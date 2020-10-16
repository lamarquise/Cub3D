/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:21:14 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/16 03:44:27 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// new name...

#include "cub3d.h"

				// we added L but need it to only work if bonus...
	// this is way worse...
int		ft_g(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' \
		|| c == 'E' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z')
		return (1);
	return (0);
}

int		ft_check_around(t_level *lev, int x, int y)
{
	if (lev->floor[y][x] == '1')
		return (1);
	if (lev->floor[y][x] == ' ')	// is necessary but i would like to rework the
		return (1);		// ???		// logic...
	if (x == 0 || x == lev->dim.x - 1 || y == 0 || y == lev->dim.y - 1 \
		|| !ft_g(lev->floor[y][x - 1]) || !ft_g(lev->floor[y - 1][x]) \
		|| !ft_g(lev->floor[y][x + 1]) || !ft_g(lev->floor[y + 1][x]) \
		|| !ft_g(lev->floor[y - 1][x - 1]) || !ft_g(lev->floor[y + 1][x - 1]) \
		|| !ft_g(lev->floor[y - 1][x + 1]) || !ft_g(lev->floor[y + 1][x + 1]))
		return (0);
	return (1);
}

int		ft_check_floor(t_level *lev)
{
	int			x;
	int			y;
	
	y = 0;
	while (y < lev->dim.y)
	{
		x = 0;
//		while (x < jeu->boxes.x)
		while (lev->floor[y][x])	// much better
		{			// is this the most efficient logic ?
			if ((ft_findchar("012 ", lev->floor[y][x])) == -1)
			{
				// if multiple letters you have to error return...

				if ((ft_findchar("NSEW", lev->floor[y][x])) != -1)
				{
					lev->player_orient = lev->floor[y][x];
					lev->player_pos.x = x + 0.5;
					lev->player_pos.y = y + 0.5;
					lev->floor[y][x] = '0';
				}
				else if (lev->floor[y][x] == 'X')
				{
					lev->exit_pos.x = x;
					lev->exit_pos.y = y;
//					lev->floor[y][x] = '0';		// not sure about this...
				}
				else
				{
					printf("pos x: %d, y: %d, bad char: |%c|\n", x, y, lev->floor[y][x]);
					return (ft_error_msg("bad map char\n", 0));
				}
			}
			if (!ft_check_around(lev, x, y))
			{
				printf("x: %d, y: %d, char: |%c|\n", x, y, lev->floor[y][x]);
				return (ft_error_msg("map not closed\n", 0));
			}
			++x;
		}
		++y;
	}

	// what is the largest number on the map, there need to be that many sprite textures

//	ft_init_player(jeu);	// not here anymore
	return (1);
}



