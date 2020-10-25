/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 00:56:31 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/24 23:32:29 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// ok so i have a linked list of sprites for each level
// now what ?

/*
	What do i need in order to render anything ?
I need to know what order the sprites are in relative to me
So get the dist (x^2 + y^2, no need to do the square root)
sort by dist

	we are actually gonna use a list not a linked list to store the sprites



*/


	// tex, pos, id, num

t_sprite	*ft_new_tsprite(t_texture *tex, int x, int y, char c)
{
	t_sprite	*new;

	if (!(new = malloc(sizeof(t_sprite))))
		return (NULL);
	// posibly ft_init_sprite here if add other var to t_sprite Struct that would
	// change later.

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

int			ft_lstadd_sprite_instance(t_game *jeu, t_level *lev, int x, int y, char c)
{
	t_sprite	*spri;
	t_texture	*tex;
	t_nlist		*tmp;
//	int			i;

	spri = NULL;	// necessary ???
	tex = NULL;
	tmp = NULL;
	if (!jeu || !lev)
		return (ft_error_msg("no jeu or lev in add sprite instance\n", 0));
	// don't need to make a new tex, just point to same place !!!

//	i = 0;
	tmp = jeu->file->spri_type_texs;
	while (tmp)
	{
		tex = (t_texture*)tmp->content;
		if ((char)(tex->value) == c)		// - tex id eventually ???
		{
			if (!(spri = ft_new_tsprite(tex, x, y, c)))
				return (ft_error_msg("failed to make new tsprite\n", 0));
			if (!ft_nlstadd_back(&lev->spris_list, ft_nlstnew((void*)spri, 0)))  // is secure 
				return (ft_error_msg("failed to add sprite to list\n", 0));
		}
		tmp = tmp->next;
//		++i;
	}
	return (1);
}
