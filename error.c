/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:12:00 by suhovhan          #+#    #+#             */
/*   Updated: 2022/09/21 23:12:02 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_params_error(char *filename)
{
	char	*map_type;
	int		filename_len;
	int		i;

	i = 0;
	map_type = ".ber";
	filename_len = ft_strlen(filename) - 4;
	while (filename[filename_len])
	{
		if (filename[filename_len++] != map_type[i++])
		{
			ft_printf("invalid map name\n");
			return (0);
		}
	}
	if (open(filename, O_RDONLY) == -1)
	{
		ft_printf("invalid map\n");
		return (0);
	}
	return (1);
}

int	check_params(int ac, char **av)
{
	char	*filename;

	filename = av[1];
	if (ac != 2)
	{
		ft_printf("Invalid count of arguments\n");
		return (0);
	}
	else
	{
		if (!input_params_error(filename))
			return (0);
	}
	return (1);
}

int	check_first_last_row(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_middle_row(char *str)
{
	int	i;

	i = 0;
	if ((str[0] != '1') && (str[ft_strlen(str) - 1] != '1'))
		return (0);
	return (1);
}

int	check_map_wall(char **matrix)
{
	int	i;

	i = 0;
	if (!check_first_last_row(matrix[i]))
		return (0);
	i++;
	while (matrix[i])
	{
		if (!check_middle_row(matrix[i]))
			return (0);
		if (!matrix[i + 1])
			if (!check_first_last_row(matrix[i]))
				return (0);
		i++;
	}
	return (0);
}
