/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 23:45:11 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/26 00:08:33 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_keypress(int key, t_game *jeu)
{
//	usleep(1000);
/*	if ((key == 46 || key == 53) && jeu->torch[key] == 1)
		jeu->torch[key] = 0;
	else
*/		jeu->torch[key] = 1;
	return (1);
}

int		ft_keyrelease(int key, t_game *jeu)
{
//	if (key != 46 && key != 53)	// definitly fucks things up for the map display (flikers)
		jeu->torch[key] = 0;
	return (1);	// may end up returning 0
}


	// move this later
int		 ft_keycodes(t_game *jeu)
{		   // replace numbers with defines

	// would be so much nicer to do with a loop and a dedicated init func
	// but still have the .h problem where can't have cross referencing
	// structures...
		// not sure this will work...
		// this is how the player moves to the next level

	if (jeu->lev->key_exists && (int)jeu->me->pos.x == (int)jeu->lev->spris_tab[jeu->lev->key_index].pos.x && (int)jeu->me->pos.y == (int)jeu->lev->spris_tab[jeu->lev->key_index].pos.y)
	{
//		jeu->me->key = 1;
		// get sprite tab index based on id
		// delete that sprite (the key)
		// also in shooting, if it's the key you get the key
		if (!ft_sprite_dies(jeu, jeu->lev->key_index))
			return (ft_error_msg("failed to destroy sprite\n", 0));
	}


	if (jeu->lev->exit_exists && jeu->me->key == 1 && (int)jeu->me->pos.x == (int)jeu->lev->spris_tab[jeu->lev->exit_index].pos.x && (int)jeu->me->pos.y == (int)jeu->lev->spris_tab[jeu->lev->exit_index].pos.y)
	{
		++jeu->cur_level;
		if (!ft_set_level(jeu))
			return (0);
	}
/*
	if (jeu->me->pos.x > jeu->lev->exit_pos.x && jeu->me->pos.x < jeu->lev->exit_pos.x + 1 \
		&& jeu->me->pos.y > jeu->lev->exit_pos.y && jeu->me->pos.y < jeu->lev->exit_pos.y + 1)
	{
		++jeu->cur_level;
		if (!ft_set_level(jeu))
		return (0);
	}
*/
	if (jeu->torch[K_W] && !ft_move_forward(jeu))
		return (0);
	if (jeu->torch[K_S] && !ft_move_backward(jeu))
		return (0);
	if (jeu->torch[K_A] && !ft_move_left(jeu))
		return (0);
	if (jeu->torch[K_D] && !ft_move_right(jeu))
		return (0);
	if (jeu->torch[K_AR_L] && !ft_rot_left(jeu))
		return (0);
	if (jeu->torch[K_AR_R] && !ft_rot_right(jeu))
		return (0);

		// not as satisfying....
	if (jeu->torch[K_AR_U] && !ft_shoot_something(jeu))			// shoot with arrow key
		return (0);
						// keep this extra condition in mind for
						// future butons
	if (jeu->torch[K_M] && /*jeu->set->bonus &&*/ !ft_toggle_on(&jeu->set->minimap))
		return (0);
	if (jeu->torch[K_N] && !ft_toggle_off(&jeu->set->minimap))
		return (0);
/*	if (jeu->torch[K_P] && !ft_toggle_on(&jeu->set->pause))
		return (0);
	if (jeu->torch[K_O] && !ft_toggle_off(&jeu->set->pause))
		return (0);
*/
	if (jeu->torch[K_Z] && !ft_toggle_on(&jeu->set->zoom))	// Z: Zoom in
		return (0);
	if (jeu->torch[K_X] && !ft_toggle_off(&jeu->set->zoom))	// X: Zoom out
		return (0);
	

	if (jeu->torch[K_ESC] && !ft_quit(jeu))				// also change ???
		return (0);

// do rather like the redraw here rather than at the end of player command funcs

	// reason redraw is after things happening is so don't constantly redraw
	// only when something changes...
	// but could be good if we put sprite logic in here too...
//	return (0);
	return (ft_redraw(jeu));
}



	// all the rest is defunct


/*
	// move to init ???
void    ft_light_torch(t_key *torch)
{
	torch[0].keycode = 53;
	torch[0].f = ft_quit;
	torch[1].keycode = 46;
	torch[1].f = ft_map;
	torch[2].keycode = 45;
	torch[3].f = ft_normal_or_not;

//	jeu->torch = torch;
}
*/
/*
int     ft_keyhooks(int keycode, t_game *jeu)
{
	static t_key    torch[20] = {{42, NULL}};
	int				i;

	i = 0;
	if (torch[0].keycode == 42)
		ft_light_torch(torch);
	while (i < 8)	// number of codes added
	{
		if (keycode == torch[i].keycode)
			return (torch[i].f(jeu));
		++i;
	}
	return (0);
}

void    ft_hooks_loop(t_game *jeu)
{
	mlx_hook(jeu->win->win_ptr, 2, 0, &ft_keyhooks, jeu);
	mlx_hook(jeu->win->win_ptr, 17, 0, &ft_quit, jeu);

		// didn't work...
//	mlx_loop_hook(jeu->mlx->ptr, ft_keycodes, jeu);
	// add all the other hooks
}
*/





