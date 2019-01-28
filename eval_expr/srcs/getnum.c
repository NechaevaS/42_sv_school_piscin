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
		res = res * 10 + (str[i] - '0');
		i++;
	}
	*p = str + i;
	return (res * neg);
}
