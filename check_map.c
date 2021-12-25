
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

static int check_char(char c)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'P' && c != 'C')
		return (0);
    return (1);
}

void    check_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->map.row)
	{
		j = 0;
		while (j < data->map.col)
		{
			if (!check_char(data->map.array[i][j]))
				exit_error(2, data);
			if (data->map.array[i][j] == 'P')
				data->player.count += 1;
			if (data->map.array[i][j] == 'C')
				data->collec.count += 1;
			if (data->map.array[i][j] == 'E')
				data->exit.count	+= 1;
			j++;
		}
		if (data->map.array[i][0] != '1' || data->map.array[i][j - 1]  != '1')
			exit_error(2, data);
		i++;
	}
	if (!check_all_wall(data->map.array[0]) || !check_all_wall(data->map.array[i - 1]))
		exit_error(2, data);
	if (data->player.count != 1 || data->collec.count < 1 || data->exit.count < 1)
		exit_error(2, data);
}
