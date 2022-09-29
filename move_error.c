/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:14:21 by suhovhan          #+#    #+#             */
/*   Updated: 2022/09/28 18:14:23 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_error_left(t_data *arg)
{
	if (arg->map->matrix[arg->pos->x][arg->pos->y - 1] == '1')
		return (0);
	else if (arg->map->matrix[arg->pos->x][arg->pos->y - 1] == 'K')
	{
		ft_printf("GAME OVER!\n");
		free_and_exit(arg);
	}
	if (!have_coin(arg))
		if (arg->map->matrix[arg->pos->x][arg->pos->y - 1] == 'E')
			return (0);
	return (1);
}

int	move_error_right(t_data *arg)
{
	if (arg->map->matrix[arg->pos->x][arg->pos->y + 1] == '1')
		return (0);
	else if (arg->map->matrix[arg->pos->x][arg->pos->y + 1] == 'K')
	{
		ft_printf("GAME OVER!\n");
		free_and_exit(arg);
	}
	if (!have_coin(arg))
		if (arg->map->matrix[arg->pos->x][arg->pos->y + 1] == 'E')
			return (0);
	return (1);
}

int	move_error_up(t_data *arg)
{
	if (arg->map->matrix[arg->pos->x - 1][arg->pos->y] == '1')
		return (0);
	else if (arg->map->matrix[arg->pos->x - 1][arg->pos->y] == 'K')
	{
		ft_printf("GAME OVER!\n");
		free_and_exit(arg);
	}
	if (!have_coin(arg))
		if (arg->map->matrix[arg->pos->x - 1][arg->pos->y] == 'E')
			return (0);
	return (1);
}

int	move_error_down(t_data *arg)
{
	if (arg->map->matrix[arg->pos->x + 1][arg->pos->y] == '1')
		return (0);
	else if (arg->map->matrix[arg->pos->x + 1][arg->pos->y] == 'K')
	{
		ft_printf("GAME OVER!\n");
		free_and_exit(arg);
	}
	if (!have_coin(arg))
		if (arg->map->matrix[arg->pos->x + 1][arg->pos->y] == 'E')
			return (0);
	return (1);
}

int	move_error(int key_kode, t_data *arg)
{
	if (key_kode == A || key_kode == LEFT)
		if (!move_error_left(arg))
			return (0);
	if (key_kode == D || key_kode == RIGHT)
		if (!move_error_right(arg))
			return (0);
	if (key_kode == W || key_kode == UP)
		if (!move_error_up(arg))
			return (0);
	if (key_kode == S || key_kode == DOWN)
		if (!move_error_down(arg))
			return (0);
	return (1);
}
