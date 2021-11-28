/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:52:59 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/28 10:47:38 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../lib/libft.h"
#include <stdio.h> //kese

typedef struct	s_flags
{
	int flag[5];
	int width;
	int accuracy;
	int modifier;
	int specifier;
	int putsize;
}				t_flags;

int ft_printf(const char *fmt, ...);
void ft_print_str(const char **start, const char **fmt, int *size);
void ft_proc_per(const char **start, const char **fmt, int *size, va_list *ap);
void ft_init_flags(t_flags *f);
int ft_do_print(const char **start, const char **fmt, va_list *ap, t_flags *flags);
int ft_emp_specifier(const char **start, const char **fmt, t_flags *flags);
void ft_percent_print(t_flags *flags);
void ft_uint_print(va_list *ap, t_flags *flags);
void ft_int_print(va_list *ap, t_flags *flags);
void ft_pointer_print(va_list *ap, t_flags *flags);
void ft_char_print(va_list *ap, t_flags *flags);
void ft_string_print(va_list *ap, t_flags *flags);

# endif
