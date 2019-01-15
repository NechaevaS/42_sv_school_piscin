#include<stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);
int	main()
{
	char a[256];
	printf("%s\n", ft_strncpy(a,"11111111111111111",200));
	printf("%s\n", a);
	printf("%s\n", ft_strncpy(a,"22222", 3));
	printf("%s\n", ft_strncpy(a,"333333", 7));
	

}

