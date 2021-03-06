/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:20:42 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/29 09:49:35 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_free_strtab(char **tab)
{
	int		a;

	a = 0;
	if (!tab)
		return (0);
	while (tab[a])
	{
		ft_scott_free(&(tab[a]), 1);
		++a;
	}
	free(tab);
	tab = NULL;
	return (1);
}
