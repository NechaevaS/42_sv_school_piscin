/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:06:04 by pheilbro          #+#    #+#             */
/*   Updated: 2019/01/27 15:11:32 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *s1, char *s2, int s2_len)
{
	int		s1_len;
	char	*ret;
	int		i;

	s1_len = ft_strlen(s1);
	ret = malloc(sizeof(char) * (s1_len + s2_len + 1));
	i = 0;
	while (i < s1_len)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i - s1_len < s2_len)
	{
		ret[i] = s2[i - s1_len];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (!*s2 || *s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (!*s2)
		return (0);
	return (*s1 - *s2);
}
