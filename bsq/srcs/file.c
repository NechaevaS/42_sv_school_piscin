#include <stdlib.h>
#include <unistd.h>
#include "file.h"

t_reader *reader_create(int fd)
{

	t_reader *p;
	
	p = (t_reader *) malloc(sizeof(t_reader *));
	p->fd = fd;
	p->pos = 0;
	p->nbytes = 0;
	return (p);
}

void reader_delete(t_reader *reader)
{
	free(reader);
}

char reader_getch(t_reader *reader)
{
	if (reader->pos == reader->nbytes)
	{
		reader->nbytes = read(reader->fd, reader->buf, BUF_SIZE);
		reader->pos = 0;
	}
	return reader->buf[reader->pos];
}

