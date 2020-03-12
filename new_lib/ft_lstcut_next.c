/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:30:40 by tlamart           #+#    #+#             */
/*   Updated: 2019/11/20 19:03:55 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcut_next(t_list **lst)
{
	t_list	*cut;
	t_list	*tmp;

	cut = (*lst)->next;
	tmp = cut->next;
	ft_lstdelone(cut, &ft_lstdel_cnt);
	(*lst)->next = tmp;
}
