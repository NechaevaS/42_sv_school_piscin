/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:21:31 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/29 15:19:08 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int str_len(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	int i;
	char *str;

	str = argv[1];
	i = str_len(str) - 1;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	write(1, "\n", 1);
	return (0);
}
