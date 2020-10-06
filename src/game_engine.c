/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 02:11:49 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/06 18:31:24 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
		jeu->minimap->img_ptr, 0, 0);		// secure ? how
	if (!ft_generate_player(jeu))
		return (0);
	mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
		jeu->yah->img_ptr, jeu->grid_tl.x, jeu->grid_tl.y);
	return (1);
}

	// Ok so might not end up being an init everything, but does create all the
	// mlx elems	

	// Not sure i love that this is where t_settings is malloced...
	// the init, may rename for clarity
int		ft_prime_engine(t_game *jeu)
{
	t_settings	*set;

	if (!(set = malloc(sizeof(t_settings))))
		return (0);

	if (!ft_init_settings(set))
		return (0);
//		return (ft_scott_free(&set, 0));	// can't scott_free set, it's not a string

	jeu->set = set;
	jeu->fog = 100;

	// also make the window and shit here i think ?
	if (!(jeu->win = ft_create_wind(jeu->mlx, "Map", jeu->file->res.x, jeu->file->res.y)))
		return (0);
//		return (ft_scott_free(&set, 0));

	if (!(jeu->fpv = ft_create_imge(jeu->mlx, jeu->file->res.x, jeu->file->res.y)))
		return (0);

	if (!ft_generate_minimap(jeu))
		return (ft_error_msg("Failed to generate minimap\n", 0));
//		return (ft_scott_free(&set, 0));
	if (!(jeu->yah = ft_create_imge(jeu->mlx, jeu->grid_pixs.x, jeu->grid_pixs.y)))
		return (0);
	if (!ft_generate_crosshair(jeu))
		return (0);

	mlx_hook(jeu->win->win_ptr, 6, 6L, &ft_capture_mouse_pos, jeu);

	return (1);
}

int		ft_draw_imges(t_game *jeu)
{
	// Is this also where i do the time thing ? i think no.

	if (!ft_generate_fpv(jeu))	// if just adding the minimap, don't need to redow the 
		return (0); // and prolly free something	// raycasting again!!!!

	// similarly do a display fpv ?

		// make sure this is in the mlx loop...
		// has to be after FPV i think, so is infront...

//	printf("settings: %d\n", jeu->settings);

	if (jeu->set->bonus == 1 && jeu->set->minimap == 1 && !ft_display_minimap(jeu))
		return (ft_error_msg("Failed to display minimap\n", 0));// maybe free something...
	if (jeu->set->bonus == 1 && jeu->set->minimap != 1 && !ft_display_crosshair(jeu))
		return (ft_error_msg("Failed to display crosshair\n", 0));

/*	if (jeu->set->bonus == 1 && jeu->set->minimap == 1 && !ft_display_minimap(jeu))
		return (ft_error_msg("Failed to display minimap\n", 0));// maybe free something...
	if (jeu->set->bonus == 1 && jeu->set->minimap != 1 && !ft_display_crosshair(jeu))
		return (ft_error_msg("Failed to display crosshair\n", 0));
*/
	return (1);
}

	// move this later
int		ft_keycodes(t_game *jeu)
{		// replace numbers with defines

	// would be so much nicer to do with a loop and a dedicated init func
	// but still have the .h problem where can't have cross referencing
	// structures...

	if (jeu->torch[13] && !ft_move_forward(jeu))
		return (0);
	if (jeu->torch[1] && !ft_move_backward(jeu))
		return (0);
	if (jeu->torch[0] && !ft_move_left(jeu))
		return (0);
	if (jeu->torch[2] && !ft_move_right(jeu))
		return (0);
	if (jeu->torch[123] && !ft_rot_left(jeu))
		return (0);
	if (jeu->torch[124] && !ft_rot_right(jeu))
		return (0);

						// keep this extra condition in mind for 
						// future butons
	if (jeu->torch[46] && jeu->set->bonus && !ft_toggle_on(&jeu->set->minimap))
		return (0);
	if (jeu->torch[45] && !ft_toggle_off(&jeu->set->minimap))
		return (0);
	if (jeu->torch[35] && !ft_toggle_on(&jeu->set->pause))
		return (0);
	if (jeu->torch[31] && !ft_toggle_off(&jeu->set->pause))
		return (0);
	if (jeu->torch[11] && !ft_toggle_on(&jeu->set->bonus))
		return (0);
	if (jeu->torch[9] && !ft_toggle_off(&jeu->set->bonus))
		return (0);

	if (jeu->torch[53] && !ft_quit(jeu))				// also change ???
		return (0);

// do rather like the redraw here rather than at the end of player command funcs

	// reason redraw is after things happening is so don't constantly redraw
	// only when something changes...
	// but could be good if we put sprite logic in here too...
	return (ft_redraw(jeu));
}


int		ft_game_engine(t_game *jeu)
{
	if (!ft_draw_imges(jeu))
		return (0);

	// if save we end it here


	// sleep(5);	// makes sleep for 5 seconds !!! an eternity
//	ft_hooks_loop(jeu);		// according to fractol this setup is fine...

	// do 1L and 2L do anything ???
	
			// was 1L and 2L
			// x_mask (1L and 2L and such) are not needed for MacOS but necessary for
			// Linux, is 17L correct ???
//	mlx_loop_hook(jeu->mlx->ptr, ft_redraw, jeu);
//	usleep(20000);	// doesnt seem to do anything
	// is there a way to record keypress length, if so use that to stabilize Map button
	mlx_hook(jeu->win->win_ptr, 2, 1L, &ft_keypress, jeu);
	mlx_hook(jeu->win->win_ptr, 3, 2L, &ft_keyrelease, jeu);
	mlx_hook(jeu->win->win_ptr, 6, 6L, &ft_mouse_move, jeu);
	mlx_hook(jeu->win->win_ptr, 17, 17L, &ft_quit, jeu);
//	ft_hooks_loop(jeu);	// one or the other, don't work at the same time...

	// will need this shit to constantly be updating especially if want the sprites to
	// keep moving even when player is still
	mlx_loop_hook(jeu->mlx->ptr, ft_keycodes, jeu);
	mlx_loop(jeu->mlx->ptr);	// will this work ???
	return (1);
}


