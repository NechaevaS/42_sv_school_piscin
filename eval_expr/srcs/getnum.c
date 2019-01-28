int is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int getnum(char **p)
{
	char *str;
	int i;
	int t;
	int res;
	int neg;

	str = *p;
	neg = 1;
	i = 0;

	while (is_space(str[i]))
		i++;
	
	if (str[i] == '+')
		i++;
	else if (str[i] =='-')
	{
		neg = -1;
		i++;
	}
	
	res = 0;
	while (is_digit(str[i]))
	{
		t = str[i] - '0';
		res = res * 10 + t;
		i++;
	}
	*p = str + i;
	return (res * neg);
}
