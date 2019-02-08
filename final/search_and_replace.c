#include <unistd.h>

int f_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != 0)
	{
		cnt++;
	}
	return (cnt);
}

int main(int argc, char **argv)
{
	int i;
	char fc;
	char rc;
	char *str;

	if ((argc != 4) || (f_strlen(argv[2]) > 1 || f_strlen(argv[3]) > 1))
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	fc = argv[2][0];
	rc = argv[3][0];
	str = argv[1];
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (str[i] == fc)
			{
				str[i] = rc;
			write(1, &str[i], 1);
			}
			else
				write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
