/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 02:03:26 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/07 02:04:54 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nlstadd_front(t_nlist **lst, t_nlist *new)
{
	if (!lst || !new)
		return (0);
	new->next = *lst;
	*lst = new;
	new->index = 0;
	while (*lst)
	{
		++(*lst)->index;
		(*lst) = (*lst)->next;
	}
	return (1);
}
