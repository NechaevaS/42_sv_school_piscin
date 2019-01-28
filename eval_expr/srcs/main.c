#include <stdio.h>
#include "eval_expr.h"

int main(int argc, char** argv)
{
//	char *str;

	if (argc > 1)
	{
#if 0		
		str = argv[1];
		printf("'%s'\n", str);
		skipws(&str);
		printf("'%s'\n", str);
		printf("'%d'\n",getnum(&str));
		printf("'%s'\n", str);
		t_stack *stk = create_stack();
		push_stack(stk, 1);
		push_stack(stk, 3);
		push_stack(stk, 5);
		push_stack(stk, 7);
		printf("TOP: %d\n", top_stack(stk));
		apply_all(stk, print_int);
		printf("\n");
		pop_stack(stk);
		pop_stack(stk);
		printf("TOP: %d\n", top_stack(stk));
		apply_all(stk, print_int);

		printf("\n");
		delete_stack(stk);
#endif
		printf("%d\n", eval_expr(argv[1]));

	}
}
