#include<stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int main()
{
	int i;
	int *ptr;
	int min;
	int max;
	int n;

	min = 3;
	max = 11;
	n = ft_ultimate_range(&ptr, min, max);

	i = 0;
	while (i < n)
	{
		printf("PTR[%d] = %d\n", i, ptr[i]);
		i++;
	}

	n = ft_ultimate_range(&ptr, 5, 2);
	printf("%d %p\n", n, ptr);
	
	n = ft_ultimate_range(&ptr, 5, 5);
	printf("%d %p\n", n, ptr);
	return (0);
}
