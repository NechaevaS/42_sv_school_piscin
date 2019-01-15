int	compare(char *str, char * to_find)
{
	int i;
	i = 0;
	while (str[i] != '\0' && to_find[i] != '\0')
	{
		if(str[i] != to_find[i])
			return (0);
		i++;
	}
	if (to_find[i] == '\0')
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		if (compare(str + i, to_find) == 1)
			return (str+i);
		i++;
	}
	return 0;
}
