/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:21:47 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/29 09:43:11 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_free_ttexture_contents(t_game *jeu, t_texture *tex)
{
	if (!jeu)
		return (0);
	if (!tex)
		return (1);
	if (tex->path)
	{
		free(tex->path);
		tex->path = NULL;
	}
	if (tex->img)
	{
		if (!ft_free_timge(jeu, tex->img))
			return (ft_error_msg("failed to free img in tex\n", 0));
		tex->img = NULL;
	}
	return (1);
}

int		ft_free_tsprite_contents(t_sprite *spri)
{
	if (!spri)
		return (0);
	if (spri->tex)
		spri->tex = NULL;
	return (1);
}

int		ft_free_tsprite_tab(t_sprite *spris, int n)
{
	int i;

	if (!spris || n < 1)
		return (1);
	i = 0;
	while (i < n)
	{
		spris[i].tex = NULL;
		++i;
	}
	free(spris);
	return (1);
}
