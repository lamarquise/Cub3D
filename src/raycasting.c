/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 03:42:31 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/24 20:20:34 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect_i	ft_get_wall_texture(t_game *jeu, t_imge *tex_img, double pwd, \
			t_vect_d ray, int side)
{
	double		wall_x;	// the exact pos in map box where ray hit wall, x coord of wall
	t_vect_i	w_texture;	// the int/pix coord where ray hit texture
							// this func just finds x value, all ys calculated later
								// to draw col
	if (side == 0)
		wall_x = jeu->me->pos.y + pwd * ray.y;
	else
		wall_x = jeu->me->pos.x + pwd * ray.x;

		// so we take the a.b and subract a leaving 0.b
	wall_x -= floor(wall_x);
	w_texture.x = (int)(wall_x * (double)tex_img->img_wid);
	if (side == 0 && ray.x > 0)
		w_texture.x = tex_img->img_wid - w_texture.x - 1;
	if (side == 1 && ray.y < 0)
		w_texture.x = tex_img->img_wid - w_texture.x - 1;
	return (w_texture);
}

	// make generic and reuse for sprite sliver calcs
	// used to calculate the sliver start and sliver end for the line of wall
t_vect_i	ft_calc_sliver_limits(t_game *jeu, int sliver_hei)
{
	t_vect_i	sliver_limits;

//	printf("calc sliver lim, sliver hei: %d\n", sliver_hei);

	sliver_limits.x = -sliver_hei / 2 + jeu->file->res.y / 2;
	if (sliver_limits.x < 0)
		sliver_limits.x = 0;
	sliver_limits.y = sliver_hei / 2 + jeu->file->res.y / 2;
	if (sliver_limits.y >= jeu->file->res.y)
		sliver_limits.y = jeu->file->res.y;
	return (sliver_limits);
}

			// x is the screen col
int		ft_generate_wall_sliver(t_game *jeu, int x, double *pwd, t_vect_d ray)
{
	t_vect_i	sliver_limits;	// like start and end
	int			color;
	t_vect_i	w_texture;
	double		tex_pos;
	t_imge		*tex_img;
	int			side;

	if ((side = ft_shoot_ray(jeu, jeu->me->pos, ray, pwd)) == 0)
		tex_img = (ray.x < 0 ? jeu->file->no->img : jeu->file->so->img);
	else
		tex_img = (ray.y < 0 ? jeu->file->we->img : jeu->file->ea->img);

//	printf("wall sliver pwd: %f\n", *pwd);

	sliver_limits = ft_calc_sliver_limits(jeu, (int)(jeu->file->res.y / *pwd));
	w_texture = ft_get_wall_texture(jeu, tex_img, *pwd, ray, side);
	tex_pos = (sliver_limits.x - jeu->file->res.y / 2 + (int)(jeu->file->res.y / \
		*pwd) / 2) * (1.0 * tex_img->img_hei / (int)(jeu->file->res.x / *pwd));


//	printf("sliver limits x: %d, y: %d\n", sliver_limits.x, sliver_limits.y);

	if (!jeu->file->floor->img && !jeu->file->ceiling->img \
		&& (!ft_draw_col_to_imge(jeu->fpv, 0, sliver_limits.x, x, \
		jeu->file->ceiling->value) || !ft_draw_col_to_imge(jeu->fpv, \
		sliver_limits.y, jeu->file->res.y, x, jeu->file->floor->value)))
		return (ft_error_msg("failed to draw floor or ceiling col to img\n", 0));

//	printf("drawing cols test\n");

	while (sliver_limits.x < sliver_limits.y)
	{
		w_texture.y = (int)tex_pos & (tex_img->img_hei - 1);
		tex_pos += 1.0 * tex_img->img_hei / (int)(jeu->file->res.x / *pwd);
		color = tex_img->img_data[tex_img->img_hei * w_texture.y + w_texture.x];
		ft_draw_pix_to_imge(jeu->fpv, sliver_limits.x * jeu->fpv->img_wid + x, color);
		++sliver_limits.x;
	}
	return (1);
}

int		ft_raycasting(t_game *jeu)
{
	int			x;
	t_vect_d	ray;
	double		perp_wall_dist;
	double		*z_buffer;

	// time = getTicks();

	if (!(z_buffer = malloc(sizeof(double) * jeu->file->res.x)))
		return (0);

	// might have to do floor and ceiling textureing here

	if (jeu->set->bonus && jeu->file->floor->img && jeu->file->ceiling->img)
		ft_floorcasting(jeu);

	x = 0;
	while (x < jeu->file->res.x)
	{
		ray.x = jeu->me->dir.x * jeu->me->zoom_factor + jeu->me->plane.x \
				* (2 * x / (double)jeu->file->res.x - 1);
		ray.y = jeu->me->dir.y * jeu->me->zoom_factor + jeu->me->plane.y \
				* (2 * x / (double)jeu->file->res.x - 1);
		if (!ft_generate_wall_sliver(jeu, x, &perp_wall_dist, ray))
			return (ft_error_msg("failed to raycast\n", 0));
		z_buffer[x] = perp_wall_dist;
		x++;
	}
	ft_spritecaster(jeu, z_buffer);
	return (1);
}

