/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:42:48 by suhovhan          #+#    #+#             */
/*   Updated: 2022/05/27 02:42:50 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int i)
{
	int	len;

	len = 0;
	if (i < 0)
	{
		len += ft_print_char('-');
		i = -i;
	}
	if (i == -2147483648)
	{
		len += ft_print_char('2');
		i = 147483648;
	}
	if (i < 10)
		len += ft_print_char(i + '0');
	else
	{
		len += ft_print_nbr(i / 10);
		len += ft_print_nbr(i % 10);
	}
	return (len);
}
