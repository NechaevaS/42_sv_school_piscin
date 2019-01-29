NAME = bsq

SRCS = srcs/*.c

$(NAME) :
	gcc -DDEBUG -Wall -Wextra -Werror -o $(NAME) $(SRCS)

all : $(NAME)

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

