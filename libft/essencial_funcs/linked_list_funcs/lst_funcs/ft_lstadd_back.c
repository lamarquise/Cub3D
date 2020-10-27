/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:18:47 by tlamart           #+#    #+#             */
/*   Updated: 2020/09/06 17:13:14 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	if (!alst || !new)
		return ;
	if (!*alst)
		*alst = new;
	list = *alst;
	while (list->next)
		list = list->next;
	list->next = new;
	new->next = NULL;
}
