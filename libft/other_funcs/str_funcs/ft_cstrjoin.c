/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:20:40 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/14 13:28:03 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cstrjoin(char c, char **s2)
{
	int		a;
	int		b;
	char	*ret;

	if (!s2)
		return (NULL);
	a = ft_fstrlen(*s2) + 2;
	if (!(ret = ft_memalloc(sizeof(char) * a)))
		return ((char*)ft_scott_free(s2, 0));
	a = 0;
	b = 0;
	ret[a++] = c;
	while (*s2 && (*s2)[b])
		ret[a++] = (*s2)[b++];
	ft_scott_free(s2, 0);
	return (ret);
}
