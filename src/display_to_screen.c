/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_to_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:00:17 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/14 04:23:44 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// secure all this shit !?

#include "cub3d.h"

int		ft_display_crosshair(t_game *jeu)
{
	mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
		jeu->crosshair->img_ptr, \
		(jeu->file->res.x - jeu->crosshair->img_wid) / 2, \
		(jeu->file->res.y - jeu->crosshair->img_hei) / 2);
	return (1);
}

int		ft_display_minimap(t_game *jeu)
{
	if (!ft_generate_player(jeu))
		return (0);
	mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
		jeu->minimap->img_ptr, 0, 0);		// secure ? how
	mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
		jeu->yah->img_ptr, jeu->grid_tl.x, jeu->grid_tl.y);
	return (1);
}

int		ft_display_title_screen(t_game *jeu)
{
	mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
		jeu->title_screen->img_ptr, 0, 0);		// secure ? how
	return (1);
}


int		ft_draw_imges(t_game *jeu)
{
	// Is this also where i do the time thing ? i think no.

	if (!ft_generate_fpv(jeu))
		return (0); // and prolly free something	// raycasting again!!!!

	if (jeu->set->bonus && jeu->set->minimap && !ft_display_minimap(jeu))
		return (ft_error_msg("Failed to display minimap\n", 0));// free something
	if (jeu->set->bonus && !jeu->set->minimap && !ft_display_crosshair(jeu))
		return (ft_error_msg("Failed to display crosshair\n", 0));

//	if (jeu->set->bonus && !ft_display_title_screen(jeu))
//		return (ft_error_msg("Failed to display title screen\n", 0));

//	mlx_string_put(jeu->mlx->ptr, jeu->win->win_ptr, 0, 0, ft_rgb_to_int(255, 0, 0, 0), "Testing");
//	sleep(1);


	return (1);
}

int		ft_redraw(t_game *jeu)
{
	// none of that gets done to player, maybe i don't need it for fpv ?

	if (jeu->fpv->img_ptr)
		mlx_destroy_image(jeu->mlx->ptr, jeu->fpv->img_ptr);
	if (!(jeu->fpv->img_ptr = mlx_new_image(jeu->mlx->ptr,\
		jeu->fpv->img_wid, jeu->fpv->img_hei)))
		return (0);
	jeu->fpv->img_data = (int*)mlx_get_data_addr(jeu->fpv->img_ptr,\
		&jeu->mlx->bpp, &jeu->mlx->s_l, &jeu->mlx->endian);

	mlx_clear_window(jeu->mlx->ptr, jeu->win->win_ptr);		 // secure ???
	if (!ft_draw_imges(jeu))
		return (0);
	return (1);
}


