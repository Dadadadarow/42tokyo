/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:54:50 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/27 11:37:52 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_string_print(va_list *ap, t_flags *flags)
{
	char *str;

	str = (char *)va_arg(*ap, char *);
	flags->putsize = ft_strlen(str);
	ft_putstr(str);
}

void ft_char_print(va_list *ap, t_flags *flags)
{
	char c;

	c = (char)va_arg(*ap, unsigned int);
	flags->putsize = 1;
	write(1, &c, 1);
}

void ft_pointer_print(va_list *ap, t_flags *flags)
{
	unsigned int num;
	flags->specifier = 3;

	num = (unsigned long long)va_arg(*ap, void *);
	flags->putsize = ft_putnbr_pointer(num);
}
