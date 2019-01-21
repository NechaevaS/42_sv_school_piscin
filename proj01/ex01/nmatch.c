/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:48:56 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/20 19:55:39 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	nmatch(char *str, char *pattern)
{
	int count;

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
