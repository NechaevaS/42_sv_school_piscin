/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 10:40:52 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/29 12:58:09 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int main(int argc, char **argv)
{
	int i;
	int j;
	char *str;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	str = argv[1];
	i = 0;
	j = -1;
	while (str[i] != '\0')
	{
		if ((i == 0 || is_space(str[i])) && (!is_space(str[i + 1]) && str[i + 1] != '\0'))
				j = i;
		i++;
	}
	if (j < 0)
	{
		write (1, "\n", 1);
		return (1);
	}
	j = j + 1;
	while ((str[j] != '\0') && !is_space(str[j]))
	{
		write(1, &str[j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
