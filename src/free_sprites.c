/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:21:47 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 02:54:01 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// should work
int		ft_free_ttexture_contents(t_game *jeu, t_texture *tex)
{
	// value
	// char *path
	// timge img

	if (!jeu)
		return (0);		// 0 might be better
	if (!tex)
		return (1);
	if (tex->path)
	{
		free(tex->path);
		tex->path = NULL;
	}
	if (tex->img)
	{
		if (!ft_free_timge(jeu, tex->img))	// i think we don't need to wory about data
			return (ft_error_msg("failed to free img in tex\n", 0));
//		free(img);	// already done
	// sadly can't set to NULL
	}
	return (1);
}

	// kinda useless
int		ft_free_tsprite_contents(t_sprite *spri)
{
	// ttexture tex
	// pos.
	// dir.

	// id
	// anim color
	// life

// ok we have an issue, the textures in the sprite tex are pointers to textures in a
// linked list, 
// for now, don't del the texture, just set pointer to it to null

	if (spri->tex)
		spri->tex = NULL;
//	free(spri);				
	// nothing else i think, for now..

	return (1);
}


	// calling this calls free tsprite which does not free the OG textures
int		ft_free_tsprite_tab(t_sprite **spris, int n)
{
	int		i;

	if (!spris || n < 1)
		return (1);	// 1 ?
	i = 0;
	while (i < n)	// would while (spris[i]) work ???
	{
		if (!ft_free_tsprite_contents(spris[i]))
			return (ft_error_msg("failed to free spri in spris tab\n", 0));
		++i;
	}
	free(spris);	// should work ???
	return (1);
}

