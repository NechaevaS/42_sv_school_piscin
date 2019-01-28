#include "eval_expr.h"
#include <stdio.h>
//#define DEBUG 1

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
#ifdef DEBUG
	printf("before ----------------\n");
	apply_all(ops, print_char);
	printf("\n");
	apply_all(opnd, print_int);
	printf("\n");
#endif
	if (is_empty(ops) && stack_size(opnd) == 1)
		return 0;

	if (stack_size(opnd) < 2 || top_stack(ops) == '(')
		return 0;

	op = top_stack(ops);
	pop_stack(ops);

	y = top_stack(opnd);
	pop_stack(opnd);

	x = top_stack(opnd);
	pop_stack(opnd);

	r = eval(op, x, y);
	push_stack(opnd, r);
#ifdef DEBUG
	printf("after ----------------\n");
	apply_all(ops, print_char);
	printf("\n");
	apply_all(opnd, print_int);
	printf("\n");
#endif
	return 1;
}

void collapse(t_stack *ops, t_stack *opnd)
{
	int op;
//	printf("Collapse\n");	
	op = top_stack(ops);
	//while(!is_empty(ops) && priority(op) == priority(top_stack(ops)))
	while(priority(op) == priority(top_stack(ops)) && collapse_one(ops, opnd));

}

void collapse_braces(t_stack *ops, t_stack *opnd) 
{
//	printf("Braces\n");
//if (top_stack(ops) != '(')
//		return;

	while(top_stack(ops) != '(')
	{
		collapse(ops, opnd);
	}
	pop_stack(ops);
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
	//	printf("str: '%s'\n", str);
		
		skipws(&str);
		
		if (*str == '\0')
			break;
		if ((last_op != 0 && last_op != ')') && (*str == '+' || *str == '-'))
		{
			num = getnum(&str);
			push_stack(opnd, num);
			last_op = 0;
			// printf("PUSH %d\n", num);
		}
		else if (is_operation(*str))
		{
			if (is_empty(ops))
			{
				push_stack(ops, *str);
			}	
			else if (priority(*str) > priority(top_stack(ops)))
			{
				push_stack(ops, *str);
			}
			else if (*str == ')')
			{
				collapse_braces(ops, opnd);
			}
			else
			{
				//printf("looop\n");
				collapse(ops, opnd);
				push_stack(ops, *str);
			}
			last_op = *str;
			str = str + 1;
		}
		else
		{
			num = getnum(&str);
			push_stack(opnd, num);
			last_op = 0;
		}
	}
	//printf("end\n");
	while(!is_empty(ops)) {
		collapse(ops, opnd);
	}
	res = top_stack(opnd);
	return (res);
}
