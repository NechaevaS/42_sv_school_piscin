/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   af_first_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:58:40 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/28 15:31:51 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	char *str;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (1);
	}
	str = argv[argc - 1];
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
