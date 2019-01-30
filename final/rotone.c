/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:20:04 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/29 16:44:57 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	char *str;
	char ind;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	str = argv[1];
	ind = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			ind = ('a' + ((str[i] - 'a' + 1) % 26));
			write(1, &ind, 1);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			ind = ('A' + ((str[i] - 'A' + 1) % 26));
			write(1, &ind, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
/nfs/2019/s/snechaev/work/github2/rush02 }
