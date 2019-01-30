#include <stdio.h>
#include "bsq.h"

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
	fill_square(map,  x, y, map->sqsize[*besty][*bestx]);	

	return (0);
}

int solve(t_map *map)
{
	int bestx;
	int besty;

	return (solve_dynamic(map, &bestx, &besty));
}
