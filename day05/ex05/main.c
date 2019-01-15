#include<stdio.h>

char	*ft_strstr(char *str, char *to_find);
int	main()
{
	char a[256];
	printf("%s\n", ft_strstr("+++++abcdefabc-----", "abc"));
	printf("%s\n", ft_strstr("+++++abcdefabc-----", "def"));
	printf("%s\n", ft_strstr("+++++abcdefabc-----", "+++"));
	printf("%s\n", ft_strstr("+++++abcdefabc-----", "-----"));
	printf("%d\n", ft_strstr("+++++abcdefabc-----", "ace") == 0);
	

}

