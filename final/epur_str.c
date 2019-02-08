#include <stdio.h>
#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int skip_space(char *str, int index)
{
	int i;

	i = index;
	while (is_space(str[i]))
	{
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	int i;
	char *str;

	i = 0;
	str = argv[1];
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = skip_space(str, i);
	while (str[i] != '\0')
	{
		if (!is_space(str[i]))
		{
			write(1, &str[i], 1);
		}
		else
		{
			i = skip_space(str, i);
			if (str[i] == '\0')
			{
				break;
			}
			else
			{
				write(1, "   ", 3);
				i--;
			}

		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
