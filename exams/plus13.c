#include <unistd.h>

int	is_letter(char c)
{
	return((c >= 'a' && c <= 'z') || (c >= 'A'&& c <= 'Z'));
}

int	main(int argc, char** argv)
{
	int i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while(argv[1][i] != 0)
	{
		if (!is_letter(argv[1][i]))
			write(1, &argv[1][i], 1);
		else
		{
			argv[1][i] = (argv[1][i] + 13);
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
