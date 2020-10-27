/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:01:00 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/26 18:12:58 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_generate_sight_lines(t_game *jeu)
{
	int			bres_spos;
	t_coords	left;
	t_coords	right;

	if (!jeu)
		return (0);
	bres_spos = (jeu->me->pos.x * jeu->grid_box_size) + \
				(int)(jeu->me->pos.y * jeu->grid_box_size) * jeu->yah->img_wid;
	left.x1 = jeu->me->pos.x * jeu->grid_box_size;
	left.y1 = jeu->me->pos.y * jeu->grid_box_size;
	left.x2 = (jeu->me->pos.x + jeu->me->dir.x * jeu->me->zoom_factor \
				- jeu->me->plane.x) * jeu->grid_box_size;
	left.y2 = (jeu->me->pos.y + jeu->me->dir.y * jeu->me->zoom_factor \
				- jeu->me->plane.y) * jeu->grid_box_size;
	right.x1 = jeu->me->pos.x * jeu->grid_box_size;
	right.y1 = jeu->me->pos.y * jeu->grid_box_size;
	right.x2 = (jeu->me->pos.x + jeu->me->dir.x * jeu->me->zoom_factor \
				+ jeu->me->plane.x) * jeu->grid_box_size;
	right.y2 = (jeu->me->pos.y + jeu->me->dir.y * jeu->me->zoom_factor \
				+ jeu->me->plane.y) * jeu->grid_box_size;
	if (!ft_bresenham(jeu->yah, left, YELLOW) \
		|| !ft_bresenham(jeu->yah, right, YELLOW))
		return (0);
	return (1);
}

int		ft_generate_player(t_game *jeu)
{
	int			size;
	int			s_pos;

	if (!jeu)
		return (0);
	size = jeu->grid_box_size / 6;
	if (size < 1)
		size = 1;
	if (!ft_fill_imge(jeu->yah, ft_rgb_to_int(0, 0, 0, jeu->fog)))
		return (0);
	s_pos = ((jeu->me->pos.x * jeu->grid_box_size) - size / 2) \
			+ (int)(jeu->me->pos.y * jeu->grid_box_size - size / 2) \
			* jeu->yah->img_wid;
	if (!(ft_draw_box(jeu->yah, s_pos, size, ft_rgb_to_int(255, 0, 0, 0))))
		return (ft_error_msg("Failed to draw player square in yah img\n", 0));
	if (!ft_generate_sight_lines(jeu))
		return (ft_error_msg("Failed to draw sight lines in yah img\n", 0));
	return (1);
}

int	ft_generate_minimap(t_game *jeu, t_level *lev)
{
	if (!jeu || !lev)
		return (0);
	if ((jeu->grid_box_size = ft_sizing_minimap_imge(jeu, lev)) == -1)
		return (ft_error_msg("Failed to size minimap\n", 0));
	jeu->grid_pixs.x = jeu->grid_box_size * lev->dim.x;
	jeu->grid_pixs.y = jeu->grid_box_size * lev->dim.y;
	jeu->grid_tl.x = (jeu->file->res.x - jeu->grid_pixs.x) / 2;
	jeu->grid_tl.y = (jeu->file->res.y - jeu->grid_pixs.y) / 2;
	if (!(jeu->minimap = ft_create_imge(jeu->mlx, jeu->file->res.x, \
		jeu->file->res.y)))
		return (0);	
	if (!ft_fill_imge(jeu->minimap, ft_rgb_to_int(0, 0, 0, jeu->fog)))
		return (0);
	if (!ft_draw_grid(jeu, lev, jeu->minimap, jeu->grid_tl.x \
		+ jeu->grid_tl.y * jeu->file->res.x))
		return (0);
	return (1);
}
