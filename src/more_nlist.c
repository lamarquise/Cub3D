/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_nlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:46:17 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 18:49:55 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_print_nlist(t_nlist *lst)
{
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

int		ft_finish_del_spris(t_nlist **lst, t_nlist **tmp, int n)
{
	t_nlist		*elem;

	if (!lst || n < 0)
		return (0);
	*tmp = *lst;
	while (*tmp && (*tmp)->index < n - 1)
		*tmp = (*tmp)->next;
	elem = (*tmp)->next;
	ft_free_tsprite_contents((t_sprite*)elem->content);
	free(elem->content);
	(*tmp)->next = elem->next;
	free(elem);
	(*tmp) = (*tmp)->next;
	return (1);
}

int		ft_nlstdel_n_sprite(t_nlist **lst, int n)
{
	t_nlist		*tmp;

	if (!lst || n < 0)
		return (0);
	if (!*lst)
		return (1);
	if (n == 0)
	{
		tmp = (*lst)->next;
		ft_free_tsprite_contents((t_sprite*)(*lst)->content);
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	else if (!ft_finish_del_spris(lst, &tmp, n))
		return (0);
	while (tmp)
	{
		tmp->index -= 1;
		tmp = tmp->next;
	}
	return (1);
}

int		ft_nlstadd_secback(t_nlist **lst, void *content)
{
	size_t	i;
	t_nlist	*tmp;
	t_nlist	*new;

	i = 0;
	if (!lst || !content || !(new = ft_nlstnew(content, 0)))
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
