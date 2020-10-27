/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 23:45:11 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 03:11:36 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_keypress(int key, t_game *jeu)
{
	if (!jeu)
		return (0);
	jeu->torch[key] = 1;
	return (1);
}

int		ft_keyrelease(int key, t_game *jeu)
{
	if (!jeu)
		return (0);
	jeu->torch[key] = 0;
	return (1);
}

int		ft_more_keycodes(t_game *jeu, t_level *lev)
{
	if (!jeu || !lev)
		return (0);

/*	printf("n spris %d\n", jeu->lev->n_spris);
	if (jeu->lev->n_spris > 0)
		ft_kill_sprite(jeu, jeu->lev->n_spris - 1);
	else
		ft_quit(jeu);
*/	if (lev->key_exists && lev->key_index != -1  && lev->spris_tab \
		&& (int)jeu->me->pos.x == (int)lev->spris_tab[lev->key_index].pos.x \
		&& (int)jeu->me->pos.y == (int)lev->spris_tab[lev->key_index].pos.y)
	{
		if (!ft_kill_sprite(jeu, lev->key_index))
			return (ft_error_msg("failed to destroy sprite\n", 0));
	}													// shouldnt need spris tab here
	if (lev->exit_exists && jeu->me->key == 1 && lev->exit_index != -1 && lev->spris_tab \
		&& (int)jeu->me->pos.x == (int)lev->spris_tab[lev->exit_index].pos.x \
		&& (int)jeu->me->pos.y == (int)lev->spris_tab[lev->exit_index].pos.y)
	{
		++jeu->cur_level;
		if (!ft_set_level(jeu))
			return (0);
	}
	if (jeu->torch[K_M] && !ft_toggle_on(&jeu->set->minimap))
		return (0);
	if (jeu->torch[K_N] && !ft_toggle_off(&jeu->set->minimap))
		return (0);
	return (1);
}

int		ft_keycodes(t_game *jeu)
{
	if (!jeu || !ft_more_keycodes(jeu, jeu->lev))
		return (0);
	if (jeu->torch[K_W] && !ft_move_forward(jeu))
		return (0);
	if (jeu->torch[K_S] && !ft_move_backward(jeu))
		return (0);
	if (jeu->torch[K_A] && !ft_move_left(jeu))
		return (0);
	if (jeu->torch[K_D] && !ft_move_right(jeu))
		return (0);
	if (jeu->torch[K_AR_L] && !ft_rot_left(jeu, -ROT_SPEED))
		return (0);
	if (jeu->torch[K_AR_R] && !ft_rot_right(jeu, ROT_SPEED))
		return (0);
	if (jeu->torch[K_AR_U] && !ft_shoot_something(jeu))
		return (0);
	if (jeu->torch[K_ESC] && !ft_quit(jeu))
		return (0);
	if (jeu->torch[K_Z] && !ft_toggle_on(&jeu->set->zoom))
		return (0);
	if (jeu->torch[K_X] && !ft_toggle_off(&jeu->set->zoom))
		return (0);
	return (ft_redraw(jeu));
}
