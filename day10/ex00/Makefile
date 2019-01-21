
all : libft.a

libft.a : 
	gcc -Wall -Wextra -Werror -I./includes -c srcs/*.c
	ar rcu libft.a *.o
	
clean :
	rm -f *.o 

fclean : clean
	rm -f libft.a

re: fclean all

