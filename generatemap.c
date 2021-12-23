/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:16:50 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/11 12:54:21 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	checklen(char *line, int col)
{
	int	len;

	len = ft_strlen(line);
	if (ft_strchr(line, '\n'))
		len--;
	if (len != col)
		return (0);
	return (1);
}

static int	fill_map(t_data *data, char *line)
{
	char	**map;
	size_t	i;

	i = 0;
	data->map.row = data->map.row + 1;
	map = malloc(sizeof(char *) * (data->map.row + 1));
	if (!map)
		exit_error(4);
	while (data->map.array[i])
	{
		map[i] = data->map.array[i];
		i++;
	}
	map[i] = line;
	map[i + 1] = NULL;
	free(data->map.array);
	data->map.array = map;
	return (0);
}

void	generate_map(char *file, t_data *data)
{
	int		fd;
	char	*line;

	if (!(ft_strnstr(file, ".ber", ft_strlen(file))))
		exit_error(1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(1);
	line = get_next_line(fd);
	if (!line)
		exit_error(2);
	data->map.col = ft_strlen(line) - 1;
	data->map.row = 0;
	while (line)
	{
		if (!checklen(line, data->map.col))
			exit_error(2);
		fill_map(data, line);
		line = get_next_line(fd);
	}
	close(fd);
}
