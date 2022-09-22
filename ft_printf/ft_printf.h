/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:41:43 by suhovhan          #+#    #+#             */
/*   Updated: 2022/05/27 02:41:45 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(int c);
int	ft_print_hex(unsigned int i, const char str);
int	ft_print_nbr(int i);
int	ft_print_ptr(unsigned long long int i);
int	ft_print_str(char *str);
int	ft_print_unbr(unsigned int i);

#endif
