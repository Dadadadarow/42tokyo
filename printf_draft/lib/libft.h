/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:52:59 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/28 00:54:56 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c);
int ft_putnbr_int(int n);
int ft_putnbr_pointer(unsigned long long n);
int ft_putnbr_uint(unsigned int n, int flag);
void ft_putstr(char *str);
int ft_strchr(char *dst, const char fmt);
size_t	ft_strlen(const char *s);

# endif
