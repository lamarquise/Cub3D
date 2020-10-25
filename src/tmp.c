/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 03:42:31 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/18 17:48:53 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
int		ft_ray_dir(t_vect_i *step, t_vect_i *map_pos, t_vect_d *pos, \
			t_vect_d *side_dist, t_vect_d *ray_dir, t_vect_d *delta_dist)
{
		// Figure out why all this and what it means...
	if (ray_dir->x < 0)
	{
		step->x = -1;
		side_dist->x = (pos->x - map_pos->x) * delta_dist->x;
	}					// OG has these as negative
	else				// holy shit that fixed everything !!!!!
	{
		step->x = 1;
		side_dist->x = (map_pos->x + 1.0 - pos->x) * delta_dist->x;
	}
	if (ray_dir->y < 0)
	{
		step->y = -1;
		side_dist->y = (pos->y - map_pos->y) * delta_dist->y;
	}
	else
	{
		step->y = 1;
		side_dist->y = (map_pos->y + 1.0 - pos->y) * delta_dist->y;
	}

	return (1);
}
*/



int		ft_raycasting(t_game *jeu)
{
	int		col;
	int		c;
	int		row;
	int		r;


	t_level *lev;

	lev = (t_level*)jeu->level_list->content;

	col = jeu->file->res.x;
	row = jeu->file->res.y;

		// Makes the Background
	c = 0;
	r = 0;
	int		wall;
	int		floor_color;
	int		ceiling_color;
	wall = ft_rgb_to_int(255, 0, 0, 0);
//	printf("getting floor colors\n");

	// for some reason absolutely need to check if jeu->file->floor, not sure why
	if (jeu->file->floor && jeu->file->floor->path == NULL)
		floor_color = jeu->file->floor->value;
	if (jeu->file->ceiling && jeu->file->ceiling->path == NULL)
		ceiling_color = jeu->file->ceiling->value;
	while (c < col)
	{
		if (!ft_draw_col_to_imge(jeu->fpv, 0, jeu->file->res.y / 2, c, \
			ceiling_color))
			return (0);
		if (!ft_draw_col_to_imge(jeu->fpv, jeu->file->res.y / 2, \
			jeu->file->res.y, c, floor_color))
			return (0);
//		if (!ft_draw_col_to_imge(jeu->fpv, 200, 600, c, wall))
//			return (0);
		++c;
	}

//	printf("Player x: %f, y: %f\n", jeu->me->pos.x, jeu->me->pos.y);

	t_vect_d	pos;		// player pos	// was pos	// not p_pos
	t_vect_d	ray;	// was ray_dir

		// curr pos in map of ray being shot			
	t_vect_i	rpim;	// Ray Position In Map	// was Map_pos

		// dist ray travels from start pos in squar to 1st x and y side_seens
	t_vect_d	dts;	// Dist To Side			// Was side_dist
		// but represents something dif later in algo...

		// dist btw 2 x side_seens or 2 y side_seens, but not rectilinear & x/y components of each
		// not accounted for
	// so we have dbs.x is a distance in xy space, not the x component of one or
	// other
	t_vect_d	dbs;	// Dist Between Sides	// was delta_dist

		// the dir (+1 or -1 to rsd when shoting ray, stored for x and y components)
	t_vect_i	rsd;		// Ray Step Direction	// was step

		// Stores if NoSo side_seen hit or EaWe side_seen hit
	int			side_seen;		// was side
	double		perp_wall_dist;
	double		camera_x;	// coordinates in camera space

	pos.x = jeu->me->pos.x;		// used ?
	pos.y = jeu->me->pos.y;

	int				col_hei;
	int				draw_start;
	int				draw_end;
	
	int		color;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	pace;	// like rsd but that was already taken
	double	tex_pos;
	int		y;

	t_imge	*texture;		// rename later cuz an imge not a ttex


	// Ideas as to where the problem could be coming from:
	// Clearly not the thing that figures out the texture
	// could be a hit issue, could be the column maker, or the number of cols accounted
	// for

	int		f;

	f = 1;
	c = 0;
	while (c < col)
	{
//		printf("player pos x: %f, y %f\n", jeu->me->pos.x, jeu->me->pos.y);
		rpim.x = (int)jeu->me->pos.x;	// have to be here or segfault ????
		rpim.y = (int)jeu->me->pos.y;	// They are curr squar ray is in
//		printf("map pos x: %d, y %d\n", rpim.x, rpim.y);
		camera_x = 2 * c / (double)col - 1;	// weird cast...
		ray.x = jeu->me->dir.x * jeu->me->zoom_factor + jeu->me->plane.x * camera_x;
		ray.y = jeu->me->dir.y * jeu->me->zoom_factor + jeu->me->plane.y * camera_x;

		if (f == 0)
		{
			printf("raycasting ray x: %f, y:%f\n", ray.x, ray.y);
		}

//		printf("me pos x: %f", jeu->me->pos.x);
//		printf("raycasting test 1, map pos x: %d, y: %d\n", rpim.x, rpim.y);


		dbs = ft_calc_delta_dist(ray);

		// Call the Ray dir Function
		// to many arguments but we'll make it work later...
		// Works tho....
		ft_ray_dir(&rsd, &rpim, &pos, &dts, &ray, &dbs);
		

//		printf("side_seen distx: %f, y: %f\n", dts.x, dts.y);

//int		ft_dda(t_game *jeu, t_vect_i *rpim, t_vect_i *rsd, \
//					t_vect_d *dts, t_vect_d *dbs)

//		printf("rpim x: %d, y: %d\n", rpim.x, rpim.y);
//		printf("rsd x: %d, y: %d\n", rsd.x, rsd.y);
//		printf("dts x: %f, y: %f\n", dts.x, dts.y);
//		printf("dbs x: %f, y: %f\n", dbs.x, dbs.y);


		// we call the DDA Algorythm
		// Works

		printf("shoot pre dda map x: %d, y: %d\n", rpim.x, rpim.y);
		while (((char**)jeu->lev->floor)[rpim.y][rpim.x] != '1')
			side_seen = ft_dda(&rpim, &rsd, &dts, &dbs);
		printf("shoot post dda map x: %d, y: %d\n", rpim.x, rpim.y);

		// can we put these in the ft_DDA function ???


		if (f == 0)
		{
			printf("pre pwd: map x: %d, y: %d, p_pos x: %f, y: %f, step x: %d, y: %d, ray x: %f, y %f\n", rpim.x, rpim.y, pos.x, pos.y, rsd.x, rsd.y, ray.x, ray.y);
		}

		if (side_seen == 0)
				perp_wall_dist = (rpim.x - pos.x + (1 - rsd.x) / 2) / ray.x;
		else
				perp_wall_dist = (rpim.y - pos.y + (1 - rsd.y) / 2) / ray.y;

		if (f == 0)
		{
			printf("pwd: %f\n", perp_wall_dist);
			f = 1;
		}
		// At this point we have a distance and a ray direction

		



		// Now onto drawing the wall columns, i think...


		col_hei = (int)(jeu->file->res.y / perp_wall_dist);
		draw_start = -col_hei / 2 + jeu->file->res.y / 2;
		draw_end = col_hei / 2 + jeu->file->res.y / 2;
		if (draw_start < 0)
				draw_start = 0;
		if (draw_end >= jeu->file->res.y)
				draw_end = jeu->file->res.y;

		printf("col hei: %d, draw s: %d, e: %d\n", col_hei, draw_start, draw_end);

		// This does simple wall color
//		if (!ft_draw_col_to_imge(jeu->fpv, draw_start, draw_end, c, wall))
//				return (0);

		// Now add textures to wall cols
		// Seems to work just fine...

		if (side_seen == 0)
			wall_x = pos.y + perp_wall_dist * ray.y;
		else
			wall_x = pos.x + perp_wall_dist * ray.x;
		wall_x -= floor(wall_x);

	
			// do this whole bit in a sep func
		// could this rpim math be the reason the textures fuck up sometimes ?	
		texture = NULL;
		if (((char**)jeu->lev->floor)[rpim.y][rpim.x] == '1')
		{
			if (side_seen == 0)					// here we replace with linked list
				texture = (ray.x < 0 ? jeu->file->no->img : jeu->file->so->img);
			else
				texture = (ray.y < 0 ? jeu->file->we->img : jeu->file->ea->img);
		}
		else if (((char**)jeu->lev->floor)[rpim.y][rpim.x] == 'X')
		{
			texture = jeu->b_file->exit->img;
		}



//		if (!(texture = ft_select_tex(jeu, side_seen, ray, rpim)))
//			return (ft_error_msg("select texture failed\n", 0));

		// This shit is the same thing twice, is that a mistake ???
		// Doesn't seem like it, but still i don't understand this...
		tex_x = (int)(wall_x * (double)texture->img_wid);
		if (side_seen == 0 && ray.x > 0)
			tex_x = texture->img_wid - tex_x - 1;
		if (side_seen == 1 && ray.y < 0)
			tex_x = texture->img_wid - tex_x - 1;

		pace = 1.0 * texture->img_hei / col_hei;
		tex_pos = (draw_start - jeu->file->res.y / 2 + col_hei / 2) * pace;

//		tex_pos = (draw_start - jeu->file->res.y / 2 + (int)(jeu->file->res.y / 
//				perp_wall_dist) / 2) * (1.0 * texture->img_hei /
//				(int)(jeu->file->res.y / perp_wall_dist));

		y = draw_start;

		while (y < draw_end)
		{
			tex_y = (int)tex_pos & (texture->img_hei - 1);// im assuming -1 cuz start at 0
			tex_pos += pace;
			if (((char**)jeu->lev->floor)[rpim.y][rpim.x] == '1')
			{
				color = texture->img_data[texture->img_hei * tex_y + tex_x];
			}
			else
			{
				color = ft_rgb_to_int(255, 0, 0, 0);
			}
			ft_draw_pix_to_imge(jeu->fpv, y * jeu->fpv->img_wid + c, color);
			++y;
		}



		++c;
	}

	return (1);
}
