/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:20:56 by mazhari           #+#    #+#             */
/*   Updated: 2021/12/28 14:13:01 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_player(t_data *data, int i, int j)
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

static void	put_exit(t_data *data, int i, int j)
{
	if (data->collec.count)
		mlx_put_image_to_window(data->mlx, data->win, data->exit.img_c,
			j * HEIGHT, i * WIDTH);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->exit.img_n_c,
			j * HEIGHT, i * WIDTH);
}

static void	check_render(t_data *data, int i, int j)
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
	if (data->map.array[i][j] == 'X')
		mlx_put_image_to_window(data->mlx, data->win, data->enemy_img,
			j * HEIGHT, i * WIDTH);
}

static void	print_moves(t_data *data, int nb)
{
	char	*moves;

	moves = ft_itoa(nb);
	mlx_string_put(data->mlx, data->win, WIDTH - 30, 0, GREEN, "Moves : ");
	mlx_string_put(data->mlx, data->win, WIDTH + 50, 0, BLUE, moves);
	free(moves);
}

void	render_game(t_data *data)
{
	int	i;
	int	j;

	print_moves(data, data->move);
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
	print_moves(data, data->move);
}
