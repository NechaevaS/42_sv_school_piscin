#include <stdio.h>

//#define NULL 0

char *find(char *str, char ch) {
	char* p;
	
	p = str;
	while(*p != '\0' && *p != ch)
	{
		p++;
	}

	if (*p == '\0')
		return NULL;
	
	return p;
}

char next_after_skipped(char *str, char ch) {
	char *p;
	p = str;
	while(*p != '\0' && *p == ch)
	{
		p++;
	}

	return *p;
}

int match(char* str, char* pattern) {
	printf("str = %s, pattern = %s\n", str, pattern);
	if(*pattern == '*')
	{
		char* s = str;
		int count = 0;
		while(*s != '\0')
		{
			count += match(s, pattern + 1);
			s++;
		}
		return count;
	}
	else if (*pattern == *str) 
	{
		if (*pattern == '\0')
			return 1;
		return match(str + 1, pattern + 1);
	}
	return (0);
}
