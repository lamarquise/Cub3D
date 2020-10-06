/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_nlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:46:17 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/05 16:52:48 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is a placeholder file

#include "cub3d.h"


int		ft_print_nlist(t_nlist *lst)
{
	// need a tmp ?

	if (!lst)
		return (0);
	while (lst)
	{
		ft_putstr((char*)lst->content);
		write(1, "\n", 1);
		lst = lst->next;
	}
	return (1);
}


