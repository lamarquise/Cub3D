/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:55:48 by erlazo            #+#    #+#             */
/*   Updated: 2018/11/20 21:26:52 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		a;
	int		b;

	a = 0;
	if (needle[a] == '\0')
		return ((char*)haystack);
	while (haystack[a] && len)
	{
		b = 0;
		while (haystack[a + b] == needle[b] && len)
		{
			++b;
			if (needle[b] == '\0')
				return ((char*)&haystack[a]);
			--len;
		}
		len = len + b - 1;
		++a;
	}
	return (NULL);
}
