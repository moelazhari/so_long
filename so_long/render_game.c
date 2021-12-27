/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:20:56 by mazhari           #+#    #+#             */
/*   Updated: 2021/12/27 17:28:44 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_data *data, int i, int j)
{
	data->player.row = i;
	data->player.col = j;
	if (!data->player.pos)
		mlx_put_image_to_window(data->mlx, data->win, data->player.img_left,
			j * HEIGHT, i * WIDTH);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->player.img_right,
			j * HEIGHT, i * WIDTH);
}

void	put_exit(t_data *data, int i, int j)
{
	if (data->collec.count)
		mlx_put_image_to_window(data->mlx, data->win, data->exit.img_c,
			j * HEIGHT, i * WIDTH);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->exit.img_n_c,
			j * HEIGHT, i * WIDTH);
}

void	check_render(t_data *data, int i, int j)
{
	if (data->map.array[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall_img,
			j * HEIGHT, i * WIDTH);
	if (data->map.array[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor_img,
			j * HEIGHT, i * WIDTH);
	if (data->map.array[i][j] == 'P')
		put_player(data, i, j);
	if (data->map.array[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collec.img,
			j * HEIGHT, i * WIDTH);
	if (data->map.array[i][j] == 'E')
		put_exit(data, i, j);
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
