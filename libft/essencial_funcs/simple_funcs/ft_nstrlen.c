/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:53:21 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/16 20:11:09 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_nstrlen(char *s, int ret)
{
	int		a;

	a = 0;
	if (!s)
		return (ret);
	while (s[a])
		++a;
	return (a);
}
