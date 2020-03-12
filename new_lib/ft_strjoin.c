/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:13:52 by erlazo            #+#    #+#             */
/*   Updated: 2019/11/15 17:50:04 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	char	*ret;

	a = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(char)
				* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
	{
		ret[a++] = *s1;
		++s1;
	}
	while (*s2)
	{
		ret[a++] = *s2;
		++s2;
	}
	ret[a] = '\0';
	return (ret);
}
