#ifndef BSQ_H
#define BSQ_H

#define TRUE 1
#define FALSE 0

typedef struct
{
	int x;
	int y;
} t_point;

typedef struct s_plist
{
	t_point 	point;
	struct s_plist	*next;
} t_plist;

typedef struct
{
	int left;
	int down;
} t_free;

typedef struct
{
	int     nrows;
	int     ncols;
	char    empty;
	char    obstacle;
	char    full;
	char    **map;
	t_free  **free_map;
	t_plist *obs_points;
} t_map;

typedef struct
{

	char    *data;
	int     pos;
	int     size;
	int	inc;

} t_strbuf;

typedef struct
{
	t_point left_upper;
	t_point right_bottom;
} t_rectangle;


t_strbuf	*strbuf_create(int size, int inc);
void		strbuf_delete(t_strbuf *buf);
void		strbuf_extend(t_strbuf *buf, int inc);
int		strbuf_full(t_strbuf *buf);
void		strbuf_addch(t_strbuf *buf, char c);
char		*strbuf_getstr(t_strbuf *buf);

void		map_init(t_map *map);
void		map_clean(t_map *map);
void		map_reset(t_map *map);
int 		read_map(int fd, t_map *map);
void 		print_map(t_map *map);
void		print_point(t_point *point);
void		print_obs_points(t_map *map);


void		list_insert(t_plist **list, int x, int y);
void		list_delete(t_plist **list);
int		read_data(int fd, t_plist** list);

int		solve(t_map *map);
#endif
