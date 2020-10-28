/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:31:38 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 01:05:23 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_input(t_input *file)
{
	file->res.x = -1;
	file->res.y = -1;
	file->no = NULL;
	file->so = NULL;
	file->we = NULL;
	file->ea = NULL;
	file->spri_type_texs = NULL;
	file->n_spri_types = 0;
	file->floor = NULL;
	file->ceiling = NULL;
	return (1);
}

int	ft_init_mlx(t_game *jeu)
{
	t_lmlx *mlx;

	if (!jeu || !(mlx = malloc(sizeof(t_lmlx))))
		return (0);
	jeu->mlx = mlx;
	if (!(jeu->mlx->ptr = mlx_init()))
		return (0);
	return (1);
}

int	ft_init_torch(t_game *jeu)
{
	int		i;

	if (!jeu)
		return (0);
	i = 0;
	while (i < 127)
		jeu->torch[i++] = 0;
	return (1);
}

int	ft_init_game(t_game *jeu)
{
	jeu->file = NULL;
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
	jeu->sbol = 1;
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
	return (1);
}
