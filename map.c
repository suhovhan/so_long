/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:13:54 by suhovhan          #+#    #+#             */
/*   Updated: 2022/09/28 18:13:56 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_and_exit(t_data *arg)
{
	int	i;

	i = -1;
	while (arg->map->matrix[++i])
		free(arg->map->matrix[i]);
	free(arg->map->matrix);
	exit(0);
	return (0);
}

int	check_count_person(t_data *arg)
{
	int		i;
	int		j;
	char	p;
	char	e;

	i = -1;
	p = 0;
	e = 0;
	while (arg->map->matrix[++i])
	{
		j = -1;
		while (arg->map->matrix[i][++j])
		{
			if (arg->map->matrix[i][j] == 'P' && p == 1)
				return (0);
			else if (arg->map->matrix[i][j] == 'P' && p == 0)
				p++;
			if (arg->map->matrix[i][j] == 'E')
				e++;
		}
	}
	if (e == 0 || p == 0)
		return (0);
	return (1);
}

int	check_map(t_data *arg)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	if (!check_map_wall(arg) || !check_count_person(arg))
		return (0);
	while (arg->map->matrix[++i])
	{
		j = -1;
		while (arg->map->matrix[i][++j])
		{
			c = arg->map->matrix[i][j];
			if ((c != '0') && (c != '1') && (c != 'C') && (c != 'P') \
			&& (c != 'E') && (c != 'K') && (c != '\n'))
				return (0);
		}
	}
	return (1);
}

void	map_size(t_data *arg, int fd)
{
	char	*line;

	line = get_next_line(fd);
	arg->map->height = 0;
	arg->map->width = (int)ft_strlen(line) - 1;
	while (line)
	{
		arg->map->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	get_map(t_data *arg, int ac, char **av)
{
	int		i;
	int		fd;

	if (!check_params(ac, av))
		exit(0);
	fd = open(av[1], O_RDONLY);
	map_size(arg, open(av[1], O_RDONLY));
	arg->map->matrix = (char **)malloc(sizeof(char *) * arg->map->height + 1);
	i = -1;
	while (++i < arg->map->height)
	{
		arg->map->matrix[i] = get_next_line(fd);
	}
	arg->map->matrix[arg->map->height] = 0;
	close(fd);
	if (!check_map(arg))
	{
		ft_printf("Invalid map");
		exit(0);
	}
}
