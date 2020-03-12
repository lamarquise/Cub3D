/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:50:17 by erlazo            #+#    #+#             */
/*   Updated: 2018/11/19 18:06:27 by erlazo           ###   ########.fr       */
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
	return (0);
}
