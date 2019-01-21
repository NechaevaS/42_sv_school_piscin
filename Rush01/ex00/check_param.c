/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:04:10 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/20 16:46:39 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

int	check_param(int argc, char **argv)
{
	int j;
	int l;
	int i;

	if (argc != (N + 1))
		return (0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			l = l + 1;
			if ((argv[i][j] < '1' || argv[i][j] > '9') && (argv[i][j] != '.'))
				return (0);
			j++;
		}
		if (l != N)
			return (0);
		i++;
	}
	return (0);
}
