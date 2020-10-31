/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:37:52 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/31 16:59:14 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_mouse_move(int x, int y, t_game *jeu)
{
	double	rot_speed;

	if (!jeu)
		return (0);
	if (!jeu->set->bonus)
		return (1);
	(void)y;
	rot_speed = ROT_SPEED;
	if (x - jeu->mouse.x < 0)
		ft_rot_left(jeu, rot_speed * (x - jeu->mouse.x) / 3);
	else if (x - jeu->mouse.x > 0)
		ft_rot_right(jeu, rot_speed * (x - jeu->mouse.x) / 3);
	jeu->mouse.x = x;
	return (1);
}

int		ft_mouse_press(int button, int x, int y, t_game *jeu)
{
	if (!jeu)
		return (0);
	(void)x;
	(void)y;
	if (button == M_CLK_L && !ft_shoot_something(jeu))
		return (ft_error_msg("failed to shoot something\n", 0));
	return (1);
}

int		ft_fire(t_game *jeu, t_vect_t map_step, t_vect_d delta_dist, \
		t_vect_d side_dist)
{
	int		nhit;
	int		i;

	if (!jeu)
		return (0);
	nhit = 1;
	while (nhit && ((char**)jeu->lev->floor)[map_step.a.y][map_step.a.x] != '1')
	{
		ft_dda(&map_step.a, &map_step.b, &side_dist, &delta_dist);
		i = -1;
		while (nhit && ++i < jeu->lev->n_spris)
		{
			if (jeu->lev->spris_tab[i].tex \
				&& map_step.a.x == (int)jeu->lev->spris_tab[i].pos.x \
				&& map_step.a.y == (int)jeu->lev->spris_tab[i].pos.y)
			{
				nhit = 0;
				jeu->lev->spris_tab[i].anim_color = 220;
				jeu->lev->spris_tab[i].life -= 50;
				if (jeu->lev->spris_tab[i].life == 0 && !ft_kill_sprite(jeu, i))
					return (ft_error_msg("failed to kill sprite\n", 0));
			}
		}
	}
	return (1);
}

int		ft_shoot_something(t_game *jeu)
{
	t_vect_t	map_step;
	t_vect_d	delta_dist;
	t_vect_d	side_dist;

	if (!jeu)
		return (0);
	if (!jeu->set->bonus)
		return (1);
	map_step.a.x = (int)jeu->me->pos.x;
	map_step.a.y = (int)jeu->me->pos.y;
	delta_dist = ft_calc_delta_dist(jeu->me->dir);
	map_step.b.x = (jeu->me->dir.x < 0) ? -1 : 1;
	map_step.b.y = (jeu->me->dir.y < 0) ? -1 : 1;
	side_dist.x = (jeu->me->dir.x < 0) ? (jeu->me->pos.x - map_step.a.x) \
				* delta_dist.x : (map_step.a.x + 1.0 - jeu->me->pos.x) \
				* delta_dist.x;
	side_dist.y = (jeu->me->dir.y < 0) ? (jeu->me->pos.y - map_step.a.y) \
				* delta_dist.y : (map_step.a.y + 1.0 - jeu->me->pos.y) \
				* delta_dist.y;
	if (!ft_fire(jeu, map_step, delta_dist, side_dist))
		return (0);
	return (1);
}
