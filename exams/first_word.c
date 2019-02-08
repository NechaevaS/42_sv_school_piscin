#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **str)
{
	int i;
	
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	while (str[1][i] != '\0')
	{	
		if (str[1][i] != ' ' && str[1][i] != '\t')
			break;
		i++;
	}
	while (str[1][i] != '\0')
	{	
		if (str[1][i] == ' ' || str[1][i] == '\t')
			break;
		write(1, &(str[1][i]), 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
