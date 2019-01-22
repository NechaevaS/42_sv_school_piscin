
#include <unistd.h>

int main(int argc, char **str)
{
	int i;

	if (argc < 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	i = 0;
	while (str[argc - 1][i])
	{
		write(1, &(str[argc -1][i]), 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
