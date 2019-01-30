/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:51:50 by pheilbro          #+#    #+#             */
/*   Updated: 2019/01/27 13:11:19 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	rush00(int x, int y, int x_i, int y_i)
{
	if ((x_i == (x - 1) && y_i == 0) || (x_i == 0 && y_i == (y - 1)))
		return ('o');
	else if (x_i == 0 && y_i == 0)
		return ('o');
	else if (x_i == (x - 1) && y_i == (y - 1))
		return ('o');
	else if (y_i == 0 || y_i == (y - 1))
		return ('-');
	else if (x_i == 0 || x_i == (x - 1))
		return ('|');
	return (' ');
}

char	rush01(int x, int y, int x_i, int y_i)
{
	if (x_i == 0 && y_i == 0)
		return ('/');
	else if (x_i == 0 && y_i == (y - 1))
		return ('\\');
	else if (x_i == (x - 1) && y_i == 0)
		return ('\\');
	else if (x_i == (x - 1) && y_i == (y - 1))
		return ('/');
	else if (x_i == 0 || x_i == (x - 1) || y_i == 0 || y_i == (y - 1))
		return ('*');
	return (' ');
}

char	rush02(int x, int y, int x_i, int y_i)
{
	if (x_i == 0 && y_i == 0)
		return ('A');
	else if (x_i == 0 && y_i == (y - 1))
		return ('C');
	else if (x_i == (x - 1) && y_i == 0)
		return ('A');
	else if (x_i == (x - 1) && y_i == (y - 1))
		return ('C');
	else if (x_i == 0 || x_i == (x - 1) || y_i == 0 || y_i == (y - 1))
		return ('B');
	return (' ');
}

char	rush03(int x, int y, int x_i, int y_i)
{
	if (x_i == 0 && y_i == 0)
		return ('A');
	else if (x_i == 0 && y_i == (y - 1))
		return ('A');
	else if (x_i == (x - 1) && y_i == 0)
		return ('C');
	else if (x_i == (x - 1) && y_i == (y - 1))
		return ('C');
	else if (x_i == 0 || x_i == (x - 1) || y_i == 0 || y_i == (y - 1))
		return ('B');
	return (' ');
}

char	rush04(int x, int y, int x_i, int y_i)
{
	if (x_i == 0 && y_i == 0)
		return ('A');
	else if (x_i == 0 && y_i == (y - 1))
		return ('C');
	else if (x_i == (x - 1) && y_i == 0)
		return ('C');
	else if (x_i == (x - 1) && y_i == (y - 1))
		return ('A');
	else if (x_i == 0 || x_i == (x - 1) || y_i == 0 || y_i == (y - 1))
		return ('B');
	return (' ');
}
