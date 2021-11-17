/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:03:51 by tyago-ri          #+#    #+#             */
/*   Updated: 2021/11/17 15:03:52 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**check_number_map(t_map *map, char *argv);
int		check_all_map(t_map *map, char **map_var);
int		check_wall(t_map *map, char **map_var);
void	free_map(t_map *map);

int	check_extension(char *str, char *extension)
{
	int	len_str;
	int	len_ext;
	int	i;

	len_str = ft_strlen(str);
	len_ext = ft_strlen(extension);
	i = 0;
	while (len_ext > 0)
	{
		if (extension[--len_ext] == str[--len_str])
			i++;
		else
		{
			print_string("Extensão do mapa inválido\n");
			return (0);
		}
	}
	return (1);
}

char	**check_number_map(t_map *map, char *argv)
{
	char	**map_var;
	int		fd1;
	int		i;

	i = 0;
	map_var = malloc(sizeof(char *) * map->count_line);
	if (!map_var)
		return (0);
	fd1 = open(argv, O_RDONLY);
	if (!fd1)
	{
		free_mapvar(map, map_var);
		return (0);
	}
	while (get_next_line(fd1, &map_var[i++]))
		;
	if (!check_all_map(map, map_var))
		return (0);
	if (!check_wall(map, map_var))
		return (0);
	return (map_var);
}

int	check_all_map(t_map *map, char **map_var)
{
	int	line_ct;
	int	col_ct;

	line_ct = 0;
	col_ct = 0;
	while (line_ct < map->count_line - 1)
	{
		if (map_var[line_ct][col_ct] != '1' &&
		(map_var[line_ct][col_ct] != '0' &&
		(map_var[line_ct][col_ct]) != 'P') && map_var[line_ct][col_ct] != 'C' &&
		(map_var[line_ct][col_ct] != 'V' && map_var[line_ct][col_ct] != 'E'))
		{
			print_string("Mapa Inválido\n");
			free_mapvar(map, map_var);
			return (0);
		}
		if (col_ct == map->count_col - 1)
		{
			line_ct++;
			col_ct = 0;
		}
		col_ct++;
	}
	return (1);
}

int	check_wall(t_map *map, char **map_var)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (line < map->count_line)
	{
		if (map_var[line][0] != '1' || map_var[line][map->count_col - 1] != '1')
		{
			free_mapvar(map, map_var);
			return (print_string("O mapa deve possuir paredes em volta\n"));
		}
		if (map_var[0][col] != '1' || map_var[map->count_line - 1][col] != '1')
		{
			free_mapvar(map, map_var);
			return (print_string("O mapa deve possuir paredes em volta\n"));
		}
		if (col == map->count_col -1)
		{
			line++;
			col = 0;
		}
		col++;
	}
	return (1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->count_line)
		free(map->map_all[i++]);
	free(map->map_all);
}
