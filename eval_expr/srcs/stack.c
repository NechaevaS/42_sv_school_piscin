#include "eval_expr.h"
#include <stdlib.h>

t_stack	*create_stack()
{
	t_stack *stk;
	stk = (t_stack *)malloc(sizeof(t_stack));
	stk->top_i = -1;
	return (stk);
}

void	delete_stack(t_stack *stk)
{
	free(stk);
}

void	push_stack(t_stack *stk, int i)
{
	stk->top_i = stk->top_i + 1;
	stk->arr[stk->top_i] = i;
}

int	top_stack(t_stack *stk)
{
	return (stk->arr[stk->top_i]);
}

void	pop_stack(t_stack *stk)
{
	if (stk->top_i == -1)
		return ;
	stk->top_i = stk->top_i - 1;
}

int is_empty(t_stack *stk)
{
	return (stk->top_i == -1);
}

int stack_size(t_stack *stk)
{
	return stk->top_i + 1;
}
