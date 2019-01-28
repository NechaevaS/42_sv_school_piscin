#include "eval_expr.h"
#include <stdlib.h>
#include <stdio.h>

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

void apply_all(t_stack *stk, void (*f)(int))
{
	int i;

	i = 0;
	while (i <= stk->top_i)
	{
		f(stk->arr[i]);
		i++;
	}
}
				
void print_int(int i)
{

		printf(" %d", i);
}

void print_char(int i)
{

		printf(" %c", i);
}
