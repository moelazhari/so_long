#include "so_long.h"

/*void    render(t_data *data)
{
    static int bl = 0;
    if (data->player.x == data->colex.x)
        bl = 1;
    mlx_clear_window(data->mlx, data->win);
    if(!bl)
        mlx_put_image_to_window(data->mlx, data->win, data->colex.coleximg, data->colex.x, data->colex.y);
    mlx_put_image_to_window(data->mlx, data->win, data->player.playerimg, data->player.x, data->player.y);
}

int move(int key, t_data *data)
{
    printf("key = %d\n", key);
    if (key == UP && data->player.y > 0)
        data->player.y -= 32;
    if (key == LEFT && data->player.x > 0)
        data->player.x -= 32;
    if (key == DOWN && data->player.y <  MAXHEIGHT - HEIGHT)
        data->player.y += 32;
    if (key == RIGHT && data->player.x < MAXWIDTH - WIDTH)
        data->player.x += 32;
    if(key == 53)
		mlx_destroy_window(data->mlx, data->win);
    render(data);
    return (1);
}
*/
int	main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;

    t_data data;

    if (argc != 2)
        exit_error(0);
    game_start(&data);
    generate_map(argv[1], &data);
    check_map(data);
    while(i < data.map.row)
    {
        j = 0;
        while (j < data.map.col)
        {
            printf("%c", data.map.array[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return (0);







    /*int width = 0;
    int height = 0;

    t_data	data;
    data.player.x = 0;
    data.player.y = 0;

    data.colex.x = 32*10;
    data.colex.y = 32*10;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, MAXHEIGHT, MAXWIDTH, "so_long");

    data.player.playerimg = mlx_xpm_file_to_image(data.mlx, "playerx.xpm", &width, &height);
	mlx_put_image_to_window(data.mlx, data.win, data.player.playerimg, data.player.x, data.player.y);

    data.colex.coleximg = mlx_xpm_file_to_image(data.mlx, "colex.xpm", &width, &height);
    mlx_put_image_to_window(data.mlx, data.win, data.colex.coleximg, data.colex.x, data.colex.y);
    
    mlx_key_hook(data.win, move, &data);
	mlx_loop(data.mlx);*/
}