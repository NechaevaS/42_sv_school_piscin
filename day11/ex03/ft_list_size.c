#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list *p;
	int count;

	p = begin_list;
	count = 0;
	while (p != 0)
	{
		p = p->next;
		count++;
	}
	return (count);
}
