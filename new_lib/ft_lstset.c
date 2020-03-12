/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:44:22 by tlamart           #+#    #+#             */
/*   Updated: 2019/11/16 17:16:24 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstset(void *content, size_t len)
{
	t_list	*begin;
	t_list	*lst;

	if (!len)
		return (NULL);
	if (!(begin = ft_lstnew(content)))
		return (NULL);
	len--;
	while (len > 0)
	{
		if (!(lst = ft_lstnew(content)))
		{
			ft_lstclear(&begin, &ft_lstdel_cnt);
			return (NULL);
		}
		ft_lstadd_front(&begin, lst);
		len--;
	}
	return (begin);
}
