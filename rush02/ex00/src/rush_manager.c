/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:11:39 by pheilbro          #+#    #+#             */
/*   Updated: 2019/01/27 18:50:59 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	rush_help(int type, int x, int y, int *xys)
{
	if (type == 0)
		return (rush00(x, y, xys[0], xys[1]));
	else if (type == 1)
		return (rush01(x, y, xys[0], xys[1]));
	else if (type == 2)
		return (rush02(x, y, xys[0], xys[1]));
	else if (type == 3)
		return (rush03(x, y, xys[0], xys[1]));
	else if (type == 4)
		return (rush04(x, y, xys[0], xys[1]));
	return ('\0');
}

char	*rush(int type, int x, int y)
{
	int		xy[2];
	char	*ret;
	int		i;

	xy[0] = -1;
	xy[1] = -1;
	ret = malloc(sizeof(char) * ((x + 1) * y + 1));
	i = 0;
	while (++xy[1] < y && x != 0)
	{
		while (++xy[0] < x)
			ret[i++] = rush_help(type, x, y, xy);
		ret[i++] = ('\n');
		xy[0] = -1;
	}
	ret[i] = '\0';
	return (ret);
}

void	print_output(char *str)
{
	int		x;
	int		y;
	char	*type;

	x = width(str);
	y = height(str);
	type = match_corners(str, x, y);
	if (!*type)
		write(1, "aucune", 6);
	else
	{
		while (*type)
		{
			print_result(*type, x, y);
			if (*(type + 1))
				write(1, " || ", 4);
			type++;
		}
	}
}
