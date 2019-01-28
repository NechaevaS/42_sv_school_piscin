#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H
# define STACK_SIZE 2048

typedef struct s_struct
	{
		int	arr[STACK_SIZE];
		int top_i;
	}	t_stack;
	void	skipws(char **p);
	int	getnum(char **p);
	t_stack	*create_stack();
	void	delete_stack(t_stack *stk);
	void	push_stack(t_stack *stk, int i);
	int	top_stack(t_stack *stk);
	void	pop_stack(t_stack *stk);
	void	apply_all(t_stack *stk, void (*f)(int));
	int	is_empty(t_stack *stk);
	int	eval_expr(char *str);
	void print_int(int i);
	void print_char(int i);
#endif
