#include <stdio.h>

int match(char* str, char* pattern, int depth) {
	for (int i = 0; i < depth;i++) {
		printf(" ");
	}

	printf("str = %s, pattern = %s\n", str, pattern);
	if (*str == '\0' || *pattern == '\0')
	{
		if (*str == '\0')
		{
			if (*pattern == '\0')
				return 1;
			if (*pattern == '*')
				return match(str, pattern+1, depth + 1);
		}
		return 0;
	}
	else if(*pattern == '*')
	{
		int count = match(str + 1, pattern, depth + 1);
		count += match(str, pattern+1, depth + 1);
		return count;
	}
	else if (*pattern == *str) 
	{
		return match(str + 1, pattern + 1, depth + 1);
	}
	return (0);
}
