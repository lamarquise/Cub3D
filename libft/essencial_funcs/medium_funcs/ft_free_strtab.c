/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:20:42 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 20:14:08 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int		ft_free_strtab(char **tab)
{
	int		a;

	a = 0;
	if (!tab || !*tab)
		return (0);
	while (tab[a])
	{
//		ft_scott_free(&(tab[a]), 1);
		free(tab[a]);
		printf("free str tab, tab[a]: |%s|\n", tab[a]);
		++a;
	}
	return (1);
}
