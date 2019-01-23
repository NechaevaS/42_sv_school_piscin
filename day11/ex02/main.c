#include <stdio.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **a, char *p);
void	print_list(t_list *p)
{
	while (p != NULL)
	{
		printf("%p -> %p %s\n",p, p->next, (char*)(p->data));
		p = p->next;
	}
}

int	main()
{
	t_list *test = NULL;
	
	ft_list_push_front(&test, "aaa");
	ft_list_push_front(&test, "bbb");
	ft_list_push_front(&test, "ccc");
	print_list(test);
}
