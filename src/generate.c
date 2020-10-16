/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:01:00 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/14 04:23:30 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_generate_player(t_game *jeu)
{
	int		size;
	int		s_pos;

	size = jeu->grid_box_size / 6;
	if (size < 1)
		size = 1;
	if (!ft_fill_imge(jeu->yah, ft_rgb_to_int(0, 0, 0, jeu->fog)))
		return (0);

//	printf("size: %d\n", size);

	// Absolutly needs to be (int) before multiply by img wid other wise small
	// diffs add up
	s_pos = ((jeu->me->pos.x * jeu->grid_box_size) - size / 2) + \
		(int)(jeu->me->pos.y * jeu->grid_box_size - size / 2) * jeu->yah->img_wid;
//		printf("pos: x %f, y %f, s_pos: %d\n", jeu->me->pos.x, jeu->me->pos.y, s_pos);

	if (!(ft_draw_box(jeu->yah, s_pos, size, ft_rgb_to_int(255, 0, 0, 0))))
		return (ft_error_msg("Failed to draw red player square in yah img\n", 0));	

	// now i call bresenham to make something...
	int		bres_spos;

	bres_spos = (jeu->me->pos.x * jeu->grid_box_size) + \
				(int)(jeu->me->pos.y * jeu->grid_box_size) * jeu->yah->img_wid;

	t_coords	left;	// left as in relative to the way the player is facing
	t_coords	right;

	left.x1 = jeu->me->pos.x * jeu->grid_box_size;
	left.y1 = jeu->me->pos.y * jeu->grid_box_size;
	// we are going to start by going out a dist of 1 box size
	// if we replace * grid_box_size with the dist to wall we should get what we want
	left.x2 = (jeu->me->pos.x + jeu->me->dir.x - jeu->me->plane.x) * jeu->grid_box_size;
	left.y2 = (jeu->me->pos.y + jeu->me->dir.y - jeu->me->plane.y) * jeu->grid_box_size;

	right.x1 = jeu->me->pos.x * jeu->grid_box_size;
	right.y1 = jeu->me->pos.y * jeu->grid_box_size;

	// we learned you can't just multiply it by 2 to make it the len of 2 gridboxes	
	// also currently the rays are actually longer than a gridbox...
	right.x2 = (jeu->me->pos.x + jeu->me->dir.x + jeu->me->plane.x) * jeu->grid_box_size;
	right.y2 = (jeu->me->pos.y + jeu->me->dir.y + jeu->me->plane.y) * jeu->grid_box_size;


	if (!ft_bresenham(jeu->yah, left, YELLOW))
		return (0);
	if (!ft_bresenham(jeu->yah, right, YELLOW))
		return (0);
	

	return (1);
}

	// makes the minimap, only called once...
int	ft_generate_minimap(t_game *jeu, t_level *lev)
{
	int	i;

//	ft_print_strtab(lev->floor);


	jeu->grid_box_size = ft_sizing_minimap_imge(jeu, lev);
	//	printf("s: %d, boxes x: %d, y: %d\n", jeu->grid_box_size, jeu->boxes.x, jeu->boxes.y);
	jeu->grid_pixs.x = jeu->grid_box_size * lev->dim.x;
	jeu->grid_pixs.y = jeu->grid_box_size * lev->dim.y;
		// no need to move by 5 cuz the 5 pix on all sides has already been factored in:)
	jeu->grid_tl.x = (jeu->file->res.x - jeu->grid_pixs.x) / 2;
	jeu->grid_tl.y = (jeu->file->res.y - jeu->grid_pixs.y) / 2;

	if (!(jeu->minimap = ft_create_imge(jeu->mlx, jeu->file->res.x, jeu->file->res.y)))
		return (0);
	i = 0;
	while (i < jeu->file->res.x)	// makes background dark
	{
		if (!ft_draw_col_to_imge(jeu->minimap, 0, jeu->file->res.y, i,
					ft_rgb_to_int(0, 0, 0, jeu->fog)))
			return (0);
		++i;
	}
	if (!ft_draw_grid(jeu, lev, jeu->minimap, jeu->grid_tl.x + jeu->grid_tl.y * jeu->file->res.x, jeu->grid_box_size))
		return (0);
	return (1);
}

	// secure !?
	// Also more like gen and display
int	ft_generate_fpv(t_game *jeu)
{
	if (!ft_raycasting(jeu))
		return (ft_error_msg("raycasting failed\n", 0));
	mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
			jeu->fpv->img_ptr, 0, 0);
	return (1);
}

	// will need to be broken up int multiple functions
int		ft_generate_crosshair(t_game *jeu)
{
	t_vect_i	thic;
	t_vect_i	len;
	t_vect_i	total;

	thic.x = 4;
	thic.y = 4;     // start with 4 thic, could do more...
	if (jeu->file->res.x % 2 == 1)
		--thic.x;
	if (jeu->file->res.y % 2 == 1)
		--thic.y;
	if (jeu->file->res.x < 1000)    // 1000 def better than 100
		thic.x -= 2;
	if (jeu->file->res.y < 1000)
		thic.y -= 2;
	// 250 pixels wide gets you 1 pix of crosshair
	len.x = 6 + jeu->file->res.x / 250;
	len.y = 6 + jeu->file->res.y / 250;
	total.x = len.x * 2 + thic.x;   // kinda unnessecary but clear...
	total.y = len.y * 2 + thic.y;
	if (!(jeu->crosshair = ft_create_imge(jeu->mlx, total.x, total.y)))
		return (0);
	// comment when testing
	if (!ft_fill_imge(jeu->crosshair, ft_rgb_to_int(0, 0, 0, 255)))
		return (0);
	// Top hash
	if (!ft_fill_rect(jeu->crosshair, (jeu->crosshair->img_wid - thic.x) / 2 , \
		thic.x, len.y, WHITE))
		return (0);
	// Left hash
	if (!ft_fill_rect(jeu->crosshair, \
		(jeu->crosshair->img_hei - thic.y) / 2 * jeu->crosshair->img_wid, \
		len.x, thic.y, WHITE))
		return (0);
	// Bottom hash
	if (!ft_fill_rect(jeu->crosshair, (jeu->crosshair->img_wid - thic.x) / 2 + \
		((jeu->crosshair->img_hei - thic.y) / 2 + thic.y) * jeu->crosshair->img_wid, \
		thic.x, len.y, WHITE))
		return (0);
	// Right hash
	if (!ft_fill_rect(jeu->crosshair, (jeu->crosshair->img_hei - thic.y) / 2 * \
		jeu->crosshair->img_wid + ((jeu->crosshair->img_wid - thic.x) / 2 + thic.x), \
		len.x, thic.y, WHITE))
		return (0);
	return (1);
}
