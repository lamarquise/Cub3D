/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 02:09:19 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/24 20:19:55 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int			ft_rot_key(t_level *lev, int i)
{
	double	rot_speed;
	double	old_dir_x;

	if ((int)lev->spris_tab[i].dir.x % 2 == 1)
		rot_speed = 1.0;
	else
		rot_speed = -1.0;
	old_dir_x = lev->spris_tab[i].dir.x;
	lev->spris_tab[i].dir.x = lev->spris_tab[i].dir.x * cos(-rot_speed) \
							- lev->spris_tab[i].dir.y * sin(-rot_speed);
	lev->spris_tab[i].dir.y = old_dir_x * sin(-rot_speed) \
							+ lev->spris_tab[i].dir.y * cos(-rot_speed);

	// make it a dif color when turning...

	return (1);
}

int			ft_move_key(t_level *lev, int i)
{
	// check x then y


	if (((char**)lev->floor)[(int)lev->spris_tab[i].pos.y] \
		[(int)(lev->spris_tab[i].pos.x + lev->spris_tab[i].dir.x \
		* (STEP_SIZE + 0.02))] == '1')
	{
		// do the rotation
		if (!ft_rot_key(lev, i))
			return (ft_error_msg("falied to rotate key\n", 0));
		return (1);
	}
	if (((char**)lev->floor)[(int)(lev->spris_tab[i].pos.y \
		+ lev->spris_tab[i].dir.y * (STEP_SIZE + 0.02))] \
		[(int)lev->spris_tab[i].pos.x] == '1')
	{
		// do the rotation
		if (!ft_rot_key(lev, i))
			return (ft_error_msg("falied to rotate key\n", 0));
		return (1);
	}
	lev->spris_tab[i].pos.x += lev->spris_tab[i].dir.x * STEP_SIZE;
	lev->spris_tab[i].pos.y += lev->spris_tab[i].dir.y * STEP_SIZE;


	// could do a * 2 step size...




	return (1);
}







