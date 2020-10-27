/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 02:30:09 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/07 02:33:41 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_latoi(char *str, long *num)
{
	int	a;
	int	neg;
	int	nlen;

	if (!str || !num)
		return (-1);
	a = 0;
	neg = 1;
	*num = 0;
	nlen = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		++a;
	if (str[a] == 43 || str[a] == 45)
	{
		if (str[a] == 45)
			neg = -1;
		++a;
	}
	while (str[a + nlen] >= 48 && str[a + nlen] <= 57)
	{
		*num = *num * 10 + (str[a + nlen] - 48);
		++nlen;
	}
	*num *= neg;
	return (nlen);
}
