
OBJFILES = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all : libft.a

%.o : src/%.c 
	gcc -Wall -Wextra -Werror -I./include -c -o $(@) $(^)

libft.a : $(OBJFILES) 
	ar rcu $(@) $(^)
	
clean :
	rm -f $(OBJFILES)

fclean : clean
	rm -f libft.a

re: clean all

