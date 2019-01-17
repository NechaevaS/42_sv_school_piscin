#include<stdio.h>

int	*ft_range(int min, int max);

int main()
{
	int i;
	int *ptr;
	int min;
	int max;

	min = 3;
	max = 11;
	ptr = ft_range(min, max);

	i = 0;
	while (i < max - min)
	{
		printf("PTR[%d] = %d\n", i, ptr[i]);
		i++;
	}
	printf("%p\n", ft_range(5, 2));
	printf("%p\n", ft_range(2, 2));
	return (0);
}
