/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_more_structures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:31:38 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 23:50:03 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_settings(t_settings *set)
{
	set->minimap = 0;
	set->bonus = 0;
	set->zoom = 0;
	set->save = 0;
	set->pause = 0;
	set->change_lev = 0;
	return (1);
}

int	ft_init_level(t_level *lev)
{
	lev->floor = NULL;
	lev->dim.x = 0;
	lev->dim.y = 0;
	lev->last_box = 0;
	lev->player_spos.x = 0;
	lev->player_spos.y = 0;
	lev->player_sorient = 0;
	lev->spris_list = NULL;
	lev->spris_tab = NULL;
	lev->n_spris = 0;
	lev->exit_exists = 0;
	lev->exit_index = -1;
	lev->key_exists = 0;
	lev->key_index = -1;
	return (1);
}

int	ft_finish_init_player(t_game *jeu, t_level *lev)
{
	if (lev->player_sorient == 'S')
	{
		jeu->me->dir.x = 0;
		jeu->me->dir.y = 1;
		jeu->me->plane.x = -0.66;
		jeu->me->plane.y = 0;
		return (1);
	}
	else if (lev->player_sorient == 'E')
	{
		jeu->me->dir.x = 1;
		jeu->me->dir.y = 0;
		jeu->me->plane.x = 0;
		jeu->me->plane.y = 0.66;
		return (1);
	}
	else if (lev->player_sorient == 'W')
	{
		jeu->me->dir.x = -1;
		jeu->me->dir.y = 0;
		jeu->me->plane.x = 0;
		jeu->me->plane.y = -0.66;
		return (1);
	}
	return (0);
}

int	ft_init_player(t_game *jeu, t_level *lev)
{
	jeu->me->pos.x = lev->player_spos.x;
	jeu->me->pos.y = lev->player_spos.y;
	jeu->me->zoom_factor = 1;
	jeu->me->life = 100;
	if (lev->key_exists)
		jeu->me->key = 0;
	else
		jeu->me->key = 1;
	if (lev->player_sorient == 'N')
	{
		jeu->me->dir.x = 0;
		jeu->me->dir.y = -1;
		jeu->me->plane.x = 0.66;
		jeu->me->plane.y = 0;
	}
	ft_finish_init_player(jeu, lev);
	return (1);
}
