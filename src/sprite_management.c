/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 00:56:31 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 23:41:48 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*ft_new_tsprite(t_texture *tex, int x, int y, char c)
{
	t_sprite	*new;

	if (!(new = malloc(sizeof(t_sprite))))
		return (NULL);
	new->tex = tex;
	new->pos.x = x + 0.5;
	new->pos.y = y + 0.5;
	new->dir.x = 0;
	new->dir.y = -1;
	new->id = c;
	new->anim_color = 0;
	new->life = 100;
	return (new);
}

int			ft_lstadd_sprite_instance(t_game *jeu, int x, int y, char c)
{
	t_sprite	*spri;
	t_texture	*tex;
	t_nlist		*tmp;

	if (!jeu || !jeu->lev)
		return (ft_error_msg("no jeu or lev in add sprite instance\n", 0));
	tmp = jeu->file->spri_type_texs;
	while (tmp)
	{
		if ((char)(((t_texture*)tmp->content)->value) == c)
		{
			spri = NULL;
			tex = (t_texture*)tmp->content;
			if (!(spri = ft_new_tsprite(tex, x, y, c)))
				return (ft_error_msg("failed to make new tsprite\n", 0));
			if (!ft_nlstadd_secback(&jeu->lev->spris_list, (void*)spri))
			{
				free(spri);
				return (ft_error_msg("failed to add sprite to list\n", 0));
			}
			return (1);
		}
		tmp = tmp->next;
	}
	return (ft_error_msg("No tex corresponding to this sprite type\n", 0));
}

int			ft_create_spris_tab(t_level *lev)
{
	t_nlist	*tmp;
	int		i;

	if (!lev)
		return (0);
	if (!lev->spris_list)
		return (1);
	tmp = lev->spris_list;
	lev->spris_tab = NULL;
	if (!(lev->spris_tab = malloc(sizeof(t_sprite) * (lev->n_spris))))
		return (0);
	i = -1;
	while (++i < lev->n_spris && tmp)
	{
		lev->spris_tab[i] = *(t_sprite*)tmp->content;
		if ((*(t_sprite*)tmp->content).id == 'Y')
			lev->key_index = i;
		else if ((*(t_sprite*)tmp->content).id == 'X')
			lev->exit_index = i;
		tmp = tmp->next;
	}
	return (1);
}
