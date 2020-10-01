/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:37:09 by erlazo            #+#    #+#             */
/*   Updated: 2019/11/21 17:01:36 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	a;

	if (!dst || !src)
		return (0);
	a = 0;
	while (dstsize > 0 && src[a] && a < dstsize - 1)
		*dst++ = src[a++];
	while (src[a])
		++a;
	if (dstsize)
		*dst = '\0';
	return (a);
}
