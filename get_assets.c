#include "so_long.h"

static void	player(t_data *data)
{
	int	width;
	int	height;

	data->player.img = mlx_xpm_file_to_image(data->mlx,
			"assets/player.xpm", &width, &height);
}

static void	collect(t_data *data)
{
	int	width;
	int	height;

	data->collec.img = mlx_xpm_file_to_image(data->mlx,
			"assets/collec.xpm", &width, &height);
}

static void	wall(t_data *data)
{
	int	width;
	int	height;

	data->wall_img = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",
			&width, &height);
}

static void	floor(t_data *data)
{
	int	width;
	int	height;

	data->floor_img = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm",
	&width, &height);
}

void	get_assets(t_data *data)
{
	int	width;
	int	height;

	wall(data);
	floor(data);
	player(data);
	collect(data);
	data->exit.img = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm",
	&width, &height);
}