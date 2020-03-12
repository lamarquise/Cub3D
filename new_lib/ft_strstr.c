/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:55:48 by erlazo            #+#    #+#             */
/*   Updated: 2018/11/20 19:55:08 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		a;
	int		b;

	a = 0;
	if (needle[a] == '\0')
		return ((char*)haystack);
	while (haystack[a])
	{
		b = 0;
		while (haystack[a + b] == needle[b])
		{
			++b;
			if (needle[b] == '\0')
				return ((char*)&haystack[a]);
		}
		++a;
	}
	return (0);
}
