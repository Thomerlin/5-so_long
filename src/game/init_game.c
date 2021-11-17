#include "../../so_long.h"

int		end_game(void *test);
int		key_hook(int keycode, t_map *map);

int	init_game(t_map *map)
{
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, map->count_col * 21,
			map->count_line * 21, "Vá para saida");
	print_map(map);
	mlx_key_hook(map->window, key_hook, map);
	mlx_hook(map->window, 9, 1L << 21, &print_map, map);
	mlx_hook(map->window, 33, 1L << 2, &end_game, map);
	mlx_loop(map->mlx);
	return (1);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 'w')
		move_up(map);
	if (keycode == 'a')
		move_left(map);
	if (keycode == 'd')
		move_right(map);
	if (keycode == 's')
		move_down(map);
	if (keycode == 'q')
		end_game(map);
	if (keycode == 65307)
		end_game(map);
	display_info(map);
	print_steps(map);
	return (keycode);
}

int	end_game(void *test)
{
	t_map	*map;

	map = test;
	mlx_destroy_window(map->mlx, map->window);
	mlx_destroy_display(map->mlx);
	free_map(map);
	free(map->mlx);
	exit (0);
}
