#include <stdlib.h>
#include "bsq.h"

#ifdef DEBUG
#include <stdio.h>
#endif

void list_insert(t_plist **list, int x, int y)
{
	t_plist *p;

	p = (t_plist *)malloc(sizeof(t_plist));

	p->point.x = x;
	p->point.y = y;
	p->next = *list;
	*list = p;
}

void list_delete(t_plist **list)
{
	t_plist *next;

	while(*list)
	{
		next = (*list)->next;
		free(*list);
		*list = next;
	}
}

void list_apply(t_plist *list, void (*f)(t_plist *))
{
	while(list)
	{
		f(list);
		list = list->next;
	}
}

