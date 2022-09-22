/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:27:14 by suhovhan          #+#    #+#             */
/*   Updated: 2022/09/15 01:27:17 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

int		input_params_error(char *filename);
int		check_params(int ac, char **av);
int		check_map_wall(char **matrix);
int		check_first_last_row(char *str);
int		check_middle_row(char *str);
char	**get_map(int ac, char **av);

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_img
{
	void	*img;
	void	*xpm;
}				t_img;

typedef struct s_map
{
	int	width;
	int	height;
}				t_map;

t_map	map_size(int fd);

#endif
