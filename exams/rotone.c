#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	char c;


	i = 0;
	while (argv[1][i] != '\0')
	{
		c = argv[1][i];
		if (c >= 'a' && c <= 'z' || c  >= 'A' && c <= 'Z')
		{
			c++;
			write(1, &c, 1);
		}
		else
			write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
