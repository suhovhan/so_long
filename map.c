/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:11:51 by suhovhan          #+#    #+#             */
/*   Updated: 2022/09/21 23:11:53 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_count_person(char **matrix)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while (matrix[i][j])
	{
		if (matrix[i][j] == 'P' && p == 1)
			return (0);
		if (matrix[i][j] == 'P')
			p++;
		if (matrix[i][j + 1] == '\n')
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (1);
}

int	check_map(char **matrix)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	if (!check_map_wall(matrix) || !check_count_person(matrix))
		return (0);
	while (matrix[i][j])
	{
		c = matrix[i][j];
		if ((c != '0') && (c != '1') && (c != 'C') && (c != 'P') && (c != 'E'))
			return (0);
		if (matrix[i][j + 1] == '\n')
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (1);
}

t_map	map_size(int fd)
{
	t_map	size;
	char	*line;

	line = get_next_line(fd);
	size.height = 0;
	size.width = ft_strlen(line) - 1;
	while (line)
	{
		size.height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (size);
}

char	**get_map(int ac, char **av)
{
	int		i;
	int		fd;
	char	**matrix;
	t_map	size;

	if (!check_params(ac, av))
		exit(0);
	i = 0;
	fd = open(av[1], O_RDONLY);
	size = map_size(open(av[1], O_RDONLY));
	ft_printf("%d\n%d\n", size.height, size.width);
	matrix = (char **)malloc(sizeof(char) * size.height);
	while (i <= size.height)
	{
		matrix[i] = (char *)malloc(sizeof(char) * size.width);
		matrix[i] = get_next_line(fd);
		ft_printf("%s", matrix[i]);
		i++;
	}
	close(fd);
	if (!check_map(matrix))
	{
		ft_printf("Invalid map");
		exit(0);
	}
	return (matrix);
}
