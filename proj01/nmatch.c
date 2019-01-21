/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:56:13 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/20 20:02:09 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	nmatch(char *str, char *pattern)
{
	if (*str == '\0' || *pattern == '\0')
	{
		if (*str == '\0')
		{
			if (*pattern == '\0')
				return (1);
			if (*pattern == '*')
				return (nmatch(str, pattern + 1));
		}
		return (0);
	}
	else if (*pattern == '*')
	{
		count = nmatch(str + 1, pattern);
		count += nmatch(str, pattern + 1);
		return (count);
	}
	else if (*pattern == *str)
	{
		return (nmatch(str + 1, pattern + 1));
	}
	return (0);
}
