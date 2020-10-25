/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:09:23 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/24 19:23:29 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	ok so theres gonna be some shit where it scales based on the size...

*/


	// if # x boxes even and res x even, spacing even
	// if # x boxes even and res x odd, spacing odd
	// same for y

		// assuming htis is right, you can start from th middle
		// s is the size of the grid squares in pixels
int		ft_sizing_minimap_imge(t_game *jeu, t_level *lev)
{
	int		s;
	int		fit;

	s = 60;
	fit = 1;
	while (fit)
	{		// leave -10 for now...
		if (lev->dim.x * s < jeu->file->res.x - 10
			&& lev->dim.y * s < jeu->file->res.y - 10)
			fit = 0;
		else
			--s;
	}
	return (s);
}

	// secure obvi
int		ft_fill_imge(t_imge *img, int color)
{
	int		i;

	i = 0;
	while (i < img->last_pix)
	{
		(img->img_data)[i] = color;
		++i;
	}
	return (1);
}

	// where s_pos is the top left of the square, size is the leng of the square
int		ft_draw_box(t_imge *img, int s_pos, int size, int color)
{
	int		x;
	int		y;

//	printf("s_pos: %d, img last pix: %d\n", s_pos, img->last_pix);

	if (!img || s_pos < 0 || s_pos > img->last_pix - size * (img->img_wid))
		return (ft_error_msg("Draw Box conditions not met\n", 0));
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)	// we can improve this...
		{
			if (!ft_draw_pix_to_imge(img, s_pos + x + y * img->img_wid, color))
				return (ft_error_msg("Draw box failed to draw pix\n", 0));
			++x;
		}
		++y;
	}
	return (1);
}

		// do i need op if im already saying it based on the floor map ???
		// keep int so is more generic
		// yea so it's really not that generic, but could easily be so
int		ft_draw_grid(t_game *jeu, t_level *lev, t_imge *img, int t_left, int size)
{
	int		x;
	int		y;
	int		pos;
	int		color;


	ft_print_strtab(lev->floor);

	y = 0;
	while (lev->floor[y])
	{
		x = 0;
		while (lev->floor[y][x])	// need to fix so will skip empty spaces...
		{
			pos = t_left + size * (y * jeu->file->res.x + x);	// more efficient math
			if (lev->floor[y][x] == '1')						// if size * all
				color = ft_rgb_to_int(255, 255, 255, jeu->fog - 20);
			else if (lev->floor[y][x] == '0')
				color = ft_rgb_to_int(180, 180, 180, jeu->fog - 20);
			else							// - 20 so more contrast
				color = -1;
			if (color != -1 && !ft_draw_box(img, pos, size - 2, color))
				return (0);
			++x;
		}
		++y;
	}

	return (1);
}

int		ft_fill_rect(t_imge *img, int s_pos, int dimx, int dimy, int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < dimy)
	{
		x = 0;
		while (x < dimx)
		{
			if (!ft_draw_pix_to_imge(img, s_pos + x + y * img->img_wid, color))
				return (0);
			++x;
		}
		++y;
	}
	return (1);
}


