
#include <unistd.h>

int main(int argc, char **str)
{
	int i;

	if (argc < 2)
		write(1, "\n", 1);
	i = 0;
	while (str[1][i] != '\0')
	{
		write(1, &(str[1][i]), 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
