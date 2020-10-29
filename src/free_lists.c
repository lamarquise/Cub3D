/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 02:01:00 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/29 13:46:30 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_free_texture_list(t_game *jeu, t_nlist **lst)
{
	t_nlist		*tmp;
	t_texture	*tex;

	if (!jeu || !lst)
		return (0);
	if (!*lst)
		return (1);
	tmp = *lst;
	while (tmp)
	{
		tex = (t_texture*)tmp->content;
		if (tex && !ft_free_ttexture_contents(jeu, tex))
			return (ft_error_msg("failed to free tex in tex list\n", 0));
		tmp = tmp->next;
	}
	if (!ft_nlstdel_all(lst))
		return (ft_error_msg("failed to del tex list\n", 0));
	*lst = NULL;
	return (1);
}

int		ft_free_sprites_list(t_nlist **lst)
{
	t_nlist		*tmp;
	t_sprite	*spri;

	if (!lst)
		return (0);
	if (!*lst)
		return (1);
	tmp = *lst;
	while (tmp)
	{
		spri = (t_sprite*)tmp->content;
		if (spri && !ft_free_tsprite_contents(spri))
			return (ft_error_msg("failed to free spri in spri list\n", 0));
		tmp = tmp->next;
	}
	if (!ft_nlstdel_all(lst))
		return (ft_error_msg("failed to del spri list\n", 0));
	*lst = NULL;
	return (1);
}

int		ft_free_level_list(t_nlist **lst)
{
	t_nlist	*tmp;
	t_level	*lev;

	if (!lst)
		return (0);
	if (!*lst)
		return (1);
	tmp = *lst;
	while (tmp)
	{
		lev = (t_level*)tmp->content;
		if (lev && !ft_free_tlevel_contents(lev))
			return (ft_error_msg("failed to free lev in lev list\n", 0));
		tmp = tmp->next;
	}
	if (!ft_nlstdel_all(lst))
		return (ft_error_msg("failed to del lev list list\n", 0));
	*lst = NULL;
	return (1);
}
