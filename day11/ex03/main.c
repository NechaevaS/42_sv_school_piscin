#include <stdio.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **a, char *p);
int	ft_list_size(t_list *begin_list);

int	main()
{
	t_list *test = NULL;
	
//	ft_list_push_front(&test, "aaa");
//	ft_list_push_front(&test, "bbb");
//	ft_list_push_front(&test, "ccc");
	printf("%d\n",ft_list_size(test));
}
