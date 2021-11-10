/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:59:25 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/09 01:17:42 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_init_flags(t_flags *f, int size)
{
	// Bonus Part
	// f->flag[0] = 0;
	// f->flag[1] = 0;
	// f->flag[2] = 0;
	// f->flag[3] = 0;
	// f->flag[4] = 0;
	// f->width = -1;
	// f->accuracy = -1;
	// f->modifier = -1;
	if (size < 0)
		f->putnum = 0;
	else
		f->putnum = size;
	f->putlen = 0;
	f->specifier = -1;
}

void ft_proc_per(const char **start, const char **fmt, int *size, va_list *ap)
{
	int		num;
	t_flags	flags;

	(*fmt)++;
	ft_init_flags(&flags, *size);
	// Bonus Part
	// while (ft_strchr_n("#0- +", **fmt) >= 0)
	// {
	// 	num = ft_strchr_n("#0-+ ", **fmt);
	// 	flags.flag[num] = 1;
	// 	(*fmt)++;
	// }
	// flags.width = ft_substr(fmt, ap, 0, &flags);
	// if (**fmt == '.')
	// {
	// 	(*fmt)++;
	// 	flags.accuracy = ft_substr(fmt, ap, 1, &flags);
	// }
	// nullを読まないようにする
	flags.specifier = ft_strchr("diuxXcsp%", **fmt);
	num = ft_do_print(start, fmt, ap, &flags);
	if (*size == 0 || num >= 0)
		*size = num;
}

void ft_print_str(const char **start, const char **fmt, int *size)
{
	while (**fmt != '%' && *fmt)
		(*fmt)++;
	write(1, *start, *fmt-*start);
	*size += *fmt - *start;
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int size;
	const char *start;
	
	size = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		size = -1;
	while (*fmt && size >= 0)
	{
		start = fmt;
		if (*start != '%')
			ft_print_str(&start, &fmt, &size);
		else
			return (0);
			ft_proc_per(&start, &fmt, &size, &ap);	
	}
	va_end(ap);
	return (size);
}

int main(void)
{
	ft_printf("This is test. %", 1);
	return (0);
}