# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/26 21:52:25 by pheilbro          #+#    #+#              #
#    Updated: 2019/01/27 18:10:05 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

FLAGS = -Wall -Werror -Wextra

all:
	gcc -I inc $(FLAGS) -o $(NAME) src/*.c

clean:
	rm -f src/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

test00:
	gcc -I inc $(FLAGS) -o rush-00 test/main.c src/print.c test/rush00.c

test01:
	gcc -I inc $(FLAGS) -o rush-01 test/main.c src/print.c test/rush01.c

test02:
	gcc -I inc $(FLAGS) -o rush-02 test/main.c src/print.c test/rush02.c

test03:
	gcc -I inc $(FLAGS) -o rush-03 test/main.c src/print.c test/rush03.c

test04:
	gcc -I inc $(FLAGS) -o rush-04 test/main.c src/print.c test/rush04.c

test_all: test00 test01 test02 test03 test04

test_clean:
	rm -f rush-00 rush-01 rush-02 rush-03 rush-04
