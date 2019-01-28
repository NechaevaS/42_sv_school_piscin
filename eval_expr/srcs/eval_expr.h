#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H
# define STACK_SIZE (16 * 1024)

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
	int 	stack_size(t_stack *stk);
	int	eval_expr(char *str);
	void	print_int(int i);
	void	print_char(int i);
	void	ft_putchar(char c);
	void	ft_putnbr(int nb);
	void	ft_putchar(char c);
	void	ft_putnbr(int nb);
	int 	collapse_one(t_stack *ops, t_stack *opnd);
	void 	collapse(t_stack *ops, t_stack *opnd);
	void 	collapse_braces(t_stack *ops, t_stack *opnd); 
	int	is_operation(char c);
	int 	priority(int op);
	int	is_operand(int last_op, int cur_ch);
	int	eval(int op, int x, int y);
#endif
