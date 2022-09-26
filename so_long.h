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
# include "get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

# ifndef SIZE
#  define SIZE 50
# endif

# ifndef KEY_KODE
#	define A 0
#	define D 2
#	define S 1
#	define W 13
#	define ESC 53
#	define LEFT 123
#	define RIGHT 124
#	define UP 126
#	define DOWN 125
# endif

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}				t_vars;

typedef struct s_img
{
	void	*xpm_1;
	void	*xpm_0;
	void	*xpm_pd;
	void	*xpm_pa;
	void	*xpm_ps;
	void	*xpm_pw;
	void	*xpm_c;
	void	*xpm_e;
	void	*xpm_k;
	void	*i_0;
	void	*i_1;
	void	*p_w;
	void	*p_a;
	void	*p_s;
	void	*p_d;
	void	*i_c;
	void	*i_k;
	void	*i_e;
}				t_img;

typedef struct s_map
{
	int		width;
	int		height;
	char	**matrix;
}				t_map;

typedef struct s_pos
{
	int	p_x;
	int	p_y;
}				t_pos;

int	input_params_error(char *filename);
int	check_params(int ac, char **av);
int	check_first_last_row(char *str);
int	check_middle_row(char *str);
int	check_map_wall(t_map map);
int	check_count_person(t_map map);
int	check_map(t_map map);
int	free_and_exit(t_map map);
t_map	map_size(int fd);
t_map	get_map(int ac, char **av);

// int	move_error_left(t_vars vars, t_map map, t_pos pos);
// int	move_error_right(t_vars vars, t_map map, t_pos pos);
// int	move_error_up(t_vars vars, t_map map, t_pos pos);
// int	move_error_down(t_vars vars, t_map map, t_pos pos);
// int	move_error(int	key_kode, t_vars vars, t_map map, t_pos pos);

#endif
