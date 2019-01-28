#include "eval_expr.h"

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
		collapse(ops, opnd);

	pop_stack(ops);
}

