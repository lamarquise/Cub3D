/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:17:10 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/16 01:59:11 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	a;

	a = 0;
	if (!s)
		return ;
	if (!f)
		return ;
	while (s[a])
	{
		f(a, &s[a]);
		++a;
	}
}
