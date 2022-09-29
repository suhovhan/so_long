/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:13:44 by suhovhan          #+#    #+#             */
/*   Updated: 2022/09/28 18:13:46 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*arg;

	arg = malloc(sizeof(t_data));
	arg->imgs = malloc(sizeof(t_img));
	arg->map = malloc(sizeof(t_map));
	arg->vars = malloc(sizeof(t_vars));
	arg->pos = malloc(sizeof(t_pos));
	get_map(arg, ac, av);
	arg->vars->mlx = mlx_init();
	arg->vars->size_x = arg->map->width * SIZE;
	arg->vars->size_y = arg->map->height * SIZE;
	arg->vars->win = mlx_new_window(arg->vars->mlx, \
	arg->vars->size_x, arg->vars->size_y, "PAC_MAN:))");
	create_imges(arg);
	put_imges(D, arg);
	mlx_hook(arg->vars->win, 2, 1l << 0, move, arg);
	mlx_hook(arg->vars->win, 17, 1l << 0, close_game, arg);
	mlx_loop(arg->vars->mlx);
	free_and_exit(arg);
	return (0);
}
