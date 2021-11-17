/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:31:36 by tyago-ri          #+#    #+#             */
/*   Updated: 2021/11/16 19:54:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>

# include "./src/utils/minilibx-linux/mlx.h"
# include "./src/utils/gnl/get_next_line.h"

typedef struct s_game
{
	int		qnt_collect;
	int		pos_col;
	int		pos_line;
	int		qnt_move;
	char	up;
	char	down;
	char	left;
	char	right;
}			t_game;

typedef struct s_program
{
	int		start;
	int		x;
	int		y;
	t_game	game;
}			t_program;

typedef struct s_map
{
	void		*mlx;
	void		*window;
	void		*image;
	int			valid_map;
	int			count_line;
	int			count_col;
	int			count_arq;
	double		count_arq2;
	double		count_col2;
	char		**map_all;
	t_game		*game;
	t_program	*program;
}				t_map;

int		check_map_valid(t_map *map, int argc, char **argv);
int		init_game(t_map *map);
int		print_string(char *string);
int		check_extension(char *str, char *extension);
char	**check_number_map(t_map *map, char *argv);
int		print_map(t_map *map);
int		print_sprite(t_map *map, int col, int line, char *path);
int		move_up(t_map *map);
int		move_down(t_map *map);
int		move_left(t_map *map);
int		move_right(t_map *map);
void	nothing_move(t_map *map);
void	free_map(t_map *map);
int		end_game(void *test);
void	free_mapvar(t_map *map, char **map_var);
void	print_steps(t_map *map);
int		map_utils(int fd1);
int		display_info(t_map *map);

size_t	ft_strlcopy(char *dst, const char *src, size_t n);
char	*ft_itoa(int n);
void	*ft_calloc(size_t nmem, size_t size);
char	*ft_memset(void *str, int c, size_t n);

#endif