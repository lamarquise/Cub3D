/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:08:54 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/07 02:28:07 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		a;
	long	ret;
	int		neg;

	a = 0;
	ret = 0;
	neg = 1;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		++a;
	if (str[a] == 43 || str[a] == 45)
	{
		if (str[a] == 45)
			neg = -1;
		++a;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		ret = ret * 10 + (str[a] - 48);
		++a;
	}
	return (ret * neg);
}
