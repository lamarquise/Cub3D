/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 03:42:31 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 14:17:03 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect_i	ft_get_wall_texture(t_game *jeu, t_imge *tex_img, double pwd, \
			t_vect_d ray)
{
	double		wall_x;
	t_vect_i	w_texture;

	if (jeu->side == 0)
		wall_x = jeu->me->pos.y + pwd * ray.y;
	else
		wall_x = jeu->me->pos.x + pwd * ray.x;
	wall_x -= floor(wall_x);
	w_texture.x = (int)(wall_x * (double)tex_img->img_wid);
	if (jeu->side == 0 && ray.x > 0)
		w_texture.x = tex_img->img_wid - w_texture.x - 1;
	if (jeu->side == 1 && ray.y < 0)
		w_texture.x = tex_img->img_wid - w_texture.x - 1;
	return (w_texture);
}

t_vect_i	ft_calc_sliver_limits(t_game *jeu, int sliver_hei)
{
	t_vect_i	sliver_limits;

	sliver_limits.x = -sliver_hei / 2 + jeu->file->res.y / 2;
	if (sliver_limits.x < 0)
		sliver_limits.x = 0;
	sliver_limits.y = sliver_hei / 2 + jeu->file->res.y / 2;
	if (sliver_limits.y >= jeu->file->res.y)
		sliver_limits.y = jeu->file->res.y;
	return (sliver_limits);
}

int			ft_draw_fc(t_game *jeu, t_vect_i sliver_limits, int x)
{
	t_vect_i	row;

	if (!jeu)
		return (0);
	row.x = 0;
	row.y = sliver_limits.x;
	if (!ft_draw_col_to_imge(jeu->fpv, row, x, jeu->file->ceiling->value))
		return (ft_error_msg("failed to draw ceiling col to img\n", 0));
	row.x = sliver_limits.x;
	row.y = jeu->file->res.y;
	if (!ft_draw_col_to_imge(jeu->fpv, row, x, jeu->file->floor->value))
		return (ft_error_msg("failed to draw flo or cei col to img\n", 0));
	return (1);
}

int			ft_generate_wall_sliver(t_game *jeu, int x, double *pwd, \
			t_vect_d ray)
{
	t_vect_i	sliver_lims;
	t_vect_i	w_texture;
	double		tex_pos;
	t_imge		*t_img;

	if ((jeu->side = ft_shoot_ray(jeu, jeu->me->pos, ray, pwd)) == 0)
		t_img = (ray.x < 0 ? jeu->file->we->img : jeu->file->ea->img);
	else
		t_img = (ray.y < 0 ? jeu->file->no->img : jeu->file->so->img);
	sliver_lims = ft_calc_sliver_limits(jeu, (int)(jeu->file->res.y / *pwd));
	w_texture = ft_get_wall_texture(jeu, t_img, *pwd, ray);
	tex_pos = (sliver_lims.x - jeu->file->res.y / 2 + (int)(jeu->file->res.y \
		/ *pwd) / 2) * (1.0 * t_img->img_hei / (int)(jeu->file->res.x / *pwd));
	if (!jeu->file->floor->img && !jeu->file->ceiling->img \
		&& !ft_draw_fc(jeu, sliver_lims, x))
		return (0);
	while (sliver_lims.x < sliver_lims.y)
	{
		w_texture.y = (int)tex_pos & (t_img->img_hei - 1);
		tex_pos += 1.0 * t_img->img_hei / (int)(jeu->file->res.x / *pwd);
		ft_pix_imge(jeu->fpv, sliver_lims.x * jeu->fpv->img_wid + x, \
			t_img->img_data[t_img->img_hei * w_texture.y + w_texture.x]);
		++sliver_lims.x;
	}
	return (1);
}

int			ft_raycasting(t_game *jeu, double *z_buffer)
{
	int			x;
	t_vect_d	ray;
	double		perp_wall_dist;

	if (!jeu)
		return (0);
	x = 0;
	while (x < jeu->file->res.x)
	{
		ray.x = jeu->me->dir.x * jeu->me->zoom_factor + jeu->me->plane.x \
				* (2 * x / (double)jeu->file->res.x - 1);
		ray.y = jeu->me->dir.y * jeu->me->zoom_factor + jeu->me->plane.y \
				* (2 * x / (double)jeu->file->res.x - 1);
		if (!ft_generate_wall_sliver(jeu, x, &perp_wall_dist, ray))
			return (ft_error_msg("failed to generate wall sliver\n", 0));
		z_buffer[x] = perp_wall_dist;
		x++;
	}
	return (1);
}
