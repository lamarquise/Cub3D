/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:49:39 by erlazo            #+#    #+#             */
/*   Updated: 2018/11/20 17:36:13 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char*)s1)[i] != ((const unsigned char*)s2)[i])
			return (((const unsigned char *)s1)[i] -
					((const unsigned char *)s2)[i]);
			++i;
	}
	return (0);
}
