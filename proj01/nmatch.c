int nmatch(char* str, char* pattern) {
	if (*str == '\0' || *pattern == '\0')
	{
		if (*str == '\0')
		{
			if (*pattern == '\0')
				return 1;
			if (*pattern == '*')
				return nmatch(str, pattern+1);
		}
		return 0;
	}
	else if(*pattern == '*')
	{
		int count = nmatch(str + 1, pattern);
		count += nmatch(str, pattern+1);
		return count;
	}
	else if (*pattern == *str) 
	{
		return nmatch(str + 1, pattern + 1);
	}
	return (0);
}
