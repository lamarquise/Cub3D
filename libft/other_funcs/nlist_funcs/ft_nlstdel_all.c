/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlstdel_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 02:05:04 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/07 02:18:10 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nlstdel_all(t_nlist **lst)
{
	t_nlist	*tmp;

	if (!lst)
		return (0);
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	return (1);
}
