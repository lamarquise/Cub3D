/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 02:39:13 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/07 02:41:47 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pos_itoa(unsigned long long n)
{
	unsigned long long	nb;
	char				*ret;
	int					len;

	nb = n;
	len = 1;
	while (nb >= 10)
	{
		nb /= 10;
		++len;
	}
	if (!(ret = ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len--] = '\0';
	nb = n;
	while (len >= 0)
	{
		ret[len] = nb % 10 + 48;
		nb /= 10;
		--len;
	}
	return (ret);
}
