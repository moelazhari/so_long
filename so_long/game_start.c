/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:18:54 by mazhari           #+#    #+#             */
/*   Updated: 2021/12/28 12:59:05 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_start(t_data *data)
{	
	data->map.array = ft_calloc(1, sizeof(char *));
	if (!data->map.array)
		exit_error(4, data);
	data->map.row = 0;
	data->map.col = 0;
	data->player.img_right = NULL;
	data->player.img_left = NULL;
	data->player.count = 0;
	data->player.row = 0;
	data->player.col = 0;
	data->player.pos = 0;
	data->collec.img = NULL;
	data->collec.count = 0;
	data->exit.img_c = NULL;
	data->exit.img_n_c = NULL;
	data->exit.count = 0;
	data->mlx = NULL;
	data->win = NULL;
	data->floor_img = NULL;
	data->wall_img = NULL;
}

void	generate_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!(data->mlx))
		exit_error(6, data);
	data->win = mlx_new_window(data->mlx, HEIGHT * data->map.col, \
	WIDTH * data->map.row, "so_long");
}
