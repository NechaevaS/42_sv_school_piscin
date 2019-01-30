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
	while(j < map->ncols)
	{
		i = 0;
		while(i < map->nrows)
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

int solve(t_map *map)
{
	return (solve_iterative(map));
}
