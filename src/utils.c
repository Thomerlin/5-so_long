/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:02:54 by tyago-ri          #+#    #+#             */
/*   Updated: 2021/11/17 15:02:55 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_mapvar(t_map *map, char **map_var)
{
	int	i;

	i = 0;
	while (i < map->count_line)
		free(map_var[i++]);
	free(map_var);
}

int	print_string(char *string)
{
	int	i;
	int	counter;

	i = 0;
	counter = -1;
	while (string[i] != '\0')
		i++;
	while (++counter < i)
		write(1, &string[counter], 1);
	return (0);
}
