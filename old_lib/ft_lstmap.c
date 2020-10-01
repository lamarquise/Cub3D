/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:33:32 by erlazo            #+#    #+#             */
/*   Updated: 2019/11/20 17:54:52 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	new = NULL;
	if (!f || !lst)
		return (NULL);
	if (lst)
	{
		if (!(new = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		if (!(new->content = f(lst->content)))
		{
			del(new->content);
			return (NULL);
		}
		new->next = ft_lstmap(lst->next, f, del);
	}
	return (new);
}
