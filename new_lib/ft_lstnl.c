/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 08:36:25 by tlamart           #+#    #+#             */
/*   Updated: 2019/11/16 17:15:59 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstnl(t_list **list, void const *content)
{
	t_list	*new;

	if (!(new = ft_lstnew((void*)content)))
		return (0);
	ft_lstadd_back(list, new);
	return (1);
}
