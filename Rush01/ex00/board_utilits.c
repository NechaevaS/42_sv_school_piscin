/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utilits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:33:03 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/20 14:56:28 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

void	copy_board(char dst[N][N], char src[N][N])
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

void	fill(char board[N][N], char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			board[i][j] = argv[i + 1][j];
			j++;
		}
		i++;
	}
}

void	print_board(char board[N][N])
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			write(1, &(board[i][j]), 1);
			if (j != (N - 1))
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
