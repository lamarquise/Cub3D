/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:53:21 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/19 04:45:51 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrdup(char *str)
{
	char	*ret;
	int		a;

	if (!str)
		return (NULL);
	a = 0;
	while (str[a])
		++a;
	if (!(ret = ft_memalloc(sizeof(char) * (a + 1))))
		return (NULL);
	a = 0;
	while (str[a])
	{
		ret[a] = str[a];
		++a;
	}
	return (ret);
}
