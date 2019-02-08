#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;
	char *s1;
	char *s2;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	s1 = argv[1];
	s2 = argv[2];
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		while (s2[j] != '\0')
		{
			if (s2[j] == s1[i])
			{
				break;
			}
			j++;
		}
		if (s2[j] == '\0')
		{
			break;
		}
		i++;
	}
	if (s1[i] == '\0')
	{
		i = 0;
		while (s1[i] != '\0')
		{
			write(1, &s1[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
