/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:09:23 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 04:28:48 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_sizing_minimap_imge(t_game *jeu, t_level *lev)
{
	int		s;
	int		fit;

	if (!jeu || !lev)
		return (-1);
	s = 60;
	fit = 1;
	while (fit)
	{
		if (lev->dim.x * s < jeu->file->res.x - 10
			&& lev->dim.y * s < jeu->file->res.y - 10)
			fit = 0;
		else
			--s;
	}
	return (s);
}

int		ft_fill_imge(t_imge *img, int color)
{
	int		i;

	if (!img)
		return (0);
	i = 0;
	while (i < img->last_pix)
	{
		(img->img_data)[i] = color;
		++i;
	}
	return (1);
}

int		ft_draw_box(t_imge *img, int s_pos, int size, int color)
{
	int		x;
	int		y;

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

int		ft_draw_grid(t_game *jeu, t_level *lev, t_imge *img, int t_left)
{
	int		x;
	int		y;
	int		pos;
	int		color;

	if (!jeu || !lev || !img || t_left < 0 || jeu->grid_box_size < 3)
		return (0);
	y = 0;
	while (lev->floor[y])
	{
		x = 0;
		while (lev->floor[y][x])
		{
			pos = t_left + jeu->grid_box_size * (y * jeu->file->res.x + x);
			if (lev->floor[y][x] == '1')
				color = ft_rgb_to_int(255, 255, 255, jeu->fog - 20);
			else if (lev->floor[y][x] == '0')
				color = ft_rgb_to_int(180, 180, 180, jeu->fog - 20);
			else
				color = -1;
			if (color != -1 && !ft_draw_box(img, pos, \
				jeu->grid_box_size - 2, color))
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

	if (!img || s_pos < 0 || s_pos > img->last_pix)
		return (ft_error_msg("failed to fill rect\n", 0));
	y = 0;
	while (y < dimy)
	{
		x = 0;
		while (x < dimx)
		{
			if (!ft_draw_pix_to_imge(img, s_pos + x + y * img->img_wid, color))
				return (ft_error_msg("failed to draw pix to img\n", 0));
			++x;
		}
		++y;
	}
	return (1);
}
