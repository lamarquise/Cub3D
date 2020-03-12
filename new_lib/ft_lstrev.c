/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:35:35 by erlazo            #+#    #+#             */
/*   Updated: 2018/11/19 19:47:52 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tmp1 = *lst;
	tmp2 = (*lst)->next;
	tmp3 = (*lst)->next->next;
	tmp1->next = NULL;
	while (tmp3)
	{
		tmp2->next = tmp1;
		tmp1 = tmp2;
		tmp2 = tmp3;
		tmp3 = tmp3->next;
	}
	tmp2->next = tmp1;
	*lst = tmp2;
}
