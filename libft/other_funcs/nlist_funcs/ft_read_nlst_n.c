/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_nlst_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 02:11:47 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/07 02:13:28 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_nlst_n(t_nlist *lst, int i)
{
	t_nlist	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp)
	{
		if (i == tmp->index)
			return ((char*)tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}
