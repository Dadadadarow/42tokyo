/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:32 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/27 10:37:55 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// diuxXcsp%

void ft_int_print(va_list *ap, t_flags *flags)
{
	int	num;

	num = (int)va_arg(*ap, int);
	flags->putsize = ft_putnbr_int(num);
}

void ft_uint_print(va_list *ap, t_flags *flags)
{
	unsigned int	num;

	num = (unsigned int)va_arg(*ap, int);
	if (flags->specifier != 2)
	{
		if (flags->specifier == 3)
			write(1, "0x", 2);
		if (flags->specifier == 4)
			write(1, "0X", 2);
		flags->putsize = 2;
	}
	flags->putsize += ft_putnbr_uint(num, flags->specifier - 2);
}

void ft_percent_print(t_flags *flags)
{
	flags->putsize = 1;
	write(1, "%", 1);
}

int ft_emp_specifier(const char **start, const char **fmt, t_flags *flags)
{
	if (!**fmt)
		return (-1);
	flags->putsize = *fmt - *start;
	write(1, *start, flags->putsize);
	//%は表示せず、パーセントの後に文字があれば出力
	return (flags->putsize);
}
//                              012345678
// flags.specifier = ft_strchr("diuxXcsp%", **fmt);

int ft_do_print(const char **start, const char **fmt, va_list *ap, t_flags *flags)
{
	if (flags->specifier == -1)
		return (ft_emp_specifier(start, fmt, flags));
	(*fmt)++;
	if (flags->specifier == 0 || flags->specifier == 1)
		ft_int_print(ap, flags);
	else if (2 <= flags->specifier && flags->specifier <= 4)
		ft_uint_print(ap, flags);
	else if (flags->specifier == 5)
		ft_char_print(ap, flags);
	else if (flags->specifier == 6)
		ft_string_print(ap, flags);
	else if (flags->specifier == 7)
		ft_pointer_print(ap, flags);
	else
		ft_percent_print(flags);
	return (flags->putsize);
}
