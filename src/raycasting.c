/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 03:42:31 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/16 04:05:40 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// ok so we're saying we've already done the math to translate x,y 2D coords to
	// 1D table coords
	// could do x and y rather than pos if wanted cuz have img wid & hei...
	// leave for now
int		ft_draw_pix_to_imge(t_imge *img, int pos, int color)
{
	if (!img || pos < 0 || pos >= img->last_pix)// last_pix + 1? + y ? not sure, best no
		return (0);
	(img->img_data)[pos] = color;
	return (1);
}

int		ft_draw_col_to_imge(t_imge *img, int start_row, int end_row, int col, int color)
{
	int		pos;

	if (!img || start_row < 0 || end_row > img->img_hei)
		return (0);
	while (start_row < end_row)
	{
		pos = col + start_row * img->img_wid;
		if (!ft_draw_pix_to_imge(img, pos, color))
			return (0);
		++start_row;
	}
	return (1);
}

	// do with Ternairs ????

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


	// Digital Differencial Algorythm, DDA,
/*			// just for testing elems of DDA individually
int		ft_test_dda(t_vect_i *map_pos, t_vect_i *step, \
					t_vect_d *side_dist, t_vect_d *delta_dist)
{
	int		side;

		if (side_dist->x < side_dist->y)
		{
			side_dist->x += delta_dist->x;
			map_pos->x += step->x;
			side = 0;
		}
		else
		{
			side_dist->y += delta_dist->y;
			map_pos->y += step->y;
			side = 1;
		}
	
	return (side);
}
*/

int		ft_dda(t_game *jeu, t_vect_i *map_pos, t_vect_i *step, \
					t_vect_d *side_dist, t_vect_d *delta_dist)
{
	int		hit;
	int		side;
	int		i;

//	printf("dda print tab\n");
//	ft_print_strtab(jeu->lev->floor);

	side = 0;
	hit = 0;
	i = 0;			// i did not improve things...
//	while (hit == 0 && i < 100)
	while (hit == 0)
	{
//		side = ft_test_dda(map_pos, step, side_dist, delta_dist);

//		printf("dda test 1, map pos x: %d, y: %d\n", map_pos->x, map_pos->y);

		if (side_dist->x < side_dist->y)
		{
			side_dist->x += delta_dist->x;
			map_pos->x += step->x;
			side = 0;
		}
		else
		{
			side_dist->y += delta_dist->y;
			map_pos->y += step->y;
			side = 1;
		}
//		printf("dda test 2\n");

		if (((char**)jeu->lev->floor)[map_pos->y][map_pos->x] != '0')
			hit = 1;
//		printf("dda test 3\n");
//		++i;
	}
	return (side);
}

/*				// may eventually be useful for sprite rendering...
	// secure obvi
t_imge		*ft_select_tex_nlist_elem(t_nlist *list, int value)
{
	t_nlist		*tmp;
	t_texture	*tex;

	tmp = list;
	tex = NULL;
	while (tmp)
	{
		tex = (t_texture*)tmp->content;
		if (tex->value == value)
			return (tex->img);
		tmp = tmp->next;
	}
	return (NULL);
}


t_imge		*ft_select_tex(t_game *jeu, int side, t_vect_d ray_dir, t_vect_i map_pos)
{
	if (((char**)jeu->lev->floor)[map_pos.y][map_pos.x] == '1')
	{
		if (side == 0)					// here we replace with linked list
		{
			if (ray_dir.x < 0)
				return (ft_select_tex_nlist_elem(jeu->file->tex_list, 0));
			else
				return (ft_select_tex_nlist_elem(jeu->file->tex_list, 1));
		}
		else
		{
			if (ray_dir.y < 0)
				return (ft_select_tex_nlist_elem(jeu->file->tex_list, 2));
			else
				return (ft_select_tex_nlist_elem(jeu->file->tex_list, 3));
		}
	}
	else if (((char**)jeu->lev->floor)[map_pos.y][map_pos.x] == '2')	// need a way to expand easier
	{
		return (ft_select_tex_nlist_elem(jeu->file->tex_list, 4));
	}
	return (NULL);
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


	// need way better names

	t_vect_d	pos;
	t_vect_d	ray_dir;
	t_vect_i	map_pos;
		// dist_next_side
	t_vect_d	side_dist;	// What are these, what is side_dist, delta_dist and step
		// dist between an x side and next x side, same for y
	t_vect_d	delta_dist;	// what do they represent ???
	t_vect_i	step;		// dir to step in x and y, +1 or -1

	int			side;		// was a NS side hit or EW
	double		perp_wall_dist;
	double		cameraX;	// coordinates in camera space

	pos.x = jeu->me->pos.x;
	pos.y = jeu->me->pos.y;

	int				col_hei;
	int				draw_start;
	int				draw_end;
	
	int		color;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	pace;	// like step but that was already taken
	double	tex_pos;
	int		y;

	t_imge	*texture;		// rename later cuz an imge not a ttex


	// Ideas as to where the problem could be coming from:
	// Clearly not the thing that figures out the texture
	// could be a hit issue, could be the column maker, or the number of cols accounted
	// for

	c = 0;
	while (c < col)
	{
		map_pos.x = (int)jeu->me->pos.x;	// have to be here or segfault ????
		map_pos.y = (int)jeu->me->pos.y;	// no idea why
		cameraX = 2 * c / (double)col - 1;	// weird cast...
		ray_dir.x = jeu->me->dir.x + jeu->me->plane.x * cameraX;
		ray_dir.y = jeu->me->dir.y + jeu->me->plane.y * cameraX;


//		printf("me pos x: %f", jeu->me->pos.x);
//		printf("raycasting test 1, map pos x: %d, y: %d\n", map_pos.x, map_pos.y);


		// Not ideal, ternairs imbriques...
		delta_dist.x = (ray_dir.y == 0) ? 0 : ((ray_dir.x == 0) ? 1 : fabs(1 / ray_dir.x));
		delta_dist.y = (ray_dir.x == 0) ? 0 : ((ray_dir.y == 0) ? 1 : fabs(1 / ray_dir.y));

		// Call the Ray dir Function
		// to many arguments but we'll make it work later...
		// Works tho....
		ft_ray_dir(&step, &map_pos, &pos, &side_dist, &ray_dir, &delta_dist);
		

//		printf("side distx: %f, y: %f\n", side_dist.x, side_dist.y);

//int		ft_dda(t_game *jeu, t_vect_i *map_pos, t_vect_i *step, \
//					t_vect_d *side_dist, t_vect_d *delta_dist)

//		printf("map_pos x: %d, y: %d\n", map_pos.x, map_pos.y);
//		printf("step x: %d, y: %d\n", step.x, step.y);
//		printf("side_dist x: %f, y: %f\n", side_dist.x, side_dist.y);
//		printf("delta_dist x: %f, y: %f\n", delta_dist.x, delta_dist.y);


		// we call the DDA Algorythm
		// Works
		side = ft_dda(jeu, &map_pos, &step, &side_dist, &delta_dist);

		// can we put these in the ft_DDA function ???
		if (side == 0)
				perp_wall_dist = (map_pos.x - pos.x + (1 - step.x) / 2) / ray_dir.x;
		else
				perp_wall_dist = (map_pos.y - pos.y + (1 - step.y) / 2) / ray_dir.y;


		// At this point we have a distance and a ray direction

		



		// Now onto drawing the wall columns, i think...


		col_hei = (int)(jeu->file->res.y / perp_wall_dist);
		draw_start = -col_hei / 2 + jeu->file->res.y / 2;
		draw_end = col_hei / 2 + jeu->file->res.y / 2;
		if (draw_start < 0)
				draw_start = 0;
		if (draw_end >= jeu->file->res.y)
				draw_end = jeu->file->res.y;

		// This does simple wall color
//		if (!ft_draw_col_to_imge(jeu->fpv, draw_start, draw_end, c, wall))
//				return (0);

		// Now add textures to wall cols
		// Seems to work just fine...

		if (side == 0)
			wall_x = pos.y + perp_wall_dist * ray_dir.y;
		else
			wall_x = pos.x + perp_wall_dist * ray_dir.x;
		wall_x -= floor(wall_x);

	
			// do this whole bit in a sep func
		// could this map_pos math be the reason the textures fuck up sometimes ?	
		texture = NULL;
		if (((char**)jeu->lev->floor)[map_pos.y][map_pos.x] == '1')
		{
			if (side == 0)					// here we replace with linked list
				texture = (ray_dir.x < 0 ? jeu->file->no->img : jeu->file->so->img);
			else
				texture = (ray_dir.y < 0 ? jeu->file->we->img : jeu->file->ea->img);
		}
		else if (((char**)jeu->lev->floor)[map_pos.y][map_pos.x] == 'X')
		{
			texture = jeu->b_file->exit->img;
		}



//		if (!(texture = ft_select_tex(jeu, side, ray_dir, map_pos)))
//			return (ft_error_msg("select texture failed\n", 0));

		// This shit is the same thing twice, is that a mistake ???
		// Doesn't seem like it, but still i don't understand this...
		tex_x = (int)(wall_x * (double)texture->img_wid);
		if (side == 0 && ray_dir.x > 0)
			tex_x = texture->img_wid - tex_x - 1;
		if (side == 1 && ray_dir.y < 0)
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
			if (((char**)jeu->lev->floor)[map_pos.y][map_pos.x] == '1')
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


