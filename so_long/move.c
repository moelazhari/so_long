/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:20:38 by mazhari           #+#    #+#             */
/*   Updated: 2021/12/27 16:42:04 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_data *data, int *count)
{
	int	prow;
	int	pcol;

	prow = data->player.row;
	pcol = data->player.col;
	if (data->map.array[prow][pcol + 1] == 'E')
	{
		if (data->collec.count == 0)
			exit_error(5, data);
		return ;
	}
	data->player.pos = 1;
	*count = 1;
	data->map.array[prow][pcol] = '0';
	pcol += 1;
	if (data->map.array[prow][pcol] == 'C')
	{
		data->map.array[prow][pcol] = '0';
		data->collec.count -= 1;
	}
	data->map.array[prow][pcol] = 'P';
}

void	move_left(t_data *data, int *count)
{
	int	prow;
	int	pcol;

	prow = data->player.row;
	pcol = data->player.col;
	if (data->map.array[prow][pcol - 1] == 'E')
	{
		if (data->collec.count == 0)
			exit_error(5, data);
		return ;
	}
	data->player.pos = 0;
	*count = 1;
	data->map.array[prow][pcol] = '0';
	pcol -= 1;
	if (data->map.array[prow][pcol] == 'C')
	{
		data->map.array[prow][pcol] = '0';
		data->collec.count -= 1;
	}
	data->map.array [prow][pcol] = 'P';
}

void	move_down(t_data *data, int *count)
{
	int	prow;
	int	pcol;

	prow = data->player.row;
	pcol = data->player.col;
	if (data->map.array[prow + 1][pcol] == 'E')
	{
		if (data->collec.count == 0)
			exit_error(5, data);
		return ;
	}
	*count = 1;
	data->map.array[prow][pcol] = '0';
	prow += 1;
	if (data->map.array[prow][pcol] == 'C')
	{
		data->map.array[prow][pcol] = '0';
		data->collec.count -= 1;
	}
	data->map.array [prow][pcol] = 'P';
}

void	move_up(t_data *data, int *count)
{
	int	prow;
	int	pcol;

	prow = data->player.row;
	pcol = data->player.col;
	if (data->map.array[prow - 1][pcol] == 'E')
	{
		if (data->collec.count == 0)
			exit_error(5, data);
		return ;
	}
	*count = 1;
	data->map.array[prow][pcol] = '0';
	prow -= 1;
	if (data->map.array[prow][pcol] == 'C')
	{
		data->map.array[prow][pcol] = '0';
		data->collec.count -= 1;
	}
	data->map.array [prow][pcol] = 'P';
}

int	move(int key, t_data *data)
{
	static int	i = 1;
	int			count;
	int			prow;
	int			pcol;

	count = 0;
	prow = data->player.row;
	pcol = data->player.col;
	if (key == RIGHT && data->map.array[prow][pcol + 1] != '1')
		move_right(data, &count);
	if (key == LEFT && data->map.array[prow][pcol - 1] != '1')
		move_left(data, &count);
	if (key == DOWN && data->map.array[prow + 1][pcol] != '1')
		move_down(data, &count);
	if (key == UP && data->map.array[prow - 1][pcol] != '1')
		move_up(data, &count);
	if (key == ESC)
		exit_error(6, data);
	if (count)
		printf("Moves: [%d]\n", i++);
	render_game(data);
	return (1);
}
