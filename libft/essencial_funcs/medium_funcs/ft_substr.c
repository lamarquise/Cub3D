/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:04:32 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/15 19:39:49 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	a;
	char			*ret;

	a = 0;
	if (!s || !(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start + a] && a < len)
		{
			ret[a] = (char)s[start + a];
			++a;
		}
	}
	ret[a] = '\0';
	return (ret);
}
