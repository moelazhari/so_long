/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:20:15 by mazhari           #+#    #+#             */
/*   Updated: 2021/12/27 18:38:29 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	player_img(t_data *data)
{
	int	width;
	int	height;

	data->player.img_right = mlx_xpm_file_to_image(data->mlx,
			"assets/playerR.xpm", &width, &height);
	data->player.img_left = mlx_xpm_file_to_image(data->mlx,
			"assets/playerL.xpm", &width, &height);
}

static void	exit_img(t_data	*data)
{
	int	width;
	int	height;

	data->exit.img_c = mlx_xpm_file_to_image(data->mlx, "assets/exitC.xpm",
			&width, &height);
	data->exit.img_n_c = mlx_xpm_file_to_image(data->mlx, "assets/exitNC.xpm",
			&width, &height);
}

void	get_assets(t_data *data)
{
	int	width;
	int	height;

	player_img(data);
	exit_img(data);
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",
			&width, &height);
	data->floor_img = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm",
			&width, &height);
	data->collec.img = mlx_xpm_file_to_image(data->mlx, "assets/collec.xpm",
			&width, &height);
	data->enemy_img = mlx_xpm_file_to_image(data->mlx, "assets/enemy.xpm",
			&width, &height);
}
