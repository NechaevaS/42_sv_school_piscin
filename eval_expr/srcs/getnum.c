#include <stdlib.h>

int getnum(char **str)
{
	int res;
	char *end;

	res = strtol(*str, &end, 10);
	*str = end;
	return (res);
}
