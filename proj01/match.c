#include <stdio.h>

int match(char* str, char* pattern) {
	if (*str == '\0' || *pattern == '\0')
	{
		if (*str == '\0')
		{
			if (*pattern == '\0')
				return 1;
			if (*pattern == '*')
				return match(str, pattern+1);
		}
		return 0;
	}
	else if(*pattern == '*')
	{
		if (match(str + 1, pattern))
			return 1;
		if (match(str, pattern+1))
			return 1;
		return 0;
	}
	else if (*pattern == *str) 
	{
		return match(str + 1, pattern + 1);
	}
	return (0);
}
