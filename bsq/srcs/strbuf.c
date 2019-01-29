#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "bsq.h"

#define BSIZE 1

void strncopy(char* dst, char *src, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

t_strbuf *strbuf_create(int size, int inc)
{
	t_strbuf *p;

	p = (t_strbuf *) malloc(sizeof(t_strbuf));

	p->data = (char *) malloc(size);
	p->size = size;
	p->pos = 0;
	p->inc = inc;
	return (p);
}

void strbuf_delete(t_strbuf *buf)
{
	free(buf->data);
	free(buf);
}

void strbuf_extend(t_strbuf *buf, int inc)
{
	char	*p;
	int	new_size;

	new_size = buf->size + inc;
	p = (char *) malloc(new_size);
	strncopy(p, buf->data, buf->pos);
	buf->size = new_size;
	free(buf->data);
	buf->data = p;
}

int strbuf_full(t_strbuf *buf)
{
	return buf->size == buf->pos;
}


void strbuf_addch(t_strbuf *buf, char c)
{
	if (strbuf_full(buf))
		strbuf_extend(buf, BSIZE);
	buf->data[buf->pos++] = c;
	//printf("%d %c\n", buf->pos, c);
}

char	*strbuf_getstr(t_strbuf *buf)
{
	char *p;

	p = (char *) malloc(buf->pos + 1);
	strncopy(p, buf->data, buf->pos);
	p[buf->pos] = '\0';
	return (p);
}
