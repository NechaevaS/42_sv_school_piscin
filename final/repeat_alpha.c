/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:38:44 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/28 18:12:08 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;
	char c;
	int prnt;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	c = argv[1][0]; 
	while (c != '\0')
	{
		c = argv[1][i]; 
		if (c >= 'A' && c <= 'Z')
		{
			j = 0;
			prnt = c -'A' + 1;
			 while (j < prnt)
			 {
			 	write(1, &c, 1);
				j++;
			 }
		}
		else if (c >= 'a' && c <= 'z')
		{
			j = 0;
			prnt = c -'a' + 1;
			 while (j <  prnt)
			 {
			 	write(1, &c, 1);
				j++;
			 }
		}
		else
			write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

