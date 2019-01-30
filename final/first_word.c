/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 10:40:52 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/29 14:16:35 by snechaev         ###   ########.fr       */
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
	int j;
	char *str;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	str = argv[1];
	j = 0;

	while (str[j] != '\0')
	{
		if (is_space(str[j]))
			j++;
		else
			break;
	}
	while ((str[j] != '\0') && (!is_space(str[j])))
	{
			write(1, &str[j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
