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

#define UP 13
#define DOWN 1
#define LEFT 0
#define RIGHT 2

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
    int     row;
    int     col;
}   t_player;

typedef struct s_colex
{
    void    *img;
    int     count;
}   t_colex;

typedef struct s_exit
{
    void    *img;
    int     count;
}   t_exit;

typedef struct s_data
{
    void	    *mlx;
	void	    *win;
    t_map       map;
	t_player    player;
    t_colex     collec;
    t_exit      exit;
    void        *floor_img;
	void		*wall_img;
}   t_data;

void    game_start(t_data *data);
void	generate_map(char *file, t_data *data);
void    check_map(t_data *data);
void    generate_game(t_data *data);
void	get_assets(t_data *data);
void	render_game(t_data *data);
int	    move(int key, t_data *data);
void	exit_error(int error,t_data *data);


#endif