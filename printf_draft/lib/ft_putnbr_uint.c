/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:57:42 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/10 21:04:05 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

static long	getlen(long n)
{
	long	flag;
	long	len;

	flag = 0;
	len = 1;
	if (n < 0)
	{
		flag = 1;
		n = -n;
	}
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len + flag);
}

// void	ft_putnbr_fd(int n, int fd)
// {
// 	if (n < 0)
// 	{
// 		ft_putchar_fd('-', fd);
// 		ft_putnbr_fd(-n, fd);
// 	}
// 	else
// 	{
// 		if (n / 10)
// 			ft_putnbr_fd(n / 10, fd);
// 		ft_putchar_fd('0' + n % 10, fd);
// 		return ;
// 	}
// }

void putans(long n)
{
	if (n / 10)
		putans(n / 10);
	ft_putchar('0' + n % 10);
	return ;
}

int ft_putnbr_uint(unsigned int n)
{
	long	len;

	n = (long)n;
	len = getlen(n);
	putans(n);
	return (len);
}

int main(void)
{
	int len = ft_putnbr_uint(2300000000);
	printf("putnum is %d\n", len);
	return (0);
}
