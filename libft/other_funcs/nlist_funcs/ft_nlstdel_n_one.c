/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlstdel_n_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 02:09:22 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/29 10:06:23 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_finish_del(t_nlist **lst, t_nlist **tmp, int n)
{
	t_nlist	*elem;

	if (!lst || n < 0)
		return (0);
	*tmp = *lst;
	while (*tmp && (*tmp)->index < n - 1)
		*tmp = (*tmp)->next;
	elem = (*tmp)->next;
	free(elem->content);
	(*tmp)->next = elem->next;
	free(elem);
	(*tmp) = (*tmp)->next;
	return (1);
}

int		ft_nlstdel_n_one(t_nlist **lst, int n)
{
	t_nlist *tmp;

	if (!lst || !*lst || n < 0)
		return (0);
	if (n == 0)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	else if (!ft_finish_del(lst, &tmp, n))
		return (0);
	while (tmp)
	{
		tmp->index -= 1;
		tmp = tmp->next;
	}
	return (1);
}
