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

void	exit_error(int error)
{
	if (error == 0)
		printf("Argument Error\n");
	if (error == 1)
		printf("File Error\n");
	if (error == 2)
		printf("Map Error\n");
	if (error == 3)
		printf("assets Error\n");
	if(error == 4)
		printf("malloc Error\n");
	exit(0);
}
