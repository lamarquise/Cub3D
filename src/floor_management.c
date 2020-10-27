/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:21:14 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 01:01:22 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// new name...

#include "cub3d.h"


			// s is value of n of sprites, make an int ?
	// this is way worse...
int		ft_g(char c, char s)
{
	if (c >= '0' && c <= (49 + s))	// i hope my math is right
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'X' \
		|| c == 'Y' || c == 'Z')
		return (1);
	return (0);
}

int		ft_check_around(t_level *lev, int x, int y, char s)
{
	if (lev->floor[y][x] == '1' || lev->floor[y][x] == ' ')	// is necessary but i would like to rework the
		return (1);
	if (x == 0 || x == lev->dim.x - 1 || y == 0 || y == lev->dim.y - 1 \
		|| !ft_g(lev->floor[y][x - 1], s) || !ft_g(lev->floor[y - 1][x], s) \
		|| !ft_g(lev->floor[y][x + 1], s) || !ft_g(lev->floor[y + 1][x], s) \
		|| !ft_g(lev->floor[y - 1][x - 1], s) || !ft_g(lev->floor[y + 1][x - 1], s) \
		|| !ft_g(lev->floor[y - 1][x + 1], s) || !ft_g(lev->floor[y + 1][x + 1], s))
		return (0);
	return (1);
}

int		ft_check_floor(t_game *jeu, t_level *lev)
{
	int			x;
	int			y;
	int			s;	// char ?

	if (!jeu || !lev)
		return (0);
	jeu->lev = lev;		// need this for add sprite instance
	s = jeu->file->n_spri_types + 49;
	y = 0;
	while (y < lev->dim.y)
	{
		x = 0;
		while (lev->floor[y][x])
		{			// is this the most efficient logic ?
			if ((ft_findchar("01 ", lev->floor[y][x])) == -1)
			{
				// if multiple NSE or W you have to error return...
				if ((ft_findchar("NSEW", lev->floor[y][x])) != -1)
				{
					if (lev->player_sorient)
						return (ft_error_msg("too many player starts\n", 0));

					lev->player_sorient = lev->floor[y][x];
					lev->player_spos.x = x + 0.5;
					lev->player_spos.y = y + 0.5;
					lev->floor[y][x] = '0';
					
//					printf("player pos x: %f, y %f\n", lev->player_pos.x, lev->player_pos.y);
				}
				else if ((lev->floor[y][x] > '1' && lev->floor[y][x] <= s) \
						|| (ft_findchar("XY", lev->floor[y][x])) != -1)
				{
					if ((lev->floor[y][x] == 'X' && !(jeu->bbol & BEX)) \
						|| (lev->floor[y][x] == 'Y' && !(jeu->bbol & BKE)))
						return (ft_error_msg("No tex corresponding to this sprite type\n", 0));
					// make a new 
					if (!ft_lstadd_sprite_instance(jeu, x, y, lev->floor[y][x]))
						return (ft_error_msg("bad sprite char in map\n", 0));

					if (lev->floor[y][x] == 'X' && lev->exit_exists == 0)
						lev->exit_exists = 1;
					else if (lev->floor[y][x] == 'Y' && lev->key_exists == 0)
						lev->key_exists = 1;
					else if (lev->floor[y][x] == 'X' || lev->floor[y][x] == 'Y')
						return (ft_error_msg("Too many doors or keys\n", 0));
					lev->floor[y][x] = '0'; //???
					++lev->n_spris;
				}
				else
				{
					printf("pos x: %d, y: %d, bad char: |%c|\n", x, y, lev->floor[y][x]);
					return (ft_error_msg("bad map char\n", 0));
				}
			}
			if (!ft_check_around(lev, x, y, s))
			{
				printf("x: %d, y: %d, char: |%c|\n", x, y, lev->floor[y][x]);
				return (ft_error_msg("map not closed\n", 0));
			}
			++x;
		}
		++y;
	}
	if (!ft_create_spris_tab(lev))
		return (ft_error_msg("failed to create 1st spris tab\n", 0));

// DO THIS !!!!!!!!!!
	// what is the largest number on the map, there need to be that many sprite textures
	jeu->lev = NULL;
	return (1);
}
