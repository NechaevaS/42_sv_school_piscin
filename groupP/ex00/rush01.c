void	ft_putchar(char c);

void	printStr(char b, char m, char e, int n)
{
	int mcnt;
	int i;
	if(n < 1)
	{
		return;
	}
	ft_putchar(b);
	if(n == 1)
	{
		ft_putchar('\n');
		return;
	}
	mcnt = n-2;
	i = 0;
	while(i < mcnt)
	{
		ft_putchar(m);
		i = i + 1;
	}
	ft_putchar(e);
	ft_putchar('\n');
}

void	rush01(int x, int y)
{
	int mcnt;
	int i;
	if(y < 1)
	{
		return;
	}
	printStr('/','*','\\',x);
	if(y == 1)
	{
		return;
	}
	mcnt = y-2;
	i = 0;
	while(i < mcnt)
	{
		printStr('*', ' ', '*',x);
		i = i + 1;
	}
	printStr('\\', '*', '/',x);
}	
