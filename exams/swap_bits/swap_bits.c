/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:49:07 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/26 16:23:44 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char mask;
	unsigned char first;
	unsigned char sec;
	unsigned char new;

	mask = 0b11110000;
	first = octet & mask >> 4;
	mask = 0b00001111;
	sec = octet & mask << 4;
	new = first | sec;
	return (new);
}
