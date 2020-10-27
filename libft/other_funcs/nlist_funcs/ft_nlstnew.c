/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 01:54:41 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/07 20:02:43 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_nlist		*ft_nlstnew(void *content, int index)
{
	t_nlist	*elem;

	if (!(elem = (t_nlist*)malloc(sizeof(t_nlist))))
		return (NULL);
	if (!content)
		elem->content = NULL;
	elem->content = content;
	elem->index = index;
	elem->next = NULL;
	return (elem);
}
