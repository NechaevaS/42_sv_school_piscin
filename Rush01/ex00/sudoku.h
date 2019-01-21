/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:35:05 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/20 17:15:33 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# define N (9)
# define BSIZE (3)

void	fill(char board[N][N], char **argv);
void	print_board(char board[N][N]);
void	solve(char workboard[N][N], int *nsolutions, char result[N][N]);
int		check(char board[N][N], int rn, int cn);
int		find_first_dot(char board[N][N], int *row, int *col);
void	print_board(char board[N][N]);
void	copy_board(char dst[N][N], char src[N][N]);
int		check_param(int argc, char **argv);
#endif
