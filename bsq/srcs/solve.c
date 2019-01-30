#include <stdio.h>
#include "bsq.h"

int find_best_for_point(t_map *map, int x, int y)
{
	int i;
	int xsize;
	int ysize;
	int size;

	if (y >= map->nrows - 1 || x >= map->ncols - 1)
		return (0);

	size = map->nrows;
	if (size < map->ncols)
		size = map->ncols;

	i = 0;	
	while(x + i < map->ncols && y + i < map->nrows)
	{
		xsize = map->free_map[y+i][x+i].left - x + 1;
		ysize = map->free_map[y+i][x+i].down - y + 1; 
		if (xsize < size)
			size = xsize;
		if (ysize < size)
			size = ysize;
		i++;
	}

	return (size);	
}

void fill_square(t_map *map, int x, int y, int sz)
{
	int i;
	int j;

	j = y;
	while(j < y+sz)
	{
		i = x;
		while(i < x + sz)
		{
			map->map[j][i] = map->full;
			i++;
		}
		j++;
	}
}

int solve_iterative(t_map *map)
{
	int i;
	int j;
	int best_x;
	int best_y;
	int best_size;
	int curr_size;

	best_size = -1;
	j = 0;
	while(j < map->nrows)
	{
		i = 0;
		while(i < map->ncols)
		{
			curr_size = find_best_for_point(map, i, j);
			if (curr_size > best_size)
			{
				best_size = curr_size;
				best_x = i;
				best_y = j;
			}
			
			i++;
		}
		j++;
	}
	if (best_size == -1)
		return (FALSE);

	fill_square(map, best_x, best_y, best_size);
	return (TRUE);
}
int solve_dynamic(t_map *map, int *bestx, int *besty)
{
	int i;
	int j;
	int left;
	int up;
	int diag;
	
	*bestx = -1;
	*besty = -1;
	j = 1;
	while(j < map->nrows)
	{
		i = 1;
		while(i < map->ncols)
		{
			if (map->sqsize[j][i] == 1)
			{	
				left = map->sqsize[j][i - 1];
				up = map->sqsize[j - 1][i];
				diag = map->sqsize[j - 1][i - 1];
				//printf("left = %d, up = %d, diag = %d\n", left, up, diag);
				if (left == 0 || up == 0 || diag == 0)
					map->sqsize[j][i] = 1;
				else
				{
					if (left < up)
						map->sqsize[j][i] = left + 1;
					else if (up < diag)
						map->sqsize[j][i] = up + 1;
					else
						map->sqsize[j][i] = diag + 1;
					if (*bestx == -1 || map->sqsize[j][i] > map->sqsize[*besty][*bestx])
					{
						*bestx = i;
						*besty = j;
					}
				}
			}
			i++;
		}
		j++;
	}

	int x =	*bestx - map->sqsize[*besty][*bestx] + 1; 
	int y =	*besty - map->sqsize[*besty][*bestx] + 1;
//	printf("%d %d %d\n", x, y, map->sqsize[*besty][*bestx]);
	fill_square(map,  x, y, map->sqsize[*besty][*bestx]);	

	return (0);
}
int solve(t_map *map)
{
#if 0
	return (solve_iterative(map));
#else
	int bestx;
	int besty;

	return (solve_dynamic(map, &bestx, &besty));
#endif
}
