#include <stdio.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list);

int	main()
{
	t_list	arr[3];

	arr->next = arr + 1;
	(arr + 1)->next = arr + 2;
	(arr + 2)->next = 0;
	
	printf("%d\n", ft_list_size(arr));
	return (0);
}
