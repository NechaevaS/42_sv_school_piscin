#include <stdio.h>
#include "bsq.h"
int point_in_rectangle(t_rectangle *rectangle, t_point *point)
{
	if(point->x < rectangle->left_upper.x)
		return (FALSE);
	if(point->x > rectangle->right_bottom.x)
		return (FALSE);
	if(point->y < rectangle->left_upper.y)
		return (FALSE);
	if(point->y > rectangle->right_bottom.y)
		return (FALSE);
	return (TRUE);
}

int square_size(t_rectangle *square)
{
	return square->right_bottom.x - square->left_upper.x;
}

void copy_rectangle(t_rectangle *dst, t_rectangle *src)
{
	dst->left_upper.x = src->left_upper.x;
	dst->left_upper.y = src->left_upper.y;
	dst->right_bottom.x = src->right_bottom.x;
	dst->right_bottom.y = src->right_bottom.y;
}

int rectangle_min_size(t_rectangle *rectangle)
{
	int size_x;
	int size_y;

	size_x = rectangle->right_bottom.x - rectangle->left_upper.x;
	size_y = rectangle->right_bottom.y - rectangle->left_upper.y;

	if (size_x < size_y)
		return size_x;
	return size_y;
}

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

int update_max_square(t_rectangle *max, t_rectangle *cand)
{
	if (square_size(max) < square_size(cand))
	{
		copy_rectangle(max, cand);
		return (TRUE);
	}
	
	if (square_size(max) == square_size(cand))
	{
		if (max->left_upper.y > cand->left_upper.y)
		{
			copy_rectangle(max, cand);
			return (TRUE);
		}
		if (max->left_upper.y == cand->left_upper.y)
			if (max->left_upper.x > cand->left_upper.x)
			{
				copy_rectangle(max, cand);
				return (TRUE);
			}
	}
	return (FALSE);
}

void rectangle_section(t_rectangle *new, t_rectangle *base, char kind, t_point *point)
{
	copy_rectangle(new, base);
	if(kind == 'L')
		new->right_bottom.x = point->x - 1;
	else if (kind == 'R')
		new->left_upper.x = point->x + 1;
	else if (kind == 'U')
		new->right_bottom.y = point->y - 1;
	else if (kind == 'D')
		new->left_upper.y = point->y + 1;
}

void square_from_rectangle(t_rectangle *square, t_rectangle *rectangle)
{
	int min_size;

	min_size = rectangle_min_size(rectangle);
	copy_rectangle(square, rectangle);
	square->right_bottom.x = square->left_upper.x + min_size;
	square->right_bottom.y = square->left_upper.y + min_size;
}

int solve_recursive(t_map *map, t_rectangle *work, t_rectangle *max_square)
{
	t_plist *p;
	t_rectangle new_work;
	t_rectangle new_square;
	int has_obstacles;
	int solution_found;

	if (rectangle_min_size(work) < square_size(max_square))
		return (FALSE);
	if (rectangle_min_size(work) < 0)
		return (FALSE);

	has_obstacles = FALSE;
	solution_found = (FALSE);
	p = map->obs_points;
	while(p)
	{
		if (point_in_rectangle(work, &(p->point)))
		{
			rectangle_section(&new_work, work, 'L', &(p->point));
			solution_found |= solve_recursive(map, &new_work, max_square);
			rectangle_section(&new_work, work, 'R', &(p->point));
			solution_found |= solve_recursive(map, &new_work, max_square);
			rectangle_section(&new_work, work, 'U', &(p->point));
			solution_found |= solve_recursive(map, &new_work, max_square);
			rectangle_section(&new_work, work, 'D', &(p->point));
			solution_found |= solve_recursive(map, &new_work, max_square);
			has_obstacles = TRUE;
		}
		p = p->next;
	}

	if (has_obstacles)
		return (solution_found);

	square_from_rectangle(&new_square, work);
	update_max_square(max_square, &new_square);
#if 0
	printf("MAX: %d, %d, %d, %d\n", 
			max_square->left_upper.x, 
			max_square->left_upper.y, 
			max_square->right_bottom.x,
			max_square->right_bottom.y);
#endif
	return (TRUE);
}

void fill_the_square(t_map *map, t_rectangle *square)
{
	int i;
	int j;

	j = square->left_upper.y;
	while(j <= square->right_bottom.y)
	{
		i = square->left_upper.x;
		while(i <= square->right_bottom.x)
		{
			map->map[j][i] = map->full;
			i++;
		}
		j++;
	}
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
//			printf("X = %d, Y = %d, SZ = %d\n", i, j, curr_size);
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
#if 0
	printf("SOLVE\n");
	t_rectangle work;
	t_rectangle max_square;

	work.left_upper.x = 0;
	work.left_upper.y = 0;
	work.right_bottom.x = map->ncols - 1;
	work.right_bottom.y = map->nrows - 1;

	max_square.left_upper.x = -1;
	max_square.left_upper.y = -1;
	max_square.right_bottom.x = -1;
	max_square.right_bottom.y = -1;

	if (solve_recursive(map, &work, &max_square))
	{
		printf("BEFORE FILL\n");
		fill_the_square(map, &max_square);
		return (TRUE);
	}
	printf("SOLVE DONE\n");
	return (FALSE);
#else
	return (solve_iterative(map));
#endif
}
