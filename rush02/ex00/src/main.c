/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 10:31:39 by pheilbro          #+#    #+#             */
/*   Updated: 2019/01/27 18:25:47 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#define BUF_SIZE 4096

int		main(void)
{
	int		read_size;
	char	buf[BUF_SIZE];
	char	*input;

	input = malloc(sizeof(char));
	input = "\0";
	while ((read_size = read(0, buf, BUF_SIZE)) > 0)
		input = ft_strcat(input, buf, read_size);
	print_output(input);
	write(1, "\n", 1);
}
