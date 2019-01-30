#include <stdio.h>
#include "bsq.h"

int main()
{
	t_strbuf *buf = strbuf_create(1, 1);
	printf("'%s'\n", strbuf_getstr(buf));
	strbuf_addch(buf, '1');
	printf("'%s'\n", strbuf_getstr(buf));
	strbuf_addch(buf, '2');
	printf("'%s'\n", strbuf_getstr(buf));
	strbuf_addch(buf, '3');
	printf("'%s'\n", strbuf_getstr(buf));

	t_map map;
	map_init(&map);
	read_map(0, &map);
	print_map(&map);
	print_obs_points(&map);
	return (0);
}
