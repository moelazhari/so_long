/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:19:14 by mazhari           #+#    #+#             */
/*   Updated: 2021/12/27 16:37:34 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file(char *file, t_data *data)
{
	int		i;
	int		len;
	char	*ber;

	ber = ".ber";
	i = 3;
	len = ft_strlen(file) - 1;
	while (i >= 0)
	{
		if (file[len] != ber[i])
			exit_error(1, data);
		i--;
		len--;
	}
}

static void	checklen(char *line, int col, t_data *data)
{
	int	len;

	len = ft_strlen(line);
	if (ft_strchr(line, '\n'))
		len--;
	if (len != col)
		exit_error(2, data);
}

static void	fill_map(t_data *data, char *line)
{
	char	**map;
	size_t	i;

	i = 0;
	data->map.row = data->map.row + 1;
	map = malloc(sizeof(char *) * (data->map.row + 1));
	if (!map)
		exit_error(4, data);
	while (data->map.array[i])
	{
		map[i] = data->map.array[i];
		i++;
	}
	map[i] = line;
	map[i + 1] = NULL;
	free(data->map.array);
	data->map.array = map;
}

void	generate_map(char *file, t_data *data)
{
	int		fd;
	char	*line;

	check_file(file, data);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(1, data);
	line = get_next_line(fd);
	if (!line)
		exit_error(2, data);
	data->map.col = ft_strlen(line) - 1;
	data->map.row = 0;
	while (line)
	{
		checklen(line, data->map.col, data);
		fill_map(data, line);
		line = get_next_line(fd);
	}
	close(fd);
}
