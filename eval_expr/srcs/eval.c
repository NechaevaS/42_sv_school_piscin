#include "eval_expr.h"

int collapse_one(t_stack *ops, t_stack *opnd);
void collapse(t_stack *ops, t_stack *opnd);
void collapse_braces(t_stack *ops, t_stack *opnd); 

int	eval(int op, int x, int y)
{
	if (op == '*')
		return (x * y);
	if (op == '/')
		return (x / y);
	if (op == '%')
		return (x % y);
	if (op == '+')
		return (x + y);
	if (op == '-')
		return (x - y);
	return (0);
}

void process_operation(t_stack *ops, t_stack *opnd, char **str)
{
	char *p;

	p = *str;
	if (is_empty(ops) || priority(*p) > priority(top_stack(ops)))
		push_stack(ops, *p);
	else if (*p == ')')
		collapse_braces(ops, opnd);
	else
	{
		collapse(ops, opnd);
		push_stack(ops, *p);
	}
	*str = p + 1;
}

int eval_str(t_stack *ops, t_stack *opnd, char *str)
{
	int last_op;
	
	last_op = -1;
	while (*str != '\0')
	{
		skipws(&str);
		if (is_operand(last_op, *str))
		{
			push_stack(opnd, getnum(&str));
			last_op = 0;
		}
		else
		{
			last_op = *str;
			process_operation(ops, opnd, &str);
		}
		skipws(&str);
	}
	
	while(!is_empty(ops))
		collapse(ops, opnd);
	
	return (top_stack(opnd));
}

int	eval_expr(char *str)
{
	int res;
	t_stack *ops;
	t_stack *opnd;

	ops = create_stack();
	opnd = create_stack();
	
	res = eval_str(ops, opnd, str);

	delete_stack(ops);
	delete_stack(opnd);

	return (res);
}
