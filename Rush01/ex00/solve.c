/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:16:04 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/20 16:51:07 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

int		check(char board[N][N], int rn, int cn)
{
	int j;
	int i;
	int rnbox;
	int cnbox;

	j = 0;
	while (j < N)
	{
		if (j != cn &&  board[rn][cn] == board[rn][j])
			return (0);
		if (j != rn && board[rn][cn] == board[j][cn])
			return (0);
		j++;
	}
	rnbox = rn / BSIZE;
	i = rnbox * BSIZE;
	while (i < (rnbox + 1) * BSIZE)
	{
		cnbox = cn / BSIZE;
		j = cnbox * BSIZE;
		while (j < (cnbox + 1) * BSIZE)
		{
			if ((rn != i || cn != j) && board[rn][cn] == board[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		find_first_dot(char board[N][N], int *row, int *col)
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (board[i][j] == '.')
			{
				*row = i;
				*col = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	solve(char workboard[N][N], int *nsolutions, char result[N][N])
{
	int i;
	int j;
	int k;

	if (!find_first_dot(workboard, &i, &j))
	{
		(*nsolutions)++;
		if (*nsolutions > 1)
			return;

		copy_board(result, workboard);
		return;
	}

	k = 1;
	while(k <= N && *nsolutions <= 1)
	{
		workboard[i][j] = k + '0';
		if (check(workboard, i, j))
		{
			solve(workboard, nsolutions, result);
		}
		k++;
	}
	workboard[i][j] = '.';
}
