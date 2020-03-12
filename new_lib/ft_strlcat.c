/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:14:58 by erlazo            #+#    #+#             */
/*   Updated: 2018/11/19 17:25:57 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= 0)
		return (src_len);
	if (dst_len < size - 1)
	{
		i = 0;
		while (i < size - 1 - dst_len && src[i])
		{
			dst[dst_len + i] = src[i];
			++i;
		}
		dst[dst_len + i] = '\0';
	}
	return ((dst_len > size) ? src_len + size : src_len + dst_len);
}
