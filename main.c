#include "so_long.h"

int	main(int argc, char *argv[])
{
    t_data data;

    if (argc != 2)
        exit_error(0, &data);
    game_start(&data);
    generate_map(argv[1], &data);
    check_map(&data);
    generate_game(&data);
    get_assets(&data);
	render_game(&data);
    mlx_hook(data.win, 2, 2L << 0, move, &data);
    mlx_loop(data.mlx);
    return (0);
}