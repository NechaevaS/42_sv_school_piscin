#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	char *str;
	char new;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	str = argv[1];
	while(str[i] != '\0')
	{
		if (str[i] >= 'a'&& str[i] <= 'z')
		{
			new = ('a' + ((str[i] - 'a') + 13)%26);
			write(1, &new, 1);
		}
		else if (str[i] >= 'A'&& str[i] <= 'Z')
		{
			new = ('A' + ((str[i] - 'A') + 13)%26);
			write(1, &new, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
