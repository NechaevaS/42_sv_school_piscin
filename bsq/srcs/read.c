#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"
#define BSIZE (16*1024)

int 	read_line(int fd, char  *buf, int size)
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

int read_header(int fd, t_map *map)
{
	char buf[BSIZE];
	char *p;
	
	if (read_line(fd, buf, BSIZE) == -1)
		return (FALSE);

	map->nrows = getnum(buf, &p);
	
	if (p == buf || ft_strlen(p) != 3)
		return (FALSE);

	map->empty = *(p++);
	map->obstacle = *(p++);
	map->full = *(p++);

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

int map_read_line(int fd, t_map *map, int row)
{
	char buf[BSIZE];
	
	if (read_line(fd, buf, BSIZE) == -1)
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
	while(row < map->nrows && map_read_line(fd, map, row++));

	if (row != map->nrows)
		return (FALSE);

	return (TRUE);
}

