#define TRUE 1
#define FALSE 0

int is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int i;
	int t;
	int res;
	int neg;

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
		if (res > 214748364)
		{
			if(neg == -1 && t >= 8)
				return -2147483648;
			else if (neg == 1 && t >= 7)
				return 2147483647;
		}
		res = res * 10 + t;
		i++;
	}
	return (res * neg);
}
