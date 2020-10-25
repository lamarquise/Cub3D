/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 02:11:49 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/26 00:16:09 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_prime_level(t_game *jeu, t_level *lev)
{
	jeu->lev = lev;
	ft_init_player(jeu, lev);

	printf("prime level, is bonus %d\n", jeu->set->bonus);

	if (!(jeu->fpv = ft_create_imge(jeu->mlx, jeu->file->res.x, jeu->file->res.y)))
		return (0);
	if (!(jeu->yah = ft_create_imge(jeu->mlx, jeu->grid_pixs.x, jeu->grid_pixs.y)))
		return (0);

	if (!ft_generate_minimap(jeu, lev))
		return (ft_error_msg("Failed to generate minimap\n", 0));
//		return (ft_scott_free(&set, 0));
	// has to be after generate minimap cuz we set grid pix and stuff there
	if (!(jeu->yah = ft_create_imge(jeu->mlx, jeu->grid_pixs.x, jeu->grid_pixs.y)))
		return (0);
	if (!ft_generate_crosshair(jeu))
		return (0);

//	if (jeu->set->bonus && !(jeu->title_screen = ft_create_imge(jeu->mlx, \
//		jeu->file->res.x, jeu->file->res.y)))
//		return (ft_error_msg("Failed to create title screen imge\n", 0));


		// this fucks all the mouse move after the first level up... *hands up shrug*
//	mlx_hook(jeu->win->win_ptr, 6, 6L, &ft_capture_mouse_pos, jeu);

	jeu->mouse.x = 0;
	jeu->mouse.y = 0;

//	printf("prime level mouse x: %d, y: %d\n", jeu->mouse.x, jeu->mouse.y);

	return (1);
}

/*
int		ft_prime_engine(t_game *jeu)
{
	jeu->fog = 100;
	if (!(jeu->win = ft_create_wind(jeu->mlx, "Cub3D", \
		jeu->file->res.x, jeu->file->res.y)))
		return (0);
//		return (ft_scott_free(&set, 0));
	return (1);
}
*/

int		ft_set_level(t_game *jeu)
{
	int		i;
	t_level	*lev;
	t_nlist	*tmp;

	// we could start this function off by wiping everything from before...
	// an a game init for just the level things...
	// do that

	lev = NULL;
	tmp = jeu->level_list;
	i = 0;	// no cuz if not bonus, it would be a bad file...
	while (i < jeu->cur_level && tmp)
	{
		++i;
		tmp = tmp->next;
	}
	if (tmp)
	{
		lev = (t_level*)tmp->content;
		if (!ft_prime_level(jeu, lev))
			return (ft_error_msg("failed to prime level\n", 0));
	}
	else if (!ft_quit(jeu))
		return (0);
	return (1);
}


	// Put this in Start engine ? or Start engine here ?
int		ft_game_engine(t_game *jeu)
{
	// do 1L and 2L do anything ???	
			// was 1L and 2L
			// x_mask (1L and 2L and such) are not needed for MacOS but necessary for
			// Linux, is 17L correct ???
//	mlx_loop_hook(jeu->mlx->ptr, ft_redraw, jeu);
//	usleep(20000);	// doesnt seem to do anything
	// is there a way to record keypress length, if so use that to stabilize Map button

	// expose and close might be the solution to my 2 keys for each thing

	mlx_hook(jeu->win->win_ptr, 2, (1L << 0), &ft_keypress, jeu);
	mlx_hook(jeu->win->win_ptr, 3, (1L << 1), &ft_keyrelease, jeu);
	mlx_hook(jeu->win->win_ptr, 4, (1L << 2), &ft_mouse_press, jeu);
	mlx_hook(jeu->win->win_ptr, 6, (1L << 6), &ft_mouse_move, jeu);	// could be (1L << 8)
	mlx_hook(jeu->win->win_ptr, 17, (1L << 17), &ft_quit, jeu);

	mlx_loop_hook(jeu->mlx->ptr, ft_keycodes, jeu);
	mlx_loop(jeu->mlx->ptr);
	return (1);
}

	// could put this in main
	// could put some things from main in here at top
int		ft_start_game(t_game *jeu)
{
	printf("set bonus: %d, minimap: %d\n", jeu->set->bonus, jeu->set->minimap);
	if (!ft_prime_engine(jeu))
		return (ft_error_msg("failed to prime engine\n", 0));// also free things ???
	// main title screen
	if (!ft_set_level(jeu))
		return (ft_error_msg("failed to set level\n", 0));// also free things ???
	if (jeu->set->save)
	{
//		if (!ft_draw_imges(jeu))
//			return (ft_error_msg("failed to save to bmp\n", 0));
		// do some shit that draws to BMP ?
		ft_screenshot(jeu);
		
//		ft_save_bmp(jeu);
		
		// could quit window here...
	}
	else if (!ft_game_engine(jeu))
		return (ft_error_msg("engine failed\n", 0));
	return (1);
}









