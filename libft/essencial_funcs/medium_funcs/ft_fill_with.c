/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_with.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:53:39 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/19 04:45:57 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fill_with(char this, int len)
{
	char    *ret;
	int		i;

	if (!this || len < 1)
		return (NULL);
	if (!(ret = ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		ret[i++] = this;
	ret[i] = '\0';
	return (ret);
}
