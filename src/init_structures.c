/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:31:38 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/01 05:00:21 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_settings(t_settings *set)
{
	set->minimap = 0;
	// more
	return (1);
}

	// make a func that fills t_vect structs
	// this isnt really an init tho...
int	ft_init_player(t_game *jeu)
{
		// new version, seems to be correct...
	if (jeu->me->s_dir == 'N')
	{
		jeu->me->dir.x = 0;
		jeu->me->dir.y = -1;
		jeu->me->plane.x = 0.66;
		jeu->me->plane.y = 0;
	}
	if (jeu->me->s_dir == 'S')
	{
		jeu->me->dir.x = 0;
		jeu->me->dir.y = 1;
		jeu->me->plane.x = -0.66;
		jeu->me->plane.y = 0;
	}
	if (jeu->me->s_dir == 'E')
	{
		jeu->me->dir.x = 1;
		jeu->me->dir.y = 0;
		jeu->me->plane.x = 0;
		jeu->me->plane.y = 0.66;
	}
	if (jeu->me->s_dir == 'W')
	{
		jeu->me->dir.x = -1;
		jeu->me->dir.y = 0;
		jeu->me->plane.x = 0;
		jeu->me->plane.y = -0.66;	// the OG tutorial has +0.66 ???
	}
	return (1);
}

int	ft_init_input(t_input *file)
{
	file->res.x = -1;
	file->res.y = -1;
	file->no_tex = NULL;
	file->so_tex = NULL;
	file->we_tex = NULL;
	file->ea_tex = NULL;
	file->sprite_tex = NULL;
	file->no_path = NULL;
	file->so_path = NULL;
	file->we_path = NULL;
	file->ea_path = NULL;
	file->sprite_path = NULL;
	file->c = -1;
	file->f = -1;
	return (0);
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
	jeu->floor = NULL;
	jeu->boxes.x = 0;		// these were -1
	jeu->boxes.y = 0;
	jeu->last_box = 0;
	jeu->mlx = NULL;
	jeu->win = NULL;
	jeu->hud = NULL;
	jeu->grid_pixs.x = -1;
	jeu->grid_pixs.y = -1;
	jeu->grid_tl.x = -1;
	jeu->grid_tl.y = -1;
	jeu->fog = -1;
	jeu->grid_box_size = -1;
	jeu->crosshair = NULL;
	jeu->yah = NULL;
	jeu->minimap = NULL;
	jeu->fpv = NULL;
	jeu->bol = 1;
	jeu->tex_list = NULL;
	jeu->me = NULL;
	jeu->set = NULL;
	if (!ft_init_torch(jeu))
		return (0);
	return (1);
}

