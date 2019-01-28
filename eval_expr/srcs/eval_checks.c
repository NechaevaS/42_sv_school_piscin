#include "eval_expr.h"

int collapse_one(t_stack *ops, t_stack *opnd);
void collapse(t_stack *ops, t_stack *opnd);
void collapse_braces(t_stack *ops, t_stack *opnd); 

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

int is_operand(int last_op, int cur_ch)
{
	if ((last_op != 0 && last_op != ')') && (cur_ch == '+' || cur_ch == '-'))
		return (1);
	if (!is_operation(cur_ch))
		return (1);
	return (0);
}

