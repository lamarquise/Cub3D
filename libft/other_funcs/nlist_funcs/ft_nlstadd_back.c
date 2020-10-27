/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 02:01:15 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/09 01:55:22 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nlstadd_back(t_nlist **lst, t_nlist *new)
{
	size_t	i;
	t_nlist	*tmp;

	i = 0;
	if (!lst || !new)
		return (0);
	if (!*lst)
	{
		*lst = new;
		new->index = i;
		return (1);
	}
	tmp = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		++i;
	}
	tmp->next = new;
	new->index = ++i;
	new->next = NULL;
	return (1);
}
