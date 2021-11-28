/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:57:42 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/28 00:53:16 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

static long	getlen_pointer(unsigned long long n)
{
	long	len;

	len = 1;
	
	while (n / 16)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void putans_pointer(unsigned long long n)
{
	if (n / 16)
		putans_pointer(n / 16);
	if (n % 16 <= 9)
		ft_putchar('0' + n % 16);
	else
	{
		ft_putchar('a' + n % 16 - 10);
	}
	return ;
}

int ft_putnbr_pointer(unsigned long long n)
{
	long len;

	write(1, "0x", 2);
	len = getlen_pointer(n);
	putans_pointer(n);
	return (len + 2);
}
