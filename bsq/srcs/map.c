#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

#define BSIZE (16*1024)
#define TRUE 1
#define FALSE 0

#define ISSPACE(C) (C == ' ' || C == '\t')
#define ISDIGIT(C) (C >= '0' && C <= '9')

int	getnum(char *str, char **end)
{
	int	res;
	
	*end = str;
	while(*str && ISSPACE(*str))
		str++;
	
	if (!ISDIGIT(*str))
		return 0;

	res = 0;
	while(*str && ISDIGIT(*str))
		res = res * 10 + (*(str++) - '0');

	*end = str;
	return res;
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;

	return i;
}

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
}

void map_clean(t_map *map)
{
	int i;

	i = 0;
	while(map->map != NULL && i < map->nrows)
	{	
		free(map->free_map[i]);
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
	map->free_map = (t_free **) malloc(sizeof(t_free*) * map->nrows);
	map->sqsize = (int **) malloc(sizeof(int *) * map->nrows);

	return (TRUE);
}

void print_freemap(t_map *map)
{
	int i;
	int j;
	for (j = 0; j < map->nrows; j++){
		for (i = 0; i < map->ncols; i++)
			printf(" [%2d,%2d]", map->free_map[j][i].down, map->free_map[j][i].left);
		printf("\n");
	}
}

void record_obstacle(t_map *map, int x, int y)
{
	int i;

	map->free_map[y][x].left = x;
	map->free_map[y][x].down = y;
	map->sqsize[y][x] = 0;

	i = x - 1;
	while(i >= 0)
	{
		if (map->map[y][i] == map->obstacle)
			break;
		map->free_map[y][i].left = x - 1;
		i--;
	}

	i = y - 1;
	while(i >= 0)
	{
		if (map->map[i][x] == map->obstacle)
			break;
		map->free_map[i][x].down = y - 1;
		i--;
	}
}

int parse_line(char *str, t_map *map, int row)
{
	int i;
	
	map->map[row] = (char*) malloc(map->ncols + 1);
	map->free_map[row] = (t_free*) malloc(sizeof(t_free) * map->ncols);
	map->sqsize[row] = (int *) malloc(sizeof(int) * map->ncols);

	i = 0;
	while(str[i])
	{
		if (i >= map->ncols)
			return (FALSE);

		map->map[row][i] = str[i];
		map->free_map[row][i].left = map->ncols - 1;
		map->free_map[row][i].down = map->nrows - 1;
		map->sqsize[row][i] = 1;

		if (str[i] == map->obstacle)
			record_obstacle(map, i, row);
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

int read_map(int fd, t_map *map)
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

void print_number(int num)
{
	char ch;
	if (num > 9)
		print_number(num/10);
	ch = '0' + num%10;
	write(1, &ch, 1);
}

void print_map(t_map *map)
{
	int row;

	row = 0;
	while(row < map->nrows)
	{
		write(1, map->map[row++], map->ncols);
		write(1, "\n", 1);
	}
}
