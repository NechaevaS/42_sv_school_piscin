
#include <unistd.h>

int	main(int argc, char **str)
{
	int i;

	if (argc != 2)
		{
		write (1, "a\n", 2);
		return (1);
		}
	i = 0;
	while (str[1][i] != '\0')
	{
		if (str[1][i] == 'a')
		{
			write (1, "a\n", 2);
			return (0);
		}
		i++;
	}
	write (1, "\n", 1);
	return (1);
}
