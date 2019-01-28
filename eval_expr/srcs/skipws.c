void skipws(char **p)
{
	char *pp;
	int i;
	
	i = 0;
	pp = p[0];
	while (pp[i] != '\0')
	{
		if (pp[i] != ' ' && pp[i] != '\t')
		{
			break;
		}
		i++;
	}
	p[0] = &(pp[i]);
}
