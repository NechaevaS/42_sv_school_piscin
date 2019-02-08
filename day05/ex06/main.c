#include<stdio.h>

int	ft_strcmp(char *s1, char *s2);
int	main()
{
	char a[256];
	printf("%d\n", ft_strcmp("abc", "abc"));
	printf("%d\n", ft_strcmp("abcdfe", "abc"));
	printf("%d\n", ft_strcmp("abc", "abcdef"));
	printf("%d\n", ft_strcmp("afc", "fbc"));


}

