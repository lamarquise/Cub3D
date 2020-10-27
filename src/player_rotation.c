/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:28:09 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/26 21:00:53 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_rot_left(t_game *jeu, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	if (!jeu)
		return (0);
	old_dir_x = jeu->me->dir.x;
	old_plane_x = jeu->me->plane.x;
	jeu->me->dir.x = jeu->me->dir.x * cos(rot_speed) - jeu->me->dir.y \
					* sin(rot_speed);
	jeu->me->dir.y = old_dir_x * sin(rot_speed) + jeu->me->dir.y \
					* cos(rot_speed);
	jeu->me->plane.x = jeu->me->plane.x * cos(rot_speed) - jeu->me->plane.y \
						* sin(rot_speed);
	jeu->me->plane.y = old_plane_x * sin(rot_speed) + jeu->me->plane.y \
						* cos(rot_speed);
	return (1);
}

int		ft_rot_right(t_game *jeu, double rot_speed)
{
	double old_dir_x;
	double old_plane_x;

	if (!jeu)
		return (0);
	old_dir_x = jeu->me->dir.x;
	old_plane_x = jeu->me->plane.x;
	jeu->me->dir.x = jeu->me->dir.x * cos(rot_speed) - jeu->me->dir.y \
					* sin(rot_speed);
	jeu->me->dir.y = old_dir_x * sin(rot_speed) + jeu->me->dir.y \
					* cos(rot_speed);
	jeu->me->plane.x = jeu->me->plane.x * cos(rot_speed) - jeu->me->plane.y \
						* sin(rot_speed);
	jeu->me->plane.y = old_plane_x * sin(rot_speed) + jeu->me->plane.y \
						* cos(rot_speed);
	return (1);
}
