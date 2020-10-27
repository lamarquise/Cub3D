/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_behavior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 02:09:19 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 03:02:56 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_rot_sprite(t_level *lev, int i)
{
	double	rot_speed;
	double	old_dir_x;

	if (!lev)
		return (0);
	if ((int)lev->spris_tab[i]->dir.x % 2 == 1)
		rot_speed = 1.0;
	else
		rot_speed = -1.0;
	old_dir_x = lev->spris_tab[i]->dir.x;
	lev->spris_tab[i]->dir.x = lev->spris_tab[i]->dir.x * cos(-rot_speed) \
							- lev->spris_tab[i]->dir.y * sin(-rot_speed);
	lev->spris_tab[i]->dir.y = old_dir_x * sin(-rot_speed) \
							+ lev->spris_tab[i]->dir.y * cos(-rot_speed);
	return (1);
}

int			ft_move_sprite(t_level *lev, int i)
{
	if (!lev || !lev->spris_tab)
		return (0);
	if (((char**)lev->floor)[(int)lev->spris_tab[i]->pos.y]\
		[(int)(lev->spris_tab[i]->pos.x + lev->spris_tab[i]->dir.x \
		* (STEP_SIZE + 0.02))] == '1')
	{
		if (!ft_rot_sprite(lev, i))
			return (ft_error_msg("falied to rotate key\n", 0));
		return (1);
	}
	if (((char**)lev->floor)[(int)(lev->spris_tab[i]->pos.y \
		+ lev->spris_tab[i]->dir.y \
		* (STEP_SIZE + 0.02))][(int)lev->spris_tab[i]->pos.x] == '1')
	{
		if (!ft_rot_sprite(lev, i))
			return (ft_error_msg("falied to rotate key\n", 0));
		return (1);
	}
	lev->spris_tab[i]->pos.x += lev->spris_tab[i]->dir.x * STEP_SIZE;
	lev->spris_tab[i]->pos.y += lev->spris_tab[i]->dir.y * STEP_SIZE;
	return (1);
}

int			ft_kill_sprite(t_game *jeu, int index)
{
	int		i;

	if (!jeu)
		return (0);
	if (index == jeu->lev->key_index)
	{
		jeu->me->key = 1;
		jeu->lev->key_index = -1;
	}
	if (index == jeu->lev->exit_index)
		jeu->lev->exit_index = -1;
	i = -1;
	while (++i < jeu->lev->n_spris)
	{
//		printf("kill sprite test 2tab id: %c\n", jeu->lev->spris_tab[i]->id);
		jeu->lev->spris_tab[i] = NULL;
	}
//	free(jeu->lev->spris_tab);	// crashes the whole thing
	jeu->lev->spris_tab = NULL;
	if (!ft_nlstdel_n_sprite(&jeu->lev->spris_list, index))
		return (ft_error_msg("failed to del dead sprite\n", 0));
	--jeu->lev->n_spris;
	if (jeu->lev->n_spris && !ft_create_spris_tab(jeu->lev))
		return (ft_error_msg("failed to create new spris tab\n", 0));
	return (1);
}
