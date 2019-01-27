/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:16:09 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/26 16:33:38 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	swap_bits(unsigned char octet);

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	mask;

	i = 0;
	while (i < 8)
	{
		mask = 0b10000000 >> i;
		if (octet & mask)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i++;
	}
}

int		main()
{
	print_bits(34);
	write(1, "\n", 1);
	print_bits(swap_bits(34));
	write(1, "\n", 1);
    return (0);
}
