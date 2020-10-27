/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:50:17 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/09 22:30:36 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		a;
	char	*tmp;

	a = 0;
	tmp = (char*)s;
	while (tmp[a])
		++a;
	while (a >= 0)
	{
		if (tmp[a] == (char)c)
			return (&tmp[a]);
		--a;
	}
	return (NULL);
}
