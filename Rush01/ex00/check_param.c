/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:04:10 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/20 14:47:24 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "sudoku.h"
int check_param(int argc, char **argv)
{
	if (argc != (N + 1))
	{
		write(1, "Error\n", 6);
		return (1);
	}

	int i;

	i = 1;
	while (i < argc)
	{
		int j;
		int l;

		l = 0;
		j = 0;
		while (argv[i][j] != '\0')
		{
			l = l + 1;
			if ((argv[i][j] < '1' || argv[i][j] > '9') && (argv[i][j] != '.'))
			{
				write(1, "Error\n", 6);
				return (1);
			}
			j++;
		}
		if (l != N)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
		return (0);
}
