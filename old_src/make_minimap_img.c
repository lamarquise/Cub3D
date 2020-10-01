/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 23:37:28 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/19 23:44:51 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_place_player(t_game *jeu)
{
	int		pos;

	ft_fill_imge_with(jeu->fpv, 0xFF000000);

	pos = (int)((double)(U + G) * (jeu->me->x +\
			(double)jeu->minimap->img_wid * jeu->me->y));

	ft_draw_crosshairs(jeu->fpv, pos, C, 0xFF0000);
	return (1);
}

int		ft_get_floor_color(char indicator)
{
	int		color;
	// could add more colors if expand options...

	if (indicator == '1')
		color = 0xEEEEEE;
	else if (indicator == '0')
		color = 0x666666;
	else
		color = BLACK;
	return (color);
}

	// need a better name
int		ft_make_minimap_img(t_game *jeu)
{
	int		x;
	int		y;
	int		n;		// get rid of eventually

	x = 0;
	y = 0;
//	ft_fill_imge_with(jeu->minimap, 0xFF000000);
	while (y < jeu->y_boxes)
	{
		x = 0;
		while (x < jeu->x_boxes)
		{
			n = (G / 2) * (1 + jeu->minimap->img_wid) + (U + G) *\
				(x + y * jeu->minimap->img_wid);

			ft_draw_rect(jeu->minimap, n, U, U, \
				ft_get_floor_color(jeu->floor[y][x]));
			++x;
		}
		++y;
	}
	return (1);
}


