#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

#define BSIZE (16*1024)

int 	line_read(int fd, char  *buf, int size)
{
	int		nread;
	char		ch;
	int 		i;
	
	i = 0;
	while((nread = read(fd, &ch, 1)) == 1 && ch != '\n' && i < size)
		buf[i++] = ch;
	
	if (nread == -1 || ch != '\n' || i == size)
		return (FALSE);

	buf[i++] = '\0';
	return (TRUE);
}

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

void map_reset(t_map	*map)
{
	map_clean(map);
	map_init(map);
}

int read_header(int fd, t_map *map)
{
	char buf[BSIZE];
	char *p;
	
	if (line_read(fd, buf, BSIZE) == -1)
		return (FALSE);

	map->nrows = getnum(buf, &p);
	if (p == buf)
		return (FALSE);

	if (!(*p))
		return (FALSE);
	map->empty = *(p++);

	if (!(*p))
		return (FALSE);
	map->obstacle = *(p++);
	
	if (!(*p))
		return (FALSE);
	map->full = *(p++);

	if (*p)
		return (FALSE);

	map->map = (char **) malloc(sizeof(char*) * map->nrows);
	map->sqsize = (int **) malloc(sizeof(int *) * map->nrows);

	return (TRUE);
}

int parse_line(char *str, t_map *map, int row)
{
	int i;
	
	map->map[row] = (char*) malloc(map->ncols + 1);
	map->sqsize[row] = (int *) malloc(sizeof(int) * map->ncols);

	i = 0;
	while(str[i])
	{
		if (i >= map->ncols)
			return (FALSE);

		map->map[row][i] = str[i];
		map->sqsize[row][i] = 1;

		if (str[i] == map->obstacle)
			map->sqsize[row][i] = 0;
		else if (str[i] != map->empty)
			return (FALSE);
		i++;
	}
	
	map->map[row][i] = '\0';
	return (TRUE);
}

int read_map_line(int fd, t_map *map, int row)
{
	char buf[BSIZE];
	
	if (line_read(fd, buf, BSIZE) == -1)
		return (FALSE);
	
	if (row == 0)
		map->ncols = ft_strlen(buf);
	else if (map->ncols != ft_strlen(buf))
		return (FALSE);
	return (parse_line(buf, map, row));
}

int map_read(int fd, t_map *map)
{
	int  row;
	
	if (!read_header(fd, map))
		return (FALSE);

	row = 0;
	while(row < map->nrows && read_map_line(fd, map, row++));

	if (row != map->nrows)
		return (FALSE);

	return (TRUE);
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
