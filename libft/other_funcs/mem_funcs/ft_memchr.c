/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:38:00 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/08 23:53:00 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		if ((unsigned char)c == ((unsigned char*)s)[a])
			return (&((unsigned char*)s)[a]);
		++a;
	}
	return (NULL);
}
