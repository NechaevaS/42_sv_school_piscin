void	ft_putchar(char c);
void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char *pn;

	if (argc == 0)
	{
	}
	pn = argv[0];
	ft_putstr(pn);
	ft_putchar('\n');
	return (0);
}



