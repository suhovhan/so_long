/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:14:14 by suhovhan          #+#    #+#             */
/*   Updated: 2022/09/28 18:14:16 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_data *arg)
{
	if (have_coin(arg))
	{
		if (arg->map->matrix[arg->pos->x - 1][arg->pos->y] == 'E')
		{
			ft_printf("GAME WIN!!!!!!\n");
			free_and_exit(arg);
		}
	}
	arg->map->matrix[arg->pos->x][arg->pos->y] = '0';
	arg->map->matrix[arg->pos->x - 1][arg->pos->y] = 'P';
	return (0);
}

int	move_down(t_data *arg)
{
	if (have_coin(arg))
	{
		if (arg->map->matrix[arg->pos->x + 1][arg->pos->y] == 'E')
		{
			ft_printf("GAME WIN!!!!!!\n");
			free_and_exit(arg);
		}
	}
	arg->map->matrix[arg->pos->x][arg->pos->y] = '0';
	arg->map->matrix[arg->pos->x + 1][arg->pos->y] = 'P';
	return (0);
}

int	move_left(t_data *arg)
{
	if (have_coin(arg))
	{
		if (arg->map->matrix[arg->pos->x][arg->pos->y - 1] == 'E')
		{
			ft_printf("GAME WIN!!!!!!\n");
			free_and_exit(arg);
		}
	}
	arg->map->matrix[arg->pos->x][arg->pos->y] = '0';
	arg->map->matrix[arg->pos->x][arg->pos->y - 1] = 'P';
	return (0);
}

int	move_right(t_data *arg)
{
	if (have_coin(arg))
	{
		if (arg->map->matrix[arg->pos->x][arg->pos->y + 1] == 'E')
		{
			ft_printf("GAME WIN!!!!!!\n");
			free_and_exit(arg);
		}
	}
	arg->map->matrix[arg->pos->x][arg->pos->y] = '0';
	arg->map->matrix[arg->pos->x][arg->pos->y + 1] = 'P';
	return (0);
}

int	move(int key_kode, t_data *arg)
{
	static int	i = 0;

	get_pose(arg);
	if (!move_error(key_kode, arg))
		return (0);
	if (key_kode == ESC)
	{
		ft_printf("GAME WAS CLOSED!\n");
		free_and_exit(arg);
	}
	else if (key_kode == A || key_kode == LEFT)
		move_left(arg);
	else if (key_kode == W || key_kode == UP)
		move_up(arg);
	else if (key_kode == S || key_kode == DOWN)
		move_down(arg);
	else if (key_kode == D || key_kode == RIGHT)
		move_right(arg);
	put_nbr(++i);
	pchar('\n');
	put_imges(key_kode, arg);
	return (0);
}
