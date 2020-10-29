/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:01:00 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 23:49:20 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_generate_fpv(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (!ft_casting(jeu))
		return (ft_error_msg("raycasting failed\n", 0));
	mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
			jeu->fpv->img_ptr, 0, 0);
	return (1);
}

int		ft_draw_crosshair(t_game *jeu, t_vect_i thic, t_vect_i len)
{
	if (!jeu)
		return (0);
	if (!ft_fill_imge(jeu->crosshair, ft_rgb_to_int(0, 0, 0, 255)))
		return (ft_error_msg("failed to fill image with blank\n", 0));
	if (!ft_fill_rect(jeu->crosshair, (jeu->crosshair->img_wid - thic.x) \
		/ 2, ft_fill_vect_i(thic.x, len.y), WHITE))
		return (0);
	if (!ft_fill_rect(jeu->crosshair, \
		(jeu->crosshair->img_hei - thic.y) / 2 \
		* jeu->crosshair->img_wid, ft_fill_vect_i(len.x, thic.y), WHITE))
		return (0);
	if (!ft_fill_rect(jeu->crosshair, (jeu->crosshair->img_wid - thic.x) / 2 + \
		((jeu->crosshair->img_hei - thic.y) / 2 + thic.y) \
		* jeu->crosshair->img_wid, ft_fill_vect_i(thic.x, len.y), WHITE))
		return (0);
	if (!ft_fill_rect(jeu->crosshair, (jeu->crosshair->img_hei - thic.y) / 2 * \
		jeu->crosshair->img_wid + ((jeu->crosshair->img_wid - thic.x) / 2 \
		+ thic.x), ft_fill_vect_i(len.x, thic.y), WHITE))
		return (0);
	return (1);
}

int		ft_generate_crosshair(t_game *jeu)
{
	t_vect_i	thic;
	t_vect_i	len;
	t_vect_i	total;

	thic.x = 4;
	thic.y = 4;
	if (jeu->file->res.x % 2 == 1)
		--thic.x;
	if (jeu->file->res.y % 2 == 1)
		--thic.y;
	if (jeu->file->res.x < 1000)
		thic.x -= 2;
	if (jeu->file->res.y < 1000)
		thic.y -= 2;
	len.x = 6 + jeu->file->res.x / 250;
	len.y = 6 + jeu->file->res.y / 250;
	total.x = len.x * 2 + thic.x;
	total.y = len.y * 2 + thic.y;
	if (!(jeu->crosshair = ft_create_imge(jeu->mlx, total.x, total.y)))
		return (0);
	if (!ft_draw_crosshair(jeu, thic, len))
		return (ft_error_msg("failed to draw crosshair\n", 0));
	return (1);
}
