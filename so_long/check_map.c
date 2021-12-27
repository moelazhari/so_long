/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:19:46 by mazhari           #+#    #+#             */
/*   Updated: 2021/12/27 16:33:34 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_all_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_char(char c, t_data *data)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'P' && c != 'C')
		return (0);
	if (c == 'P')
		data->player.count += 1;
	if (c == 'C')
		data->collec.count += 1;
	if (c == 'E')
		data->exit.count += 1;
	return (1);
}

void	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.row)
	{
		j = 0;
		while (j < data->map.col)
		{
			if (!check_char(data->map.array[i][j], data))
				exit_error(2, data);
			j++;
		}
		if (data->map.array[i][0] != '1' || data->map.array[i][j - 1] != '1')
			exit_error(2, data);
		i++;
	}
	if (!check_all_wall(data->map.array[0])
		|| !check_all_wall(data->map.array[i - 1]))
		exit_error(2, data);
	if (data->player.count != 1 || data->collec.count < 1
		|| data->exit.count < 1)
		exit_error(2, data);
}
