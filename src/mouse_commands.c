/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:02:15 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/12 01:12:18 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		ft_capture_mouse_pos(int x, int y, t_game *jeu)
{
	jeu->mouse.x = x;
	jeu->mouse.y = y;
	return (1);
}

	// change rot speed or make so mouse x dif needs to be greater and
	// only update if calls rot ?...

int		ft_mouse_move(int x, int y, t_game *jeu)
{
	(void)y;

	// calc the dif btw this and og, then take that and apply to rot


//	printf("mouse x: %d, y: %d\n", x, y);

	if (x - jeu->mouse.x < 0)
		ft_rot_left(jeu);
	else if (x - jeu->mouse.x > 0)
		ft_rot_right(jeu);

	// should i put this before the rot call ???
	jeu->mouse.x = x;

	return (1);
}













