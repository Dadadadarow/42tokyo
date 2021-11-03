/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:59:25 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/04 07:05:18 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void proc_per(const char **start, const char **fmt, int *size, va_list *ap)
{
	
}

void print_str(const char **start, const char **fmt, int *size)
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
			print_str(&start, &fmt, &size);
		else
			return (0);
			proc_per(&start, &fmt, &size, &ap);	
	}
	va_end(ap);
	return (size);
}

int main(void)
{
	ft_printf("This is test. %", 1);
	return (0);
}