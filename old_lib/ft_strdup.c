/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:47:38 by erlazo            #+#    #+#             */
/*   Updated: 2018/11/20 17:58:41 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*ret;

	if (!s1)
		return (NULL);
	a = 0;
	while (s1[a])
		++a;
	if (!(ret = ft_memalloc(sizeof(char) * (a + 1))))
		return (NULL);
	a = 0;
	while (s1[a])
	{
		ret[a] = s1[a];
		++a;
	}
	return (ret);
}
