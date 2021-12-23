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

static void	image_init(t_data *data)
{
	data->player.img = NULL;
	data->win = NULL;
}

void	game_start(t_data *data)
{	
	data->map.array = ft_calloc(1, sizeof(char *));
	if (!data->map.array)
		exit_error(4);
	data->player.count = 0;
	data->collec.count = 0;
	data->exit.count = 0;
	image_init(data);
}
