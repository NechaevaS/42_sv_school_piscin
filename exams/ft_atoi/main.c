#include <stdio.h>

int	ft_atoi(const char *str);

int main(int argc, char **argv)
{
	if (argc > 2)
		return (1);
	printf("%d\n", ft_atoi(argv[1]));
	return (0);
}
