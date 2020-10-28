/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 03:14:22 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 22:43:15 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_draw_floor(t_game *jeu, int x, int y, t_vect_i tex)
{
	int		color;
	t_imge	*tex_img;

	tex_img = jeu->file->floor->img;
	color = tex_img->img_data[tex_img->img_hei * tex.y + tex.x];
	ft_pix_imge(jeu->fpv, x + y * jeu->file->res.x, color);
	return (1);
}

int			ft_draw_ceiling(t_game *jeu, int x, int y, t_vect_i tex)
{
	int		color;
	t_imge	*tex_img;

	tex_img = jeu->file->ceiling->img;
	color = tex_img->img_data[tex_img->img_hei * tex.y + tex.x];
	ft_pix_imge(jeu->fpv, (jeu->file->res.y - y - 1) \
						* jeu->file->res.x + x, color);
	return (1);
}

t_vect_i	ft_get_floor_tex(t_imge *img, t_vect_d *floor, t_vect_i *cell)
{
	t_vect_i	tex;

	tex.x = (int)(img->img_wid * (floor->x - cell->x)) & (img->img_wid - 1);
	tex.y = (int)(img->img_hei * (floor->y - cell->y)) & (img->img_hei - 1);
	return (tex);
}

int			ft_shoot_floor_ray(t_game *jeu, t_vect_d *floor, \
			t_vect_d *floor_step, double row_dist)
{
	t_vect_d	ray_zero;
	t_vect_d	ray_one;

	ray_zero.x = jeu->me->dir.x * jeu->me->zoom_factor - jeu->me->plane.x;
	ray_zero.y = jeu->me->dir.y * jeu->me->zoom_factor - jeu->me->plane.y;
	ray_one.x = jeu->me->dir.x * jeu->me->zoom_factor + jeu->me->plane.x;
	ray_one.y = jeu->me->dir.y * jeu->me->zoom_factor + jeu->me->plane.y;
	floor_step->x = row_dist * (ray_one.x - ray_zero.x) / jeu->file->res.x;
	floor_step->y = row_dist * (ray_one.y - ray_zero.y) / jeu->file->res.x;
	floor->x = jeu->me->pos.x + row_dist * ray_zero.x;
	floor->y = jeu->me->pos.y + row_dist * ray_zero.y;
	return (1);
}

int			ft_floorcasting(t_game *jeu)
{
	int			y;
	int			x;
	t_vect_d	floor_step;
	t_vect_d	floor;
	t_vect_i	cell;

	y = -1;
	while (++y < jeu->file->res.y)
	{
		ft_shoot_floor_ray(jeu, &floor, &floor_step, (0.5 * jeu->file->res.y) \
						/ (y - jeu->file->res.y / 2));
		x = -1;
		while (++x < jeu->file->res.x)
		{
			cell.x = (int)floor.x;
			cell.y = (int)floor.y;
			ft_draw_floor(jeu, x, y, ft_get_floor_tex(jeu->file->floor->img,\
					&floor, &cell));
			ft_draw_ceiling(jeu, x, y, \
					ft_get_floor_tex(jeu->file->ceiling->img, &floor, &cell));
			floor.x += floor_step.x;
			floor.y += floor_step.y;
		}
	}
	return (1);
}
