#include "eval_expr.h"

int	is_operation(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%'|| c =='(' || c == ')');
}

int priority(int op)
{
	if (op == '*' || op == '/' || op == '%')
		return (2);
	else if (op == '+' || op == '-')
		return (1);
	return (-1);
	
}

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

void collapse(t_stack *ops, t_stack *opnd)
{
	int op;
	int x;
	int y;
	int r;

	op = top_stack(ops);
	pop_stack(ops);

	y = top_stack(opnd);
	pop_stack(opnd);

	x = top_stack(opnd);
	pop_stack(opnd);

	r = eval(op, x, y);
	push_stack(opnd, r);
}

int	eval_expr(char *str)
{
	int res;
	t_stack *ops;
	t_stack *opnd;
	int num;

	ops = create_stack();
	opnd = create_stack();
	
	while (*str != '\0')
	{
		skipws(&str);
		if (is_operation(*str))
		{
			if (is_empty(ops))
			{
				push_stack(ops, *str);
			}	
			else if (priority(*str) > priority(top_stack(ops)))
			{
				push_stack(ops, *str);
			}
			else
			{
				collapse(ops, opnd);
				push_stack(ops, *str);
			}
		}
		else
		{
			num = getnum(&str);
			push_stack(opnd, num);
		}
	}
	collapse(ops, opnd);
	res = top_stack(opnd);
	return (res);
}
