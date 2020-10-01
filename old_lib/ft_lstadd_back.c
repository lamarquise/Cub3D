/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:18:47 by tlamart           #+#    #+#             */
/*   Updated: 2019/11/04 17:35:01 by erlazo           ###   ########.fr       */
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
