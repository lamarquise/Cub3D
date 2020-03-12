/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:03:45 by erlazo            #+#    #+#             */
/*   Updated: 2019/11/13 15:51:50 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	a;

	if (!dst && !src)
		return (NULL);
	a = 0;
	while (a < n)
	{
		((unsigned char*)dst)[a] = ((unsigned char*)src)[a];
		++a;
	}
	return (dst);
}
