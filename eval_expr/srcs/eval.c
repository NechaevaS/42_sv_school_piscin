#include "eval_expr.h"
#include <stdio.h>

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

void collapse_one(t_stack *ops, t_stack *opnd)
{
	int op;
	int x;
	int y;
	int r;
	printf("before ----------------\n");
	apply_all(ops, print_char);
	printf("\n");
	apply_all(opnd, print_int);
	printf("\n");
	op = top_stack(ops);
	pop_stack(ops);

	y = top_stack(opnd);
	pop_stack(opnd);

	x = top_stack(opnd);
	pop_stack(opnd);

	r = eval(op, x, y);
	push_stack(opnd, r);
	printf("after ----------------\n");
	apply_all(ops, print_char);
	printf("\n");
	apply_all(opnd, print_int);
	printf("\n");
}

void collapse(t_stack *ops, t_stack *opnd)
{
	int op;
	
	op = top_stack(ops);
	//while(!is_empty(ops) && priority(op) == priority(top_stack(ops)))
	while(priority(op) == priority(top_stack(ops)))
	{
		collapse_one(ops, opnd);
	}

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
//		printf("'%s'\n", str);
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
				printf("looop\n");
				collapse(ops, opnd);
				push_stack(ops, *str);
			}
			str = str + 1;
		}
		else
		{
			num = getnum(&str);
			push_stack(opnd, num);
		}
	}
	printf("end\n");
	while(!is_empty(ops)) {
		collapse(ops, opnd);
	}
	res = top_stack(opnd);
	return (res);
}
