/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:42:53 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/24 03:30:25 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// changed all the collision checks to be != 1, was == 0 before


#include "cub3d.h"

	// are we redrawing ??? like since we have the new loop hook???

int		ft_move_forward(t_game *jeu)
{
	// i think there's a way of doing this all in one ???
			// where the fuck does 0.02 come from ?????
//	printf("dir.x %f dir.y %f\n", jeu->me->dir.x, jeu->me->dir.y);

	double		x;
	double		y;
					// was - 0.02  no parenthesies
												// was - 0.02
	x = (jeu->me->pos.x + jeu->me->dir.x * (STEP_SIZE + 0.02));
	y = (jeu->me->pos.y + jeu->me->dir.y * (STEP_SIZE + 0.02));

//	printf("x: %f, y: %f\n", x, y);

	if (((char**)jeu->lev->floor)[(int)jeu->me->pos.y] \
		[(int)x] != '1')
		jeu->me->pos.x += jeu->me->dir.x * STEP_SIZE;
	if (((char**)jeu->lev->floor)[(int)y] \
		[(int)jeu->me->pos.x] != '1')
		jeu->me->pos.y += jeu->me->dir.y * STEP_SIZE;

/*	if (((char**)jeu->lev->floor)[(int)jeu->me->pos.y] \
		[(int)(jeu->me->pos.x + jeu->me->dir.x * STEP_SIZE - 0.02)] == '0')
		jeu->me->pos.x += jeu->me->dir.x * STEP_SIZE;
	if (((char**)jeu->lev->floor)[(int)(jeu->me->pos.y + jeu->me->dir.y * STEP_SIZE - 0.02)] \
		[(int)jeu->me->pos.x] == '0')
	{
		jeu->me->pos.y += jeu->me->dir.y * STEP_SIZE;
//		printf("for y is possible\n");
	}
*/
//	printf("move forward, x = %f, y = %f", jeu->me->pos.x, jeu->me->pos.y);

//	return (ft_redraw(jeu));
	return (1);

}


//int		ft_move_backward(t_screen *either)
int		ft_move_backward(t_game *jeu)
{				// was + 0.02  no parenthesies
	
	if (((char**)jeu->lev->floor)[(int)jeu->me->pos.y] \
		[(int)(jeu->me->pos.x - jeu->me->dir.x * (STEP_SIZE + 0.02))] != '1')
		jeu->me->pos.x -= jeu->me->dir.x * STEP_SIZE;
	if (((char**)jeu->lev->floor)[(int)(jeu->me->pos.y - jeu->me->dir.y * (STEP_SIZE + 0.02))] \
		[(int)jeu->me->pos.x] != '1')
		jeu->me->pos.y -= jeu->me->dir.y * STEP_SIZE;

//	return (ft_redraw(jeu));
	return (1);
}

	// swaped left and right names
	// back to normal -> left on top then right
int		ft_move_left(t_game *jeu)
{				// was + 0.02  no parenthesies
	if (((char**)jeu->lev->floor)[(int)jeu->me->pos.y] \
		[(int)(jeu->me->pos.x - jeu->me->plane.x * (STEP_SIZE + 0.02))] != '1')
		jeu->me->pos.x -= jeu->me->plane.x * STEP_SIZE;
	if (((char**)jeu->lev->floor)[(int)(jeu->me->pos.y - jeu->me->plane.y * (STEP_SIZE + 0.02))] \
		[(int)jeu->me->pos.x] != '1')
		jeu->me->pos.y -= jeu->me->plane.y * STEP_SIZE;

//	return (ft_redraw(jeu));
	return (1);
}

int		ft_move_right(t_game *jeu)
{				// was - 0.02  no parenthesies
	if (((char**)jeu->lev->floor)[(int)jeu->me->pos.y][(int)(jeu->me->pos.x + \
		jeu->me->plane.x * (STEP_SIZE + 0.02))] != '1')
		jeu->me->pos.x += jeu->me->plane.x * STEP_SIZE;
	if (((char**)jeu->lev->floor)[(int)(jeu->me->pos.y + jeu->me->plane.y * (STEP_SIZE + 0.02))] \
		[(int)jeu->me->pos.x] != '1')
		jeu->me->pos.y += jeu->me->plane.y * STEP_SIZE;

//	return (ft_redraw(jeu));
	return (1);
}

	// we swaped from right first and left second


	// ok so apparently we aren't even using the DEFINE ROT_SPEED...

int		ft_rot_left(t_game *jeu)
{
	double rotSpeed = 0.04;		// could do minus here and not in code below
	double oldDirX = jeu->me->dir.x;
	jeu->me->dir.x = jeu->me->dir.x * cos(-rotSpeed) - jeu->me->dir.y *\
					sin(-rotSpeed);
	jeu->me->dir.y = oldDirX * sin(-rotSpeed) + jeu->me->dir.y * cos(-rotSpeed);
	double oldPlaneX = jeu->me->plane.x;
	jeu->me->plane.x = jeu->me->plane.x * cos(-rotSpeed) - jeu->me->plane.y *\
					sin(-rotSpeed);
	jeu->me->plane.y = oldPlaneX * sin(-rotSpeed) + jeu->me->plane.y * cos(-rotSpeed);

//	return (ft_redraw(jeu));
	return (1);
}

int		ft_rot_right(t_game *jeu)
{
	double rotSpeed = -0.04;
	double oldDirX = jeu->me->dir.x;
	jeu->me->dir.x = jeu->me->dir.x * cos(-rotSpeed) - jeu->me->dir.y *\
					sin(-rotSpeed);
	jeu->me->dir.y = oldDirX * sin(-rotSpeed) + jeu->me->dir.y * cos(-rotSpeed);
	double oldPlaneX = jeu->me->plane.x;
	jeu->me->plane.x = jeu->me->plane.x * cos(-rotSpeed) - jeu->me->plane.y *\
					sin(-rotSpeed);
	jeu->me->plane.y = oldPlaneX * sin(-rotSpeed) + jeu->me->plane.y * cos(-rotSpeed);

//	return (ft_redraw(jeu));
	return (1);
}





