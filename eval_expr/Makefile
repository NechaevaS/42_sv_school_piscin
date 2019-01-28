NAME = eval_expr
SRCS = srcs

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS)/*.c

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
