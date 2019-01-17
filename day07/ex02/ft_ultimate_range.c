#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int n;
	int i;
	int *ar;
	
	range[0] = NULL;
	n = max - min;
	if (n <= 0)
		return (0);

	ar = (int *)malloc (sizeof(int) * (n));
	if (ar == NULL)
		return (0);

	i = 0;
	while (i < n)
	{
		ar[i] = min + i;
		i++;
	}
	range[0] = ar;
	return (n);
}
