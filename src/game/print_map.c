/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:03:31 by tyago-ri          #+#    #+#             */
/*   Updated: 2021/11/17 15:07:35 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int		print_sprite(t_map *map, int col, int line, char *path);
int		print_player(t_map *map, int col, int line);
void	nothing_move(t_map *map);
void	print_steps(t_map *map);

int	print_map(t_map *map)
{
	int	col;
	int	line;

	col = 0;
	line = 0;
	while (line < map->count_line)
	{
		while (col < map->count_col)
		{
			if (map->map_all[line][col] == '1')
				print_sprite(map, col, line, "./src/assets/wall.xpm");
			if (map->map_all[line][col] == 'V')
				print_sprite(map, col, line, "./src/assets/enemy.xpm");
			if (map->map_all[line][col] == 'P' || map->map_all[line][col] == 'C'
				|| map->map_all[line][col] == 'E')
				print_player(map, col, line);
			if (map->map_all[line][col] == '0')
				print_sprite(map, col, line, "./src/assets/floor.xpm");
			col++;
		}
		col = 0;
		line++;
	}
	return (1);
}

void	nothing_move(t_map *map)
{
	map->game->up = 0;
	map->game->down = 0;
	map->game->left = 0;
	map->game->right = 0;
}

int	print_sprite(t_map *map, int col, int line, char *path)
{
	map->image = mlx_xpm_file_to_image(map->mlx, path,
			&map->program->x, &map->program->y);
	mlx_put_image_to_window(map->mlx, map->window, map->image,
		col * 21, line * 21);
	mlx_destroy_image(map->mlx, map->image);
	print_steps(map);
	return (1);
}

void	print_steps(t_map *map)
{
	char	*counter;
	char	*steps;

	steps = ft_calloc(sizeof(char), 100);
	counter = ft_itoa(map->game->qnt_move);
	ft_strlcopy(steps, "Moves: ", 8);
	ft_strlcopy(&steps[ft_strlen(steps)], counter, ft_strlen(counter) + 1);
	mlx_string_put(map->mlx, map->window, (map->count_col
			* 21) / 2 - 42, 50, 0x0087CEFA, steps);
	free(counter);
	free(steps);
}

int	print_player(t_map *map, int col, int line)
{
	if (map->map_all[line][col] == 'C')
		print_sprite(map, col, line, "./src/assets/collect.xpm");
	if (map->map_all[line][col] == 'E')
		print_sprite(map, col, line, "./src/assets/exit.xpm");
	if (map->map_all[line][col] == 'P')
	{
		map->game->pos_line = line;
		map->game->pos_col = col;
		if (map->game->up == 'w')
			print_sprite(map, col, line, "./src/assets/p_back.xpm");
		else if (map->game->left == 'a')
			print_sprite(map, col, line, "./src/assets/p_left.xpm");
		else if (map->game->right == 'd')
			print_sprite(map, col, line, "./src/assets/p_right.xpm");
		else if (map->game->down == 's')
			print_sprite(map, col, line, "./src/assets/p_down.xpm");
		else
			print_sprite(map, col, line, "./src/assets/p_down.xpm");
	}
	return (1);
}
