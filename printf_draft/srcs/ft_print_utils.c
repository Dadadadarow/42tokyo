/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:32 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/09 00:48:51 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// diuxXcsp%

int ft_do_print(const char **start, const char **fmt, va_list *ap, t_flags *flags)
{
	if (flags->specifier == -1)
		return (ft_emp_specifier(start, fmt, flags));
	(*fmt)++;
	if (flags->specifier == 0 || flags->specifier == 1)
		return (ft_int_print(ap, flags));
	else if (2 <= flags->specifier && flags->specifier <= 4)
		return (ft_unsigned_print(ap, flags));
	else if (flags->specifier == 5)
		return (ft_char_print(ap, flags));
	else if (flags->specifier == 6)
		return (ft_string_print(ap, flags));
	else if (flags->specifier == 7)
		return (ft_pointer_print(ap, flags));
	else
		return (ft_percent_print(flags));
}