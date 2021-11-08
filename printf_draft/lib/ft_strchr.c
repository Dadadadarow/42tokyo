/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:14 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/09 00:34:35 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strchr(char *dst, const char fmt)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(dst);
	while (i < len)
	{
		if (dst[i] == fmt)
			return (i);
		i += 1;
	}
	return (-1);
}
// int main(void)
// {
// 	char fmt;
// 	int ret;

// 	fmt = '%';
// 	ret = ft_strchr("diuxXcsp%", fmt);
// 	printf("%d\n", ret);
// 	return (0);
// }
