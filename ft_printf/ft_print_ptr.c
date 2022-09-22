/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:40:50 by suhovhan          #+#    #+#             */
/*   Updated: 2022/05/27 02:40:53 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_print(unsigned long long int i)
{
	int		len;
	char	*hex;

	len = 0;
	hex = "abcdef";
	if (i < 10)
		len += ft_print_char(i + '0');
	else if (i < 16)
		len += ft_print_char(hex[i - 10]);
	else
	{
		len += ft_get_print(i / 16);
		len += ft_get_print(i % 16);
	}
	return (len);
}

int	ft_print_ptr(unsigned long long int i)
{
	int	len;

	len = 0;
	if (!i)
		return (write(1, "0x0", 3));
	else
	{
		write(1, "0x", 2);
		return (ft_get_print(i) + 2);
	}
}
