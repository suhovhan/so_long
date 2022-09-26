#include "so_long.h"

int	free_and_exit(t_map map)
{
	int	i;

	i = -1;
	while (map.matrix[++i])
		free(map.matrix[i]);
	free(map.matrix);
	// exit(0);
	return (0);
}

int	check_count_person(t_map map)
{
	int		i;
	int		j;
	char	p;
	char	e;

	i = -1;;
	p = 0;
	e = 0;
	while (map.matrix[++i])
	{
		j = -1;
		while (map.matrix[i][++j])
		{
			if (map.matrix[i][j] == 'P' && p == 1)
				return (0);
			else if (map.matrix[i][j] == 'P' && p == 0)
				p++;
			if (map.matrix[i][j] == 'E')
				e++;
		}
	}
	if (e == 0 || p == 0)
		return (0);
	return (1);
}

int	check_map(t_map map)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	if (!check_map_wall(map) || !check_count_person(map))
		return (0);
	while (map.matrix[++i])
	{
		j = -1;
		while (map.matrix[i][++j])
		{
			c = map.matrix[i][j];
			if ((c != '0') && (c != '1') && (c != 'C') && (c != 'P') && (c != 'E') && (c != 'K') && (c != '\n'))
				return (0);
		}
	}
	return (1);
}

t_map	map_size(int fd)
{
	t_map	map;
	char	*line;

	line = get_next_line(fd);
	map.height = 0;
	map.width = ft_strlen(line) - 1;
	while (line)
	{
		map.height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}

t_map	get_map(int ac, char **av)
{
	int		i;
	int		fd;
	t_map	map;

	if (!check_params(ac, av))
		exit(0);
	i = 0;
	fd = open(av[1], O_RDONLY);
	map = map_size(open(av[1], O_RDONLY));
	map.matrix = (char **)malloc(sizeof(char) * map.height);
	while (i <= map.height)
	{
		map.matrix[i] = (char *)malloc(sizeof(char) * map.width);
		map.matrix[i] = get_next_line(fd);
		i++;
	}
	map.matrix[map.height] = 0;
	close(fd);
	if (!check_map(map))
	{
		ft_printf("Invalid map");
		exit(0);
	}
	return (map);
}