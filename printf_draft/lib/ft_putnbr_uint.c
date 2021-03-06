/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:57:42 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/28 00:54:00 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	getlen_uint(long n, int sys)
{
	long	len;

	len = 1;
	while (n / sys)
	{
		len++;
		n /= sys;
	}
	return (len);
}

void putans_uint(long n)
{
	if (n / 10)
		putans_uint(n / 10);
	ft_putchar('0' + n % 10);
	return ;
}

void putans_hex(long n, int flag)
{
	if (n / 16)
		putans_hex(n / 16, flag);
	if (n % 16 <= 9)
		ft_putchar('0' + n % 16);
	else
		if (flag == 0)
			ft_putchar('a' + n % 16 - 10);
		else
			ft_putchar('A' + n % 16 - 10);
}

// 0:u 1:x 2:X

int ft_putnbr_uint(unsigned int n, int flag)
{
	long	len;

	n = (long)n;
	if (flag == 0)
	{
		len = getlen_uint(n, 10);
		putans_uint(n);
	}
	else
	{
		len = getlen_uint(n, 16);
		putans_hex(n, flag - 1);
	}
	return (len);
}
