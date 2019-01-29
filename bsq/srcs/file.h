#ifndef FILE_H
#define FILE_H

#define BUF_SIZE 256
typedef struct
{
	int  fd;
	char buf[BUF_SIZE];
	int  nbytes;
	int  pos;
} t_reader;

t_reader*	reader_create(int fd);
void		reader_delete(t_reader *reader);
char		reader_getch(t_reader *reader);
int 		reader_getint(t_reader *reader);

#endif
