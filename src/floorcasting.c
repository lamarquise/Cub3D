/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 03:14:22 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 21:19:38 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	OK i think i get the algo
You go row by row down, and for each row you want to know the dist btw the camera
and the floor or ceiling, so further across the middle of the screen and closer
at the bottom and top

*/

	// may have to apply a zoom here too ?

	// call something dif
	// this just does floor...


int		ft_floorcasting(t_game *jeu)
{
	t_vect_d	ray_zero;	// dir for left most ray
	t_vect_d	ray_one;	// dir for right most ray
	int			y;			// y coord on screen
	int			p;			// curr y pos relative to center of screen
	double		pos_z;		// vertical pos of camera
	double		row_dist;

	t_vect_d	floor_step;	// real world steps (like not pixel of tex) to add for 
					// each x (im assuming down the screen, so like 

	t_vect_d	floor;//real world coords of left most col, gets updated as we step right

	int			x;

	t_vect_i	cell;	// int parts of floor
	t_vect_i	tex;	// pix coord on texture(from fractional part, not sure what means)

	y = 0;
	while (y < jeu->file->res.y)
	{
		ray_zero.x = jeu->me->dir.x * jeu->me->zoom_factor - jeu->me->plane.x;
		ray_zero.y = jeu->me->dir.y * jeu->me->zoom_factor - jeu->me->plane.y;
		ray_one.x = jeu->me->dir.x * jeu->me->zoom_factor + jeu->me->plane.x;
		ray_one.y = jeu->me->dir.y * jeu->me->zoom_factor + jeu->me->plane.y;

		p = y - jeu->file->res.y / 2;	// starts as - half screen hei ends up + half ?
		pos_z = 0.5 * jeu->file->res.y;
		row_dist = pos_z / p;		


		floor_step.x = row_dist * (ray_one.x - ray_zero.x) / jeu->file->res.x;
		floor_step.y = row_dist * (ray_one.y - ray_zero.y) / jeu->file->res.x;//still res.x

		floor.x = jeu->me->pos.x + row_dist * ray_zero.x;
		floor.y = jeu->me->pos.y + row_dist * ray_zero.y;

		// contender for dif func
		x = 0;
		while (x < jeu->file->res.x)
		{
			cell.x = (int)floor.x;
			cell.y = (int)floor.y;

			tex.x = (int)(jeu->file->floor->img->img_wid * (floor.x - cell.x)) \
					& (jeu->file->floor->img->img_wid - 1);
			tex.y = (int)(jeu->file->floor->img->img_hei * (floor.y - cell.y)) \
					& (jeu->file->floor->img->img_hei - 1);

			floor.x += floor_step.x;
			floor.y += floor_step.y;


			int		color;
			t_imge	*tex_img;

			tex_img = jeu->file->floor->img;

			color = tex_img->img_data[tex_img->img_hei * tex.y + tex.x];

			ft_pix_imge(jeu->fpv, x + y * jeu->file->res.x, color);

			ft_pix_imge(jeu->fpv, (jeu->file->res.y - y - 1) * jeu->file->res.x + x , color);



			++x;
		}

		++y;
	}
	return (1);
}




