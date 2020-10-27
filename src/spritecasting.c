/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:23:54 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 21:41:20 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_sort_sprites(int *spri_ord, double *spri_dist, int n_spris)
{
	int		j;
	int		sorted;
	int		tmp;
	double	tmp_dist;

	sorted = 1;
	while (sorted)
	{
		sorted = 0;
		j = -1;
		while (++j < n_spris - 1)
		{
			if (spri_dist[j] < spri_dist[j + 1])
			{
				tmp_dist = spri_dist[j + 1];
				spri_dist[j + 1] = spri_dist[j];
				spri_dist[j] = tmp_dist;
				tmp = spri_ord[j + 1];
				spri_ord[j + 1] = spri_ord[j];
				spri_ord[j] = tmp;
				sorted = 1;
			}
		}
	}
	return (1);
}

int			ft_calc_sprite_order(t_game *jeu, int *spri_ord)
{
	int		i;
	double	spri_dist[jeu->lev->n_spris];

	i = 0;
	while (i < jeu->lev->n_spris)
	{
		spri_ord[i] = i;
		spri_dist[i] = ((jeu->me->pos.x - jeu->lev->spris_tab[i].pos.x) \
						* (jeu->me->pos.x - jeu->lev->spris_tab[i].pos.x) \
						+ (jeu->me->pos.y - jeu->lev->spris_tab[i].pos.y) \
						* (jeu->me->pos.y - jeu->lev->spris_tab[i].pos.y));
		++i;
	}
	if (!(ft_sort_sprites(spri_ord, spri_dist, jeu->lev->n_spris)))
		return (0);
//	free(spri_dist);
	return (1);
}

t_vect_d	ft_calc_sprite_transform(t_game *jeu, int i, int *spri_ord)
{
	t_vect_d	tran;
	t_vect_d	sprite_cp;
	double		inv_det;

	sprite_cp.x = jeu->lev->spris_tab[spri_ord[i]].pos.x - jeu->me->pos.x;
	sprite_cp.y = jeu->lev->spris_tab[spri_ord[i]].pos.y - jeu->me->pos.y;
	inv_det = 1.0 / (jeu->me->plane.x * jeu->me->dir.y * jeu->me->zoom_factor \
			- jeu->me->plane.y * jeu->me->dir.x * jeu->me->zoom_factor);
	tran.x = inv_det * (jeu->me->dir.y * jeu->me->zoom_factor * sprite_cp.x \
				- jeu->me->dir.x * jeu->me->zoom_factor * sprite_cp.y);
	tran.y = inv_det * (-jeu->me->plane.y * sprite_cp.x \
				+ jeu->me->plane.x * sprite_cp.y);
	return (tran);
}

int			ft_calc_sprite_screen_x(t_game *jeu, t_vect_d *tran)
{
	int		spri_screen_x;

	if (tran->y != 0)
		spri_screen_x = (int)((jeu->file->res.x / 2) \
			* (1 + tran->x / tran->y));
	else
		spri_screen_x = (int)((jeu->file->res.x / 2) * (1 + tran->x));
	return (spri_screen_x);
}

t_vect_t	ft_calc_draw_dims(t_game *jeu, t_vect_t *spri_dims, t_vect_d *tran)
{
	t_vect_t	draw;

	spri_dims->a.x = ft_calc_sprite_screen_x(jeu, tran);
	spri_dims->a.y = tran->y == 0 ? abs(jeu->file->res.y) \
			: abs((int)(jeu->file->res.y / (tran->y)));
	draw.a.y = -spri_dims->a.y / 2 + jeu->file->res.y / 2;
	if (draw.a.y < 0)
		draw.a.y = 0;
	draw.b.y = spri_dims->a.y / 2 + jeu->file->res.y / 2;
	if (draw.b.y >= jeu->file->res.y)
		draw.b.y = jeu->file->res.y - 1;
	draw.a.x = -spri_dims->a.y / 2 + spri_dims->a.x;
	if (draw.a.x < 0)
		draw.a.x = 0;
	draw.b.x = spri_dims->a.y / 2 + spri_dims->a.x;
	if (draw.b.x >= jeu->file->res.x)
		draw.b.x = jeu->file->res.x - 1;
	return (draw);
}

	// see calc sliver limits

int			ft_spritecaster(t_game *jeu, double *z_buffer)
{
	int			i;
	int			spri_ord[jeu->lev->n_spris];
	t_vect_d	transform;

	t_vect_t	spri_dims;	//hei(y) and screen x(x)


	if (!jeu || !z_buffer)
		return (0);
	if (!(ft_calc_sprite_order(jeu, spri_ord)))
		return (ft_error_msg("failed to calc sprite order\n", 0));
	i = 0;
	while (i < jeu->lev->n_spris)
	{
		transform = ft_calc_sprite_transform(jeu, i, spri_ord);

		spri_dims.b.x = spri_ord[i];

		ft_draw_sprite(jeu, &spri_dims, z_buffer, &transform);

		if (jeu->lev->spris_tab[spri_ord[i]].anim_color > 0)
			jeu->lev->spris_tab[spri_ord[i]].anim_color -= 10;
		++i;
	}
	return (1);
}

void		ft_draw_sprite(t_game *jeu, t_vect_t *s, double *z, t_vect_d *tr)
{
	t_vect_t	t;
	t_vect_t	dr;
	t_imge		*i;

	i = jeu->lev->spris_tab[s->b.x].tex->img;
	dr = ft_calc_draw_dims(jeu, s, tr);
	while (++dr.a.x - 1 < dr.b.x)
	{
		t.a.x = (int)(256 * (dr.a.x - (-s->a.y / 2 + s->a.x)) \
			* i->img_wid / s->a.y) / 256;
		if (tr->y > 0 && dr.a.x > 0 && dr.a.x < jeu->file->res.x \
			&& tr->y < z[dr.a.x])
		{
			t.b.y = dr.a.y - 1;
			while (++t.b.y < dr.b.y)
			{
				t.a.y = (((t.b.y * 256 - jeu->file->res.y * 128 + s->a.y \
						* 128) * i->img_hei) / s->a.y) / 256;
				t.b.x = i->img_data[i->img_wid * t.a.y + t.a.x];
				if ((t.b.x & 0x00FFFFFF))
					ft_pix_imge(jeu->fpv, t.b.y * jeu->fpv->img_wid + dr.a.x, \
						t.b.x | jeu->lev->spris_tab[s->b.x].anim_color << 16);
			}
		}
	}
}


/*	t_vect_i	t;
	t_vect_i	c;
	t_vect_t	dr;
	t_imge		*i;

	i = jeu->lev->spris_tab[s->b.x].tex->img;
	dr = ft_calc_draw_dims(jeu, s, tr);
	while (++dr.a.x - 1 < dr.b.x)
	{
		t.x = (int)(256 * (dr.a.x - (-s->a.y / 2 + s->a.x)) \
			* i->img_wid / s->a.y) / 256;
		if (tr->y > 0 && dr.a.x > 0 && dr.a.x < jeu->file->res.x \
			&& tr->y < z[dr.a.x])
		{
			c.y = dr.a.y - 1;
			while (++c.y < dr.b.y)
			{
				t.y = (((c.y * 256 - jeu->file->res.y * 128 + s->a.y \
						* 128) * i->img_hei) / s->a.y) / 256;
				c.x = i->img_data[i->img_wid * t.y + t.x];
				if ((c.x & 0x00FFFFFF))
					ft_pix_imge(jeu->fpv, c.y * jeu->fpv->img_wid + dr.a.x, \
						c.x | jeu->lev->spris_tab[s->b.x].anim_color << 16);

			}
		}
	}
*/
/*	tex_img = jeu->lev->spris_tab[spri_dims->b.x].tex->img;
	draw = ft_calc_draw_dims(jeu, spri_dims, transform);
	loop.x = draw.a.x - 1;
	while (++loop.x < draw.b.x)
	{
		tex.x = (int)(256 * (loop.x - (-spri_dims->a.y / 2 + spri_dims->a.x)) \
				* tex_img->img_wid / spri_dims->a.y) / 256;
		if (transform->y > 0 && loop.x > 0 && loop.x < jeu->file->res.x \
			&& transform->y < z_buffer[loop.x])
		{
			loop.y = draw.a.y - 1;
			while (++loop.y < draw.b.y)
			{
				tex.y = (((loop.y * 256 - jeu->file->res.y * 128 + spri_dims->a.y \
						* 128) * tex_img->img_hei) / spri_dims->a.y) / 256;
				color = tex_img->img_data[tex_img->img_wid * tex.y + tex.x];
				if ((color & 0x00FFFFFF) != 0)
					ft_draw_pix_to_imge(jeu->fpv, loop.y * jeu->fpv->img_wid \
						+ loop.x, color | jeu->lev->spris_tab[spri_dims->b.x]\
						.anim_color << 16);
			}
		}
	}
*/

