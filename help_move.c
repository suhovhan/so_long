/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:08:15 by suhovhan          #+#    #+#             */
/*   Updated: 2022/09/28 18:08:17 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_pose(t_data *arg)
{
	int	i;
	int	j;

	i = -1;
	while (++i < arg->map->height)
	{
		j = -1;
		while (++j < arg->map->width)
		{
			if (arg->map->matrix[i][j] == 'P')
			{
				arg->pos->x = i;
				arg->pos->y = j;
			}
		}
	}
	return (0);
}

int	have_coin(t_data *arg)
{
	int	i;
	int	j;

	i = -1;
	while (++i < arg->map->height)
	{
		j = -1;
		while (++j < arg->map->width)
			if (arg->map->matrix[i][j] == 'C')
				return (0);
	}
	return (1);
}

void	pchar(char ch)
{
	write(1, &ch, 1);
}

void	put_nbr(int nbr)
{
	if (nbr > 9)
		put_nbr(nbr / 10);
	nbr %= 10;
	pchar(nbr + '0');
}

int	close_game(t_data *arg)
{
	int	i;

	i = -1;
	ft_printf("GAME CLOSED!\n");
	while (arg->map->matrix[++i])
		free(arg->map->matrix[i]);
	free(arg->map->matrix);
	exit(0);
	return (0);
}
