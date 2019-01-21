/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:37:30 by snechaev          #+#    #+#             */
/*   Updated: 2019/01/20 19:46:38 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	match(char *str, char *pattern);
int	nmatch(char *str, char *pattern);

int	main(int argc, char **argv)
{
	int nmatches;

	if (argc != 3)
	{
		printf("Wrong number of parameters\n");
		return (1);
	}
	if (match(argv[1], argv[2]))
		printf("Match\n");
	else
		printf("Fail\n");
	if ((nmatches = nmatch(argv[1], argv[2])))
		printf("nmatch,  nmatches(%d)\n", nmatches);
	else
		printf("Fail\n");
	return (0);
}
