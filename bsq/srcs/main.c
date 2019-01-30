#include <unistd.h>
#include <fcntl.h>
#include "bsq.h"

void print_map_error()
{
	write(2, "map error\n", 10);
}

void process_map(int fd)
{
	t_map map;

	map_init(&map);
	if (!map_read(fd, &map))
	{
		print_map_error();
		return;
	}
	solve(&map);
	map_print(&map);
	map_clean(&map);
}

int main(int argc, char **argv)
{
	int i;
	int fd;

	if (argc == 1)
	{
		process_map(0);
		return (0);
	}
	
	i = 1;
	while(i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			print_map_error();
		else
		{
			process_map(fd);
			close(fd);
		}
		i++;
	}
	return (0);
}
