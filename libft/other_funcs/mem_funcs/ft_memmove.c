/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:34:49 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/09 00:03:44 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	a;

	if (!dst && !src)
		return (NULL);
	if ((int)dst - (int)src < 0)
	{
		a = -1;
		while (++a < len)
			((unsigned char*)dst)[a] = ((unsigned char*)src)[a];
	}
	else
	{
		a = len;
		while (a-- > 0)
			((unsigned char*)dst)[a] = ((unsigned char*)src)[a];
	}
	return (dst);
}
