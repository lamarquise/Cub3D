/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 21:45:28 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/09 22:18:27 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int		a;
	unsigned int		b;

	a = 0;
	b = 0;
	while (s1[a])
		++a;
	while (b < n && s2[b])
	{
		s1[a + b] = s2[b];
		++b;
	}
	s1[a + b] = '\0';
	return (s1);
}
