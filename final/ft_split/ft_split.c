#include <stdlib.h>
#include <stdio.h>

int 	iswsps(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int 	cnt_word(char *str)
{
	int cnt;
	int i;
	
	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (!iswsps(str[i]) && (iswsps(str[i - 1]) || i == 0))
			cnt++;
		i++;
	}
	return (cnt);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**ft_split(char *str)
{
	char **arr;
	char **a;
	char *tmp;
	char *t;
	char *p;

	tmp = (char *)malloc(ft_strlen(str));
	t = tmp;
	p = str;
	while (*p)
	{
		*t = *p;
		t++;
		p++;
	}
	arr = (char **)malloc(sizeof(char **) * (cnt_word(str)+1));
	a = arr;
	t = tmp;
	while (*t)
	{
		if (!iswsps(*t) && (iswsps(*(t - 1)) || tmp == t))
		{
			*a = t;
			a++;
		}
		t++;
	}
	*a = NULL;
	while (*tmp)
	{
		if (iswsps(*tmp))
			*tmp = 0;
		tmp++;
	}
	return (arr);

}
