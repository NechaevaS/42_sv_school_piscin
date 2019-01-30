/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:35:49 by pheilbro          #+#    #+#             */
/*   Updated: 2019/01/27 15:53:25 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		width(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		height(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	*match_corners(char *str, int x, int y)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * 4);
	i = 0;
	if (str[0] == 'o' && ft_strcmp(str, rush(0, x, y)) == 0)
		ret[i++] = '0';
	else if (str[0] == '/' && ft_strcmp(str, rush(1, x, y)) == 0)
		ret[i++] = '1';
	else if (str[0] == 'A')
	{
		if (ft_strcmp(str, rush(2, x, y)) == 0)
			ret[i++] = '2';
		if (ft_strcmp(str, rush(3, x, y)) == 0)
			ret[i++] = '3';
		if (ft_strcmp(str, rush(4, x, y)) == 0)
			ret[i++] = '4';
	}
	ret[i] = 0;
	return (ret);
}
