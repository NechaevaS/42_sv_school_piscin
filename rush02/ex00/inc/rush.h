/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:33:54 by pheilbro          #+#    #+#             */
/*   Updated: 2019/01/27 18:22:01 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr(int nbr);
void	print_result(char type, int x, int y);

int		width(char *str);
int		height(char *str);
char	*match_corners(char *str, int x, int y);

int		ft_strlen(char *str);
char	*ft_strcat(char *s1, char *s2, int s2_len);
int		ft_strcmp(char *s1, char *s2);

char	rush00(int x, int y, int x_i, int y_i);
char	rush01(int x, int y, int x_i, int y_i);
char	rush02(int x, int y, int x_i, int y_i);
char	rush03(int x, int y, int x_i, int y_i);
char	rush04(int x, int y, int x_i, int y_i);

char	*rush(int type, int x, int y);
void	print_output(char *str);

#endif
