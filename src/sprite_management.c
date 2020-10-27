/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 00:56:31 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 16:01:19 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*ft_new_tsprite(t_texture tex, int x, int y, char c)
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


	// now making copies of sprites and textures
int			ft_lstadd_sprite_instance(t_game *jeu, int x, int y, char c)
{
	t_sprite	*spri;
	t_texture	tex;
	t_nlist		*tmp;

//	tex = NULL;
	tmp = NULL;
	if (!jeu || !jeu->lev)
		return (ft_error_msg("no jeu or lev in add sprite instance\n", 0));
	tmp = jeu->file->spri_type_texs;
	while (tmp)
	{
		if ((char)(((t_texture*)tmp->content)->value) == c)
		{
			spri = NULL;
			tex = *(t_texture*)tmp->content;
			if (!(spri = ft_new_tsprite(tex, x, y, c)))
				return (ft_error_msg("failed to make new tsprite\n", 0));
//			((t_texture*)tmp->content)->value = 999;
//	printf("tmp value: %d, spri tex value: %d\n", ((t_texture*)tmp->content)->value, spri->tex->value);

			if (!ft_nlstadd_back(&jeu->lev->spris_list, ft_nlstnew((void*)spri, 0)))
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

int		ft_create_spris_tab(t_level *lev)
{
	t_nlist		*tmp;
	int			i;
	t_sprite	tab[lev->n_spris];

	if (!lev)
		return (0);
	if (!lev->spris_list)	// maybe...
		return (1);
	tmp = lev->spris_list;
/*	lev->spris_tab = NULL;
	if (!(lev->spris_tab = malloc(sizeof(t_sprite) * (lev->n_spris))))
		return (0);
	i = -1;
	while (++i < lev->n_spris && tmp)
	{
		lev->spris_tab[i] = *(t_sprite*)tmp->content;// copy of sprite in sprilist
		if ((*(t_sprite*)tmp->content).id == 'Y')
			lev->key_index = i;
		else if ((*(t_sprite*)tmp->content).id == 'X')
			lev->exit_index = i;
//		printf("create tab, id: %c\n", lev->spris_tab[i].id);
		tmp = tmp->next;
	}
//	lev->spris_tab[i] = NULL;	// would need a **spris_tab...
*/	i = -1;
	while (++i < lev->n_spris && tmp)
	{
		tab[i] = *(t_sprite*)tmp->content;
		if ((*(t_sprite*)tmp->content).id == 'Y')
			lev->key_index = i;
		else if ((*(t_sprite*)tmp->content).id == 'X')
			lev->exit_index = i;
//		printf("create tab, id: %c\n", lev->spris_tab[i].id);
		tmp = tmp->next;
	}
	lev->spris_tab = tab;
	return (1);
}

//		printf("spris list i: %d, index: %d, pos.x: %f, y: %f\n", i, tmp->index, (*(t_sprite*)tmp->content).pos.x,(*(t_sprite*)tmp->content).pos.y);
//		printf("spris tab[%d]: pos x: %f, y: %f\n", i, lev->spris_tab[i].pos.x, lev->spris_tab[i].pos.y);

//VX		(*(t_sprite*)tmp->content).id = 'Z';
//	printf("list id: %c, tab id: %c\n", (*(t_sprite*)tmp->content).id, lev->spris_tab[i]->id);





