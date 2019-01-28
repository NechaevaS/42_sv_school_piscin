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
	else if (op == '(')
		return (3);
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

int collapse_one(t_stack *ops, t_stack *opnd)
{
	int op;
	int x;
	int y;
	int r;
	
	if (is_empty(ops) && stack_size(opnd) == 1)
		return (0);

	if (stack_size(opnd) < 2 || top_stack(ops) == '(')
		return (0);

	op = top_stack(ops);
	pop_stack(ops);

	y = top_stack(opnd);
	pop_stack(opnd);

	x = top_stack(opnd);
	pop_stack(opnd);

	r = eval(op, x, y);
	push_stack(opnd, r);
	return (1);
}

void collapse(t_stack *ops, t_stack *opnd)
{
	int op;
	
	op = top_stack(ops);
	while(priority(op) == priority(top_stack(ops)) && collapse_one(ops, opnd));
}

void collapse_braces(t_stack *ops, t_stack *opnd) 
{
	while(top_stack(ops) != '(')
	{
		collapse(ops, opnd);
	}
	pop_stack(ops);
}

int is_operand(int last_op, int cur_ch)
{
	if ((last_op != 0 && last_op != ')') && (cur_ch == '+' || cur_ch == '-'))
		return (1);
	if (!is_operation(cur_ch))
		return (1);
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

int	eval_expr(char *str)
{
	int res;
	t_stack *ops;
	t_stack *opnd;
	int num;
	int last_op;

	ops = create_stack();
	opnd = create_stack();
	
	last_op = -1;
	while (*str != '\0')
	{
		skipws(&str);
		if (is_operand(last_op, *str))
		{
			num = getnum(&str);
			push_stack(opnd, num);
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
	{
		collapse(ops, opnd);
	}
	
	res = top_stack(opnd);
	return (res);
}
