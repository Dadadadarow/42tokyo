/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:52:59 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/04 00:14:19 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_flags
{
	int flag[5];
	int field;
	int acc;
	int modifier;
	int specifier;
	int size;
}				t_flags;

int ft_printf(const char *fmt, ...);
void proc_per(const char **start, const char **fmt, int *size, va_list *ap);

# endif