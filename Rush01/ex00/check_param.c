/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:04:10 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/20 17:30:22 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

int	check_param(int argc, char **argv)
{
	int j;
	int i;

	if (argc != (N + 1))
		return (FALSE);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] < '1' || argv[i][j] > '9') && (argv[i][j] != '.'))
				return (FALSE);
			j++;
		}
		if (j != N)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
