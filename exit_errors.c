/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:40:46 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/05 16:02:40 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.row)
	{
		if (data->map.array[i])
			free(data->map.array[i]);
		i++;
	}
	if (data->map.array)
		free(data->map.array);
}

void	exit_error(int error,t_data *data)
{
	ft_free(data);
	if (error == 0)
		printf("Argument Error\n");
	if (error == 1)
		printf("File Error\n");
	if (error == 2)
		printf("Map Error\n");
	if (error == 3)
		printf("assets Error\n");
	if (error == 4)
		printf("malloc Error\n");
	if (error == 5)
		printf("you win");
	exit(0);
}

