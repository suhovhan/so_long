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

# include <mlx.h>
# include "get_next_line.h"
# include <fcntl.h>

# ifndef SIZE
#  define SIZE 50
# endif

# ifndef KEY_KODE
#  define A 0
#  define D 2
#  define S 1
#  define W 13
#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define UP 126
#  define DOWN 125
# endif

# define IMG_0 "img/map.xpm"
# define IMG_1 "img/wall.xpm"
# define IMG_PA "img/pers_A.xpm"
# define IMG_PW "img/pers_W.xpm"
# define IMG_PS "img/pers_S.xpm"
# define IMG_PD "img/pers_D.xpm"
# define IMG_E "img/exit.xpm"
# define IMG_C "img/coin.xpm"
# define IMG_K "img/enemy.xpm"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
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
	int	x;
	int	y;
}				t_pos;

typedef struct s_data
{
	t_vars	*vars;
	t_map	*map;
	t_img	*imgs;
	t_pos	*pos;
}				t_data;

int		ft_printf(char *str);

int		input_params_error(char *filename);
int		check_params(int ac, char **av);
int		check_first_last_row(char *str);
int		check_middle_row(char *str);
int		check_map_wall(t_data *arg);
int		check_count_person(t_data *arg);
int		check_map(t_data *arg);

int		free_and_exit(t_data *arg);
int		create_imges(t_data *arg);
void	get_map(t_data *arg, int ac, char **av);
void	map_size(t_data *arg, int fd);
void	put_imges(int key_kode, t_data *arg);

int		move_error_left(t_data *arg);
int		move_error_right(t_data *arg);
int		move_error_up(t_data *arg);
int		move_error_down(t_data *arg);
int		move_error(int key_kode, t_data *arg);

int		move_up(t_data *arg);
int		move_down(t_data *arg);
int		move_left(t_data *arg);
int		move_right(t_data *arg);
int		move(int key_kode, t_data *arg);

int		get_pose(t_data *arg);
int		have_coin(t_data *arg);
void	put_nbr(int nb);
void	pchar(char ch);
int		close_game(t_data *arg);

#endif
