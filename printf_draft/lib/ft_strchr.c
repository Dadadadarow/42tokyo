/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:14 by dainoue           #+#    #+#             */
/*   Updated: 2021/11/27 11:50:06 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strchr(char *dst, const char fmt)
{
	size_t	len;
	size_t		i;

	i = 0;
	if (fmt == 0)
		return (-1);
	len = ft_strlen(dst);
	while (i < len)
	{
		if (dst[i] == fmt)
			return (i);
		i += 1;
	}
	return (-1);
}
