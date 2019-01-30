#include <unistd.h>
#include "bsq.h"

int	getnum(char *str, char **end)
{
	int	res;
	
	*end = str;
	while(*str && ISSPACE(*str))
		str++;
	
	if (!ISDIGIT(*str))
		return 0;

	res = 0;
	while(*str && ISDIGIT(*str))
		res = res * 10 + (*(str++) - '0');

	*end = str;
	return res;
}

void print_number(int num)
{
	char ch;
	if (num > 9)
		print_number(num/10);
	ch = '0' + num%10;
	write(1, &ch, 1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;

	return i;
}
