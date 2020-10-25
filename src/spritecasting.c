/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:23:54 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/24 20:15:06 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		ft_sort_sprites(int *spri_ord, double *spri_dist, int n_spris)
{
	int		j;
	int		sorted;
	int		tmp;
	double	tmp_dist;

	sorted = 1;
	while (sorted)
	{
		sorted = 0;
		j = 0;
		while (j < n_spris - 1)
		{
			if (spri_dist[j] < spri_dist[j + 1])
			{
				tmp_dist = spri_dist[j + 1];
				spri_dist[j + 1] = spri_dist[j];
				spri_dist[j] = tmp_dist;
				tmp = spri_ord[j + 1];
				spri_ord[j + 1]  = spri_ord[j];
				spri_ord[j] = tmp;
				sorted = 1;
			}
			++j;
		}
	}
	return (1);
}
	// we create and then calculate the order
int		*ft_calc_sprite_order(t_game *jeu)
{
	int		i;
	int		*spri_ord;	// index of the sprite in the spri tab
	double	*spri_dist;	// distance of that sprite from camera? player?

	if (!(spri_ord = (int*)malloc(sizeof(int) * jeu->lev->n_spris)))
		return ((int*)ft_error_msg("failed to allocate spri ord tab\n", 0));
	if (!(spri_dist = malloc(sizeof(double) * jeu->lev->n_spris)))
		return ((int*)ft_error_msg("failed to allocate spri dist tab\n", 0));

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
		return (NULL);
	return (spri_ord);
}


	// don't entirely (or at all) understand what transform does
	// but it's where the zoom factor needs to be for the sprites
	// to render properly...
	// wait no it's not...

t_vect_d	ft_calc_sprite_transform(t_game *jeu, int i, int *spri_ord)
{
	t_vect_d	transform;	// transform sprite with inverse camera matrix
				// gets us a vector representing the depth inside the screen
	t_vect_d	sprite_cp;	// sprite pos relative to camera
	double		inv_det;	// value require for matrix multiplication

	sprite_cp.x = jeu->lev->spris_tab[spri_ord[i]].pos.x - jeu->me->pos.x;
	sprite_cp.y = jeu->lev->spris_tab[spri_ord[i]].pos.y - jeu->me->pos.y;

	// Have to multiply all dir.'s by zoom factor, regardless of where they are

	inv_det = 1.0 / (jeu->me->plane.x * jeu->me->dir.y * jeu->me->zoom_factor \
			- jeu->me->plane.y * jeu->me->dir.x * jeu->me->zoom_factor);

	transform.x = inv_det * (jeu->me->dir.y * jeu->me->zoom_factor * sprite_cp.x \
				- jeu->me->dir.x * jeu->me->zoom_factor * sprite_cp.y);
	transform.y = inv_det * (-jeu->me->plane.y * sprite_cp.x \
				+ jeu->me->plane.x * sprite_cp.y);
	return (transform);
}

											// better if we send pointers ?
t_vect_i	ft_calc_sprite_dimentions(t_game *jeu, t_vect_d transform)
{
	t_vect_i	spri_d;

	if (transform.y != 0)
	{
		spri_d.y = abs((int)(jeu->file->res.y / (transform.y)));
		spri_d.x = abs((int)(jeu->file->res.y / (transform.y)));
	}
	else
	{
		spri_d.y = abs((int)jeu->file->res.y);
		spri_d.x = abs((int)jeu->file->res.y);
	}
	return (spri_d);
}




int			ft_calc_sprite_screen_x(t_game *jeu, t_vect_d transform)
{
	int		spri_screen_x;

	if (transform.y != 0)
		spri_screen_x = (int)((jeu->file->res.x / 2) \
			* (1 + transform.x / transform.y));
	else
		spri_screen_x = (int)((jeu->file->res.x / 2) * (1 + transform.x));
	return (spri_screen_x);
}

/*
int			ft_draw_sprite(t_game *jeu, t_vect_i spri_d, int spri_screen_x, int spri_hei)
{



}

*/

int			ft_spritecaster(t_game *jeu, double *z_buffer)
{
	int			i;
	int			*spri_ord;
	t_vect_d	transform;
	t_vect_i	spri_d;			// what is this ??? what does it represent
	int			spri_screen_x;	// what does this mean ???

	int			spri_hei;

	t_vect_i	draw_start;
	t_vect_i	draw_end;
//	int			sliver;		stripe will become sliver...


	spri_ord = NULL;
		// from this we get a table of ints coresponding to indexes of spris
		// in the spri table
	if (!(spri_ord = ft_calc_sprite_order(jeu)))
		return (ft_error_msg("failed to calc sprite order\n", 0));

/*	i = 0;
	while (i < jeu->lev->n_spris)
	{
		printf("spri ord [i]: %d\n", spri_ord[i]);
		++i;
	}
	printf("\n\n");
*/

	i = 0;
	while (i < jeu->lev->n_spris)
	{
		transform = ft_calc_sprite_transform(jeu, i, spri_ord);
			// i imagine this is not changed by zoom...
		spri_d = ft_calc_sprite_dimentions(jeu, transform);

		// call dir in ft_draw_sprite
		spri_screen_x = ft_calc_sprite_screen_x(jeu, transform);
		spri_hei = transform.y == 0 ? abs(jeu->file->res.y) : abs((int)(jeu->file->res.y / (transform.y)));

		draw_start.y = -spri_hei / 2 + jeu->file->res.y / 2;
		if(draw_start.y < 0)
			draw_start.y = 0;
		draw_end.y = spri_hei / 2 + jeu->file->res.y / 2;
		if(draw_end.y >= jeu->file->res.y)
			draw_end.y = jeu->file->res.y - 1;

		draw_start.x = -spri_hei / 2 + spri_screen_x;
		if(draw_start.x < 0)
			draw_start.x = 0;
		draw_end.x = spri_hei / 2 + spri_screen_x;
		if(draw_end.x >= jeu->file->res.x)
			draw_end.x = jeu->file->res.x - 1;


		t_imge	*tex_img;

		tex_img = jeu->lev->spris_tab[spri_ord[i]].tex->img;


		int 		stripe;
		t_vect_i	tex;
		int			y;
		int			d;	// no idea what it represents
		int			color;

		stripe = draw_start.x;

		while (stripe < draw_end.x)
		{
			
				// assuming 256 is the resolution we are anticipating
			tex.x = (int)(256 * (stripe - (-spri_hei / 2 + spri_screen_x)) \
					* tex_img->img_wid / spri_hei) / 256;

			if (transform.y > 0 && stripe > 0 && stripe < jeu->file->res.x \
				&& transform.y < z_buffer[stripe])
			{
				y = draw_start.y;
				while (y < draw_end.y)
				{
					d = y * 256 - jeu->file->res.y * 128 + spri_hei * 128;
					tex.y = ((d * tex_img->img_hei) / spri_hei) / 256;
					color = tex_img->img_data[tex_img->img_wid * tex.y + tex.x];

					if ((color & 0x00FFFFFF) != 0)
					{
						ft_draw_pix_to_imge(jeu->fpv, y * jeu->fpv->img_wid \
				+ stripe, color | jeu->lev->spris_tab[spri_ord[i]].anim_color << 16);
					}
					++y;
				}
			}
			++stripe;
		}
		if (jeu->lev->spris_tab[spri_ord[i]].anim_color > 0)
			jeu->lev->spris_tab[spri_ord[i]].anim_color -= 10;

//		ft_draw_sprite(jeu, spri_screen_x, );

		++i;
	}
	return (1);
}







