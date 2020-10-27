/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 01:29:05 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/19 04:46:12 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nstrdup(char **cp, char *og)
{
	int		a;

	if (!og)
		return (1);
	if (!cp)
		return (0);
	a = 0;
	while (og[a])
		++a;
	if (!(*cp = ft_memalloc(sizeof(char) * (a + 1))))
		return (0);
	a = 0;
	while (og[a])
	{
		(*cp)[a] = og[a];
		++a;
	}
	return (1);
}
