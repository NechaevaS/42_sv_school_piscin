#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int n;
	int i;
	int *ar;
	
	n = max - min;
	if (n <= 0)
		return (NULL);

	ar = (int *)malloc (sizeof(int) * (n));
	if (ar == NULL)
		return (NULL);

	i = 0;
	while (i < n)
	{
		ar[i] = min + i;
		i++;
	}
	return (ar);
}
