/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:41:15 by suhovhan          #+#    #+#             */
/*   Updated: 2022/05/27 02:41:20 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unbr(unsigned int i)
{
	int	len;

	len = 0;
	if (i < 10)
		len += ft_print_char(i + '0');
	else
	{
		len += ft_print_unbr(i / 10);
		len += ft_print_unbr(i % 10);
	}
	return (len);
}
