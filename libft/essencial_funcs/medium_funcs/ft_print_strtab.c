/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:23:18 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/16 17:25:24 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_strtab(char **tab)
{
	int		a;

	if (!tab)
		return (0);
	a = 0;
	while (tab[a])
	{
		write(1, tab[a], ft_fstrlen(tab[a]));
		write(1, "\n", 1);
		++a;
	}
	return (1);
}
