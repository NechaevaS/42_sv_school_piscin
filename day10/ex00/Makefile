
OBJFILES = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all : libft.a

%.o : srcs/%.c 
	gcc -Wall -Wextra -Werror -I./includes -c -o $(@) $(^)

libft.a : $(OBJFILES) 
	ar rcu $(@) $(^)
	
clean :
	rm -f $(OBJFILES)

fclean : clean
	rm -f libft.a

re: fclean all

