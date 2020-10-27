/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_to_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:00:17 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 21:06:13 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_display_crosshair(t_game *jeu)
{
	if (!jeu)
		return (0);
	mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
		jeu->crosshair->img_ptr, \
		(jeu->file->res.x - jeu->crosshair->img_wid) / 2, \
		(jeu->file->res.y - jeu->crosshair->img_hei) / 2);
	return (1);
}

int		ft_display_minimap(t_game *jeu)
{
	if (!jeu || !ft_generate_player(jeu))
		return (0);
	mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
		jeu->minimap->img_ptr, 0, 0);		// secure ? how
	mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
		jeu->yah->img_ptr, jeu->grid_tl.x, jeu->grid_tl.y);
	return (1);
}

int		ft_draw_imges(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (jeu->set->bonus && jeu->set->zoom)
		jeu->me->zoom_factor = 2;
	else
		jeu->me->zoom_factor = 1;
	if (jeu->lev->key_index != -1 && jeu->lev->key_exists
		&& !ft_move_sprite(jeu->lev, jeu->lev->key_index))
		return (ft_error_msg("Failed to move the key\n", 0));
	if (!ft_generate_fpv(jeu))
		return (0);
	if (jeu->set->bonus && jeu->set->minimap && !ft_display_minimap(jeu))
		return (ft_error_msg("Failed to display minimap\n", 0));
	if (jeu->set->bonus && !jeu->set->minimap && !ft_display_crosshair(jeu))
		return (ft_error_msg("Failed to display crosshair\n", 0));
	return (1);
}

int		ft_redraw(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (jeu->fpv->img_ptr)
		mlx_destroy_image(jeu->mlx->ptr, jeu->fpv->img_ptr);
	if (!(jeu->fpv->img_ptr = mlx_new_image(jeu->mlx->ptr,\
		jeu->fpv->img_wid, jeu->fpv->img_hei)))
		return (0);
	jeu->fpv->img_data = (int*)mlx_get_data_addr(jeu->fpv->img_ptr,\
		&jeu->mlx->bpp, &jeu->mlx->s_l, &jeu->mlx->endian);
	mlx_clear_window(jeu->mlx->ptr, jeu->win->win_ptr);
	if (!ft_draw_imges(jeu))
		return (0);
	return (1);
}

int		ft_casting(t_game *jeu)
{
	double	z_buffer[jeu->file->res.x];

	if (!jeu)
		return (0);
	if (jeu->set->bonus && jeu->file->floor->img && jeu->file->ceiling->img \
		&& !ft_floorcasting(jeu))
		return (ft_error_msg("failed to floorcast\n", 0));
//	if (!(z_buffer = malloc(sizeof(double) * jeu->file->res.x)))
//		return (0);
	if (!ft_raycasting(jeu, z_buffer))
	{
//		free(z_buffer);
		return (ft_error_msg("failed to raycast\n", 0));
	}
	if (!ft_spritecaster(jeu, z_buffer))
	{
//		free(z_buffer);
		return (ft_error_msg("failed to spritecast\n", 0));
	}
//	free(z_buffer);
	return (1);
}








