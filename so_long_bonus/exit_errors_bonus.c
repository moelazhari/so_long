/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:18:38 by mazhari           #+#    #+#             */
/*   Updated: 2021/12/27 18:53:05 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_images(t_data *data)
{
	if (data->wall_img)
		mlx_destroy_image(data->mlx, data->wall_img);
	if (data->exit.img_c)
		mlx_destroy_image(data->mlx, data->exit.img_c);
	if (data->exit.img_n_c)
		mlx_destroy_image(data->mlx, data->exit.img_n_c);
	if (data->collec.img)
		mlx_destroy_image(data->mlx, data->collec.img);
	if (data->player.img_right)
		mlx_destroy_image(data->mlx, data->player.img_right);
	if (data->player.img_left)
		mlx_destroy_image(data->mlx, data->player.img_left);
	if (data->floor_img)
		mlx_destroy_image(data->mlx, data->floor_img);
	if (data->enemy_img)
		mlx_destroy_image(data->mlx, data->enemy_img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
}

static void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	
	while (i < data->map.row)
	{
		if(data->map.array[i])
			free(data->map.array[i]);
		i++;
	}
	if (data->map.array)
		free(data->map.array);
}

int	destroy_notify(t_data *data)
{
	exit_error(6, data);
	return (0);
}

void	exit_error(int error, t_data *data)
{
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
		printf("\n|!|!| you win |!|!|\n");
	if (error == 6)
		printf("\n|!|!| quit successfully |!|!|\n" );
	if (error == 7)
		printf("\n|!|!| game over|!|!|\n");
	ft_free(data);
	destroy_images(data);
}
