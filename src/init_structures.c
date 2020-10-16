/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:31:38 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/16 04:05:46 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// all this shit needs to be properly secured


#include "cub3d.h"

int	ft_init_settings(t_settings *set)
{
	set->minimap = 0;
	set->bonus = 0;	// 0 being no bonuses
	set->save = 0;
	set->pause = 0;
	set->change_lev = 0;
	// more
	return (1);
}

int	ft_init_level(t_level *lev)
{	
	lev->floor = NULL;
	lev->dim.x = 0;
	lev->dim.y = 0;
	lev->last_box = 0;
	lev->player_pos.x = 0;
	lev->player_pos.y = 0;
	lev->exit_pos.x = -4;
	lev->exit_pos.y = -4;
//	lev->exit_t = NULL;
	return (1);
}

	// make a func that fills t_vect structs
	// this isnt really an init tho...
int	ft_init_player(t_game *jeu, t_level *lev)
{
	jeu->me->pos.x = lev->player_pos.x;
	jeu->me->pos.y = lev->player_pos.y;

		// new version, seems to be correct...
	if (lev->player_orient == 'N')
	{
		jeu->me->dir.x = 0;
		jeu->me->dir.y = -1;
		jeu->me->plane.x = 0.66;
		jeu->me->plane.y = 0;
	}
	if (lev->player_orient == 'S')
	{
		jeu->me->dir.x = 0;
		jeu->me->dir.y = 1;
		jeu->me->plane.x = -0.66;
		jeu->me->plane.y = 0;
	}
	if (lev->player_orient == 'E')
	{
		jeu->me->dir.x = 1;
		jeu->me->dir.y = 0;
		jeu->me->plane.x = 0;
		jeu->me->plane.y = 0.66;
	}
	if (lev->player_orient == 'W')
	{
		jeu->me->dir.x = -1;
		jeu->me->dir.y = 0;
		jeu->me->plane.x = 0;
		jeu->me->plane.y = -0.66;	// the OG tutorial has +0.66 ???
	}
	jeu->me->life = 100;	// in this case we get full life each level...
	return (1);
}

int	ft_init_input(t_input *file)
{
	file->res.x = -1;
	file->res.y = -1;

	file->sprites = NULL;
	file->no = NULL;
	file->so = NULL;
	file->we = NULL;
	file->ea = NULL;

	file->tex_list = NULL;
	file->index_tab = NULL;
	file->nsprites = 0;

//	file->exit = NULL;

	file->floor = NULL;
	file->ceiling = NULL;
	return (1);
}

int	ft_init_binput(t_binput *b_file)
{
	b_file->exit = NULL;
	b_file->key = NULL;
	b_file->opener = NULL;

	return (1);
}

int	ft_init_mlx(t_game *jeu)
{
	t_lmlx *mlx;

	if (!(mlx = malloc(sizeof(t_lmlx))))
		return (0);
	jeu->mlx = mlx;
	if (!(jeu->mlx->ptr = mlx_init()))      // i think...
		return (0);
	return (1);
}

int	ft_init_torch(t_game *jeu)
{
	int		i;

	// secure ?
	i = 0;
	while (i < 127)
		jeu->torch[i++] = 0;
	return (1);
}

int	ft_init_game(t_game *jeu)
{
	jeu->file = NULL;
	jeu->b_file = NULL;
	jeu->level_list = NULL;
	jeu->lev = NULL;
	jeu->n_of_levels = 0;
	jeu->cur_level = 0;
	jeu->me = NULL;
	jeu->set = NULL;

	jeu->mlx = NULL;
	jeu->win = NULL;

	jeu->yah = NULL;
	jeu->crosshair = NULL;
	jeu->minimap = NULL;
	jeu->fpv = NULL;
	jeu->title_screen = NULL;

	jeu->sbol = 1;			// why does bol have to equal 1 ???
	jeu->bbol = 1;
	jeu->fog = -1;
	ft_init_torch(jeu);
	jeu->mouse.x = 0;		
	jeu->mouse.y = 0;

	jeu->grid_pixs.x = -1;
	jeu->grid_pixs.y = -1;
	jeu->grid_tl.x = -1;
	jeu->grid_tl.y = -1;
	jeu->grid_box_size = -1;

//	jeu->hud = NULL;
	return (1);
}


/*
int	ft_init_sprite()
{
	return (1);
}
*/
/*
int	*ft_init_index_tab()
{
	int		*tab;

	tab = NULL;
	if (!(tab = malloc()))
		return (NULL);
	return (tab);
}
*/


