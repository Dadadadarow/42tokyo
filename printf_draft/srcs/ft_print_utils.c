/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:32 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/09 01:12:01 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// diuxXcsp%

void ft_percent_print(t_flags *flags)
{
	write(1, "%", 1);
}

int ft_do_print(const char **start, const char **fmt, va_list *ap, t_flags *flags)
{
	if (flags->specifier == -1)
		return (ft_emp_specifier(start, fmt, flags));
	(*fmt)++;
	if (flags->specifier == 0 || flags->specifier == 1)
		ft_int_print(ap, flags);
	else if (2 <= flags->specifier && flags->specifier <= 4)
		ft_unsigned_print(ap, flags);
	else if (flags->specifier == 5)
		 ft_char_print(ap, flags);
	else if (flags->specifier == 6)
		 ft_string_print(ap, flags);
	else if (flags->specifier == 7)
		 ft_pointer_print(ap, flags);
	else
		 ft_percent_print(flags);
}