# ifndef SO_LONG_H
# define SO_LONG_H


#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"


#define HEIGHT 32
#define WIDTH 32

#define MAXHEIGHT HEIGHT * 30
#define MAXWIDTH  WIDTH * 30    


#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124

#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF

typedef struct map
{
    int     col;
    int     row;
    char    **array;

}           t_map;

typedef struct s_player
{
    void    *img;
    int     count;
    int     x;
    int     y;
}   t_player;

typedef struct s_colex
{
    void    *img;
    int     count;
    int     x;
    int     y;
}   t_colex;

typedef struct s_exit
{
    void    *img;
    int     count;
    int     x;
    int     y;
}   t_exit;

typedef struct s_data
{
    void	    *mlx;
	void	    *win;
    t_map       map;
	t_player    player;
    t_colex     collec;
    t_exit      exit;
}   t_data;

void	exit_error(int error);
char	*get_next_line(int fd);
void	generate_map(char *file, t_data *data);
void    game_start(t_data *data);

#endif 