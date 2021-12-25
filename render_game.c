#include "so_long.h"

void	check_render(t_data *data, int i, int j)
{
	if (data->map.array[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall_img,
			j * HEIGHT, i * WIDTH);
	if (data->map.array[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor_img,
			j * HEIGHT, i * WIDTH);
	if (data->map.array[i][j] == 'P')
	{
		data->player.row = i;
		data->player.col = j;
		mlx_put_image_to_window(data->mlx, data->win, data->player.img,
			j * HEIGHT, i * WIDTH);
	}
	if (data->map.array[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collec.img,
			j * HEIGHT, i * WIDTH);
	if (data->map.array[i][j] == 'E')
	{
		if (!data->collec.count)
			mlx_put_image_to_window(data->mlx, data->win, data->exit.img,
				j * HEIGHT, i * WIDTH);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->wall_img,
				j * HEIGHT, i * WIDTH);
	}
}

void	render_game(t_data *data)
{
	int	i;
	int	j;

	mlx_clear_window(data->mlx, data->win);
	i = 0;
	while (i < data->map.row)
	{
		j = 0;
		while (j < data->map.col)
		{
			check_render(data, i, j);
			j++;
		}
		i++;
	}
}