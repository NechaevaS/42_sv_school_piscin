#include <stdio.h>

int match(char *str, char *pattern);

int main(int argc, char** argv) {
	int nmatches;
	if (argc != 3)
	{
		printf("Wrong number of parameters\n");
		return 1;
	}

	if ((nmatches = match(argv[1], argv[2]))) 
	{
		printf("Match,  nmatches(%d)\n", nmatches);

	}
	else 
	{
		printf("Fail\n");
	}

	return (0);
}
