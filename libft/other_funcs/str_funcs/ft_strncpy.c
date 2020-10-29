/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:00:28 by erlazo            #+#    #+#             */
/*   Updated: 2020/10/29 09:56:45 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int		a;

	a = 0;
	while (a < len && src[a])
	{
		dst[a] = src[a];
		++a;
	}
	while (a < len)
		dst[a++] = '\0';
	return (dst);
}
