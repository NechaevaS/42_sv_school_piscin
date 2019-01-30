#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

void map_init(t_map *map) {
	map->nrows = 0;
	map->ncols = 0;
	map->empty = '\0';
	map->obstacle = '\0';
	map->full = '\0';
	map->map = NULL;
	map->sqsize = NULL;
}

void map_clean(t_map *map)
{
	int i;

	i = 0;
	while(map->map != NULL && i < map->nrows)
	{	
		free(map->map[i]);
		free(map->sqsize[i]);
		i++;
	}
}

void map_print(t_map *map)
{
	int row;

	row = 0;
	while(row < map->nrows)
	{
		write(1, map->map[row++], map->ncols);
		write(1, "\n", 1);
	}
}
