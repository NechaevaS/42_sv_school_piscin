#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list *p;
	int res;

	p = begin_list;
	res = 0;
	while (p != 0)
	{
		p = p->next;
		res++;
	}
	return (res);
}
