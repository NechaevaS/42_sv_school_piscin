#include "eval_expr.h"

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int getnum(char **p)
{
	char *pp;
	int res;
	int neg;

	pp = *p;
	neg = 1;

	skipws(&pp);
	
	if (*pp == '+')
		pp++;
	else if (*pp =='-')
	{
		neg = -1;
		pp++;
	}
	
	res = 0;
	while (is_digit(*pp))
		res = res * 10 + (*pp++ - '0');

	*p = pp;
	return (res * neg);
}
