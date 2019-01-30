#include <stdio.h>
#include "bsq.h"

int main()
{
	t_map map;
	map_init(&map);
	read_map(0, &map);
	print_map(&map);
	print_obs_points(&map);

	solve(&map);
	print_map(&map);
	return (0);
}
