/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:20:24 by mazhari           #+#    #+#             */
/*   Updated: 2021/12/27 18:58:21 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		exit_error(0, &data);
	game_start(&data);
	generate_map(argv[1], &data);
	check_map(&data);
	generate_game(&data);
	get_assets(&data);
	render_game(&data);
	mlx_hook(data.win, 2, 2L << 0, move, &data);
	mlx_hook(data.win, 17, 0L, destroy_notify, &data);
	mlx_loop(data.mlx);
	return (0);
}
