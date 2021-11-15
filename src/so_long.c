/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:24:08 by tyago-ri          #+#    #+#             */
/*   Updated: 2021/11/15 15:24:47 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_struct(t_program *program, t_map *map, t_game *game);

int	main(int argc, char **argv)
{
	t_program	program;
	t_map		map;
	t_game		game;

	init_struct(&program, &map, &game);
	map.valid_map = check_map_valid(&map, argc, argv);
	if (map.valid_map > 0)
		init_game(&map);
	else
		return (0);
	return (1);
}

void	init_struct(t_program *program, t_map *map, t_game *game)
{
	game->up = 0;
	game->down = 0;
	game->left = 0;
	game->right = 0;
	map->game = game;
	map->program = program;
	map->valid_map = 0;
	map->count_line = 0;
	map->count_col = 0;
	map->count_arq = 0;
	map->game->qnt_collect = 0;
	map->game->qnt_move = 0;
	program->start = 0;
	program->x = 0;
	program->y = 0;
}
