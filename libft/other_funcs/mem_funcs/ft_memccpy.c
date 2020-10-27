/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:02:01 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/08 23:47:26 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	a;
	unsigned char	*dst2;
	unsigned char	*src2;

	a = 0;
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	while (a < n)
	{
		dst2[a] = src2[a];
		if (src2[a] == (unsigned char)c)
			return (&dst[a + 1]);
		++a;
	}
	return (NULL);
}
