/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:43:00 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/11 16:14:28 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_start(t_data *data)
{	
	data->map.array = ft_calloc(1, sizeof(char *));
	if (!data->map.array)
		exit_error(4, data);
	data->player.count = 0;
	data->player.row = 0;
	data->player.col = 0;
	data->collec.count = 0;
	data->exit.count = 0;
	data->exit.img = NULL;
	data->floor_img = NULL;
	data->player.img = NULL;
	data->wall_img = NULL;
	data->collec.img = NULL;
	data->win = NULL;
}

void	generate_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!(data->mlx))
		exit_error(6, data);
	data->win = mlx_new_window(data->mlx, HEIGHT * data->map.col, \
	WIDTH * data->map.row, "so_long");
}
