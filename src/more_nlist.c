/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_nlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:46:17 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 01:41:33 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is a placeholder file

#include "cub3d.h"


int		ft_print_nlist(t_nlist *lst)
{
	// need a tmp ?

	if (!lst)
		return (0);
	while (lst)
	{
		ft_putstr((char*)lst->content);
		write(1, "\n", 1);
		lst = lst->next;
	}
	return (1);
}

	// copy all this into del n one cuz apparently the other one seg faults for no reason

	// not good enough we need to actually free the sprite struct in content

int		ft_nlstdel_n_sprite(t_nlist **lst, int n)
{
	t_nlist		*tmp;
	t_nlist		*elem;

//	printf("del n sprite test 1\n");

	if (!lst || !*lst || n < 0)
		return (0);
	if (n == 0)
	{
//	printf("del n sprite test 2\n");
		tmp = (*lst)->next;
		ft_free_tsprite_contents((t_sprite*)(*lst)->content);	// free the contents of sprite
		free((*lst)->content);		// then free contents of list, a sprite struct var
		free(*lst);
		*lst = tmp;
	}
	else
	{
//	printf("del n sprite test 3\n");
		tmp = *lst;
		while (tmp && tmp->index < n - 1)
			tmp = tmp->next;
		elem = tmp->next;
		ft_free_tsprite_contents((t_sprite*)elem->content);	// same here
		free(elem->content);
		tmp->next = elem->next;
		free(elem);
		tmp = tmp->next;
	}
//	printf("del n sprite test 4\n");
	while (tmp)
	{
		tmp->index -= 1;
		tmp = tmp->next;
	}
/*
	tmp = *lst;
	while (tmp)
	{
		printf("tmp index: %d\n", tmp->index);
		tmp = tmp->next;
	}
	printf("del n sprite test 5\n");
*/	return (1);
}

	// need it ???
													// void ????
int		ft_nlstdel_all_with(t_nlist **lst, int (*del)(void *))
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

	t_nlist	*elem;

	if (!lst || !del)
		return (0);
	tmp = *lst;
	while (tmp)
	{
		elem = tmp;
		tmp = tmp->next;
		if (!del(elem->content))
			return (0);
		free(elem);
	}
	*lst = NULL;

	return (1);
}


int		ft_nlstadd_secback(t_nlist **lst, void *content)
{
	size_t	i;
	t_nlist	*tmp;
	t_nlist	*new;

	i = 0;
	if (!lst || !content || !(new = ft_nlstnew(content, 0)))
		return (0);
	if (!*lst)
	{
		*lst = new;
		new->index = i;
		return (1);
	}
	tmp = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		++i;
	}
	tmp->next = new;
	new->index = ++i;
	new->next = NULL;
	return (1);
}



