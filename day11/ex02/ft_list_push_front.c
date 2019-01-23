#include "ft_list.h"

t_list *ft_create_elem(void* data);

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new;

	new = ft_create_elem(data);
	
	new->next = begin_list[0];
	begin_list[0] = new;
}
