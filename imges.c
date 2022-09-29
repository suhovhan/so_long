/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:15:39 by suhovhan          #+#    #+#             */
/*   Updated: 2022/09/28 18:15:41 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_imges(t_data *arg)
{
	int	w;
	int	h;

	arg->imgs->xpm_1 = mlx_xpm_file_to_image(arg->vars->mlx, \
	IMG_1, &w, &h);
	arg->imgs->xpm_0 = mlx_xpm_file_to_image(arg->vars->mlx, \
	IMG_0, &w, &h);
	arg->imgs->xpm_pd = mlx_xpm_file_to_image(arg->vars->mlx, \
	IMG_PD, &w, &h);
	arg->imgs->xpm_pa = mlx_xpm_file_to_image(arg->vars->mlx, \
	IMG_PA, &w, &h);
	arg->imgs->xpm_pw = mlx_xpm_file_to_image(arg->vars->mlx, \
	IMG_PW, &w, &h);
	arg->imgs->xpm_ps = mlx_xpm_file_to_image(arg->vars->mlx, \
	IMG_PS, &w, &h);
	arg->imgs->xpm_c = mlx_xpm_file_to_image(arg->vars->mlx, \
	IMG_C, &w, &h);
	arg->imgs->xpm_e = mlx_xpm_file_to_image(arg->vars->mlx, \
	IMG_E, &w, &h);
	arg->imgs->xpm_k = mlx_xpm_file_to_image(arg->vars->mlx, \
	IMG_K, &w, &h);
	return (0);
}

void	put_map_images(t_data *arg, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(arg->vars->mlx, \
		arg->vars->win, arg->imgs->xpm_0, y, x);
	else if (c == '1')
		mlx_put_image_to_window(arg->vars->mlx, \
		arg->vars->win, arg->imgs->xpm_1, y, x);
	else if (c == 'E')
		mlx_put_image_to_window(arg->vars->mlx, \
		arg->vars->win, arg->imgs->xpm_e, y, x);
	else if (c == 'C')
		mlx_put_image_to_window(arg->vars->mlx, \
		arg->vars->win, arg->imgs->xpm_c, y, x);
	else if (c == 'K')
		mlx_put_image_to_window(arg->vars->mlx, \
		arg->vars->win, arg->imgs->xpm_k, y, x);
}

void	put_person_imges(int key_kode, t_data *arg, int x, int y)
{
	if (key_kode == D || key_kode == RIGHT)
		mlx_put_image_to_window(arg->vars->mlx, \
		arg->vars->win, arg->imgs->xpm_pd, y, x);
	else if (key_kode == A || key_kode == LEFT)
		mlx_put_image_to_window(arg->vars->mlx, \
		arg->vars->win, arg->imgs->xpm_pa, y, x);
	else if (key_kode == W || key_kode == UP)
		mlx_put_image_to_window(arg->vars->mlx, \
		arg->vars->win, arg->imgs->xpm_pw, y, x);
	else if (key_kode == S || key_kode == DOWN)
		mlx_put_image_to_window(arg->vars->mlx, \
		arg->vars->win, arg->imgs->xpm_ps, y, x);
}

void	put_imges(int key_kode, t_data *arg)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	c;

	i = -1;
	while (++i < arg->map->height)
	{
		j = -1;
		while (++j < arg->map->width)
		{
			x = i * SIZE;
			y = j * SIZE;
			c = arg->map->matrix[i][j];
			if (arg->map->matrix[i][j] != 'P')
				put_map_images(arg, c, x, y);
			else
				put_person_imges(key_kode, arg, x, y);
		}
	}
}
