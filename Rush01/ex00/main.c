#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 5)//change to 10
	{
		write(1, "Error\n", 6);
		return (1);
	}
	
	int i;

	i = 1;
	while (i < argc)
	{
		int j;
		int l;
		
		l =0;
		j = 0;
		while (argv[i][j] != '\0')
		{
			l = l + 1;
			if ((argv[i][j] < 49 || argv[i][j] > 57) && (argv[i][j] != '.'))
			{
				write(1, "Error\n", 6);
				return (1);
			}
			j++;
		}
		if (l != 4)//change to 9
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}	
	return (0);
}
