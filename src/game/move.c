/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:03:37 by tyago-ri          #+#    #+#             */
/*   Updated: 2021/11/17 15:03:38 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	move_up(t_map *map)
{
	if (map->map_all[map->game->pos_line - 1][map->game->pos_col] == '1')
		return (0);
	if (map->map_all[map->game->pos_line - 1][map->game->pos_col] == 'E' &&
		map->game->qnt_collect > 0)
		return (0);
	if (map->map_all[map->game->pos_line - 1][map->game->pos_col] == 'C')
		map->game->qnt_collect--;
	if (map->map_all[map->game->pos_line - 1][map->game->pos_col] == 'V')
	{
		print_string("Game Over\n");
		end_game(map);
	}
	if (map->map_all[map->game->pos_line - 1][map->game->pos_col] == 'E' &&
		map->game->qnt_collect == 0)
	{
		print_string("Win");
		end_game(map);
	}
	map->game->qnt_move++;
	map->map_all[map->game->pos_line][map->game->pos_col] = '0';
	map->map_all[map->game->pos_line - 1][map->game->pos_col] = 'P';
	map->game->up = 'w';
	print_map(map);
	nothing_move(map);
	return (1);
}

int	move_left(t_map *map)
{
	if (map->map_all[map->game->pos_line][map->game->pos_col - 1] == '1')
		return (0);
	if (map->map_all[map->game->pos_line][map->game->pos_col - 1] == 'E' &&
		map->game->qnt_collect > 0)
		return (0);
	if (map->map_all[map->game->pos_line][map->game->pos_col - 1] == 'C')
		map->game->qnt_collect--;
	if (map->map_all[map->game->pos_line][map->game->pos_col - 1] == 'V')
	{
		print_string("Game Over\n");
		end_game(map);
	}
	if (map->map_all[map->game->pos_line][map->game->pos_col - 1] == 'E' &&
		map->game->qnt_collect == 0)
	{
		print_string("Win");
		end_game(map);
	}
	map->game->qnt_move++;
	map->map_all[map->game->pos_line][map->game->pos_col] = '0';
	map->map_all[map->game->pos_line][map->game->pos_col - 1] = 'P';
	map->game->left = 'a';
	print_map(map);
	nothing_move(map);
	return (1);
}

int	move_right(t_map *map)
{
	if (map->map_all[map->game->pos_line][map->game->pos_col + 1] == '1')
		return (0);
	if (map->map_all[map->game->pos_line][map->game->pos_col + 1] == 'E' &&
		map->game->qnt_collect > 0)
		return (0);
	if (map->map_all[map->game->pos_line][map->game->pos_col + 1] == 'C')
		map->game->qnt_collect--;
	if (map->map_all[map->game->pos_line][map->game->pos_col + 1] == 'V')
	{
		print_string("Game Over\n");
		end_game(map);
	}
	if (map->map_all[map->game->pos_line][map->game->pos_col + 1] == 'E' &&
		map->game->qnt_collect == 0)
	{
		print_string("Win");
		end_game(map);
	}
	map->game->qnt_move++;
	map->map_all[map->game->pos_line][map->game->pos_col] = '0';
	map->map_all[map->game->pos_line][map->game->pos_col + 1] = 'P';
	map->game->right = 'd';
	print_map(map);
	nothing_move(map);
	return (1);
}

int	move_down(t_map *map)
{
	if (map->map_all[map->game->pos_line + 1][map->game->pos_col] == '1')
		return (0);
	if (map->map_all[map->game->pos_line + 1][map->game->pos_col] == 'E' &&
		map->game->qnt_collect > 0)
		return (0);
	if (map->map_all[map->game->pos_line + 1][map->game->pos_col] == 'C')
		map->game->qnt_collect--;
	if (map->map_all[map->game->pos_line + 1][map->game->pos_col] == 'V')
	{
		print_string("Game Over\n");
		end_game(map);
	}
	if (map->map_all[map->game->pos_line + 1][map->game->pos_col] == 'E' &&
		map->game->qnt_collect == 0)
	{
		print_string("WIN\n");
		end_game(map);
	}
	map->game->qnt_move++;
	map->map_all[map->game->pos_line][map->game->pos_col] = '0';
	map->map_all[map->game->pos_line + 1][map->game->pos_col] = 'P';
	map->game->down = 's';
	print_map(map);
	nothing_move(map);
	return (1);
}
