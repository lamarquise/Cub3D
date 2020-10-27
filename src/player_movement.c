/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:24:04 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/26 20:31:07 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_move_forward(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (((char**)jeu->lev->floor)[(int)jeu->me->pos.y]\
		[(int)(jeu->me->pos.x + jeu->me->dir.x * STEP_SIZE - 0.02)] == '0')
		jeu->me->pos.x += jeu->me->dir.x * STEP_SIZE;
	if (((char**)jeu->lev->floor)[(int)(jeu->me->pos.y + jeu->me->dir.y \
		* STEP_SIZE - 0.02)][(int)jeu->me->pos.x] == '0')
		jeu->me->pos.y += jeu->me->dir.y * STEP_SIZE;
	return (1);
}

int		ft_move_backward(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (((char**)jeu->lev->floor)[(int)jeu->me->pos.y]\
		[(int)(jeu->me->pos.x - jeu->me->dir.x * (STEP_SIZE + 0.02))] != '1')
		jeu->me->pos.x -= jeu->me->dir.x * STEP_SIZE;
	if (((char**)jeu->lev->floor)[(int)(jeu->me->pos.y - jeu->me->dir.y \
		* (STEP_SIZE + 0.02))][(int)jeu->me->pos.x] != '1')
		jeu->me->pos.y -= jeu->me->dir.y * STEP_SIZE;
	return (1);
}

int		ft_move_left(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (((char**)jeu->lev->floor)[(int)jeu->me->pos.y]\
		[(int)(jeu->me->pos.x - jeu->me->plane.x * (STEP_SIZE + 0.02))] != '1')
		jeu->me->pos.x -= jeu->me->plane.x * STEP_SIZE;
	if (((char**)jeu->lev->floor)[(int)(jeu->me->pos.y - jeu->me->plane.y \
		* (STEP_SIZE + 0.02))][(int)jeu->me->pos.x] != '1')
		jeu->me->pos.y -= jeu->me->plane.y * STEP_SIZE;
	return (1);
}

int		ft_move_right(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (((char**)jeu->lev->floor)[(int)jeu->me->pos.y][(int)(jeu->me->pos.x \
		+ jeu->me->plane.x * (STEP_SIZE + 0.02))] != '1')
		jeu->me->pos.x += jeu->me->plane.x * STEP_SIZE;
	if (((char**)jeu->lev->floor)[(int)(jeu->me->pos.y + jeu->me->plane.y \
		* (STEP_SIZE + 0.02))][(int)jeu->me->pos.x] != '1')
		jeu->me->pos.y += jeu->me->plane.y * STEP_SIZE;
	return (1);
}
