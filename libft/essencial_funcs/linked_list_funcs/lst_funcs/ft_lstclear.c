/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:54:43 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/06 17:20:13 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		elem = tmp;
		tmp = tmp->next;
		del(elem->content);
		free(elem);
	}
	*lst = NULL;
}
