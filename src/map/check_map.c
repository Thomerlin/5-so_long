#include "../../so_long.h"

int	check_map_struct(t_map *map, char *argv);
int	counter_line(t_map *map, int fd1);
int	counter_col(t_map *map, int fd1, char *argv);
int	more_verify(char *argv);

int	check_map_valid(t_map *map, int argc, char **argv)
{
	if (argc == 1)
	{
		print_string("Nenhum argumento encontrado\n");
		return (0);
	}
	if (argc > 2)
		print_string("Seá utilizado apenas o primeiro argumento\n");
	if (!check_extension(argv[1], ".ber"))
		return (0);
	if (!check_struct(map, argv[1]))
		return (0);
	if (!more_one(argv[1]))
		return (0);
	map->map_all = check_number_map(map, argv[1]);
	if (map->map_all == 0)
		return (0);
	return (1);
}

int	check_map_struct(t_map *map, char *argv)
{
	int		fd1;
	double	res;

	fd1 = open(argv, O_RDONLY);
	if (!fd1)
		return (0);
	if (!counter_line(map, fd1))
		return (0);
	if (!counter_col(map, fd1, argv))
		return (0);
	close(fd1);
	res = map->count_arq2 / map->count_col2;
	if (res != map->count_line)
	{
		print_string("Linhas e colunas inconrretas\n");
		return (0);
	}
	else
		return (1);
}

int	counter_line(t_map *map, int fd1)
{
	int		size;
	char	buffer;

	map->count_line++;
	while (true)
	{
		size = read(fd1, &buffer, 1);
		if (buffer == '\n')
			map->count_line++;
		if (buffer != '\n' && size > 0)
		{
			map->count_arq++;
			if (buffer == 'C')
				map->game->qnt_collect++;
		}
		if (size == 0)
			break ;
	}
	if (map->count_line < 4)
		return (print_string("Mapa deve conter mais de 3 espaços"));
	map->count_arq2 = map->count_arq;
	close(fd1);
	return (1);
}

int	counter_col(t_map *map, int fd1, char *argv)
{
	int		size;
	char	buffer_c;

	fd1 = open(argv, O_RDONLY);
	while (true)
	{
		size = read(fd1, &buffer_c, 1);
		if (buffer_c == '\n')
			break ;
		if (buffer_c != '\n')
			map->count_col++;
	}
	if (map->count_col < 5)
	{
		print_string("Mapa deve conter pelo menos 5 colunas");
		return (0);
	}
	map->count_col2 = map->count_col;
	close(fd1);
	return (1);
}

int	more_verify(char *argv)
{
	int	fd1;
	int	verify;

	fd1 = open(argv, O_RDONLY);
	verify = map_utils(fd1);
	if (verify < 3)
		return (3);
	close(fd1);
	return (1);
}
