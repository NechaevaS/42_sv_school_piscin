/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:41:47 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/20 14:45:04 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

int main(int argc, char **argv)
{
	char workboard[N][N];
	char result[N][N];
	
	
	check_param(argc, argv)
	fill(workboard, argv);
	
	int nsolutions = 0;
	solve(workboard, &nsolutions, result);
	if (nsolutions == 1)
	{
		print_board(result);
		return (0);
	}

	write(1, "Error\n", 6);
	return (1);
}
