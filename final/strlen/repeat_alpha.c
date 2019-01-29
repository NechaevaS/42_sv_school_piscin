/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:38:44 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/28 17:23:36 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_letter(char c)
{
	return (c >= 'A' && c <= 'Z' || c >= 'a' && c >= 'z');
}

int main(int argc, char **argv)
{
	int i;
	int j;
	char c;
	int prnt;

	if (argc != 2)
		write(1, "\n", 1);
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (!is_letter(c))
			i++;
		if (is_letter(c) && (c >= 'A' && c <= 'Z'))
		{
			j = 0;
			prnt = c -'A' + 1;
			 while (j <= prnt)
			 {
			 	write(1, &c, 1);
				j++;
			 }
		}
		if (is_letter(c) && (c >= 'a' && c <= 'z'))
		{
			j = 0;
			prnt = c -'a' + 1;
			 while (j <= prnt)
			 {
			 	write(1, &c, 1);
				j++;
			 }
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
