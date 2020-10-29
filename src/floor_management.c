/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:21:14 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 23:42:26 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_g(char c, char s)
{
	if (c >= '0' && c <= (49 + s))
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'X' \
		|| c == 'Y')
		return (1);
	return (0);
}

int		ft_check_around(t_level *lev, int x, int y, char s)
{
	if (lev->floor[y][x] == '1' || lev->floor[y][x] == ' ')
		return (1);
	if (x == 0 || x == lev->dim.x - 1 || y == 0 || y == lev->dim.y - 1 \
		|| !ft_g(lev->floor[y][x - 1], s) || !ft_g(lev->floor[y - 1][x], s) \
		|| !ft_g(lev->floor[y][x + 1], s) || !ft_g(lev->floor[y + 1][x], s) \
		|| !ft_g(lev->floor[y - 1][x - 1], s) \
		|| !ft_g(lev->floor[y + 1][x - 1], s) \
		|| !ft_g(lev->floor[y - 1][x + 1], s) \
		|| !ft_g(lev->floor[y + 1][x + 1], s))
		return (ft_error_msg("map not closed\n", 0));
	return (1);
}

int		ft_found_sprite(t_game *jeu, t_level *lev, t_vect_i p)
{
	if (!jeu || !jeu->lev)
		return (0);
	if ((lev->floor[p.y][p.x] == 'X' && !(jeu->bbol & BEX)) \
		|| (lev->floor[p.y][p.x] == 'Y' && !(jeu->bbol & BKE)))
		return (ft_error_msg("No tex corresponding to this sprite type\n", 0));
	if (!ft_lstadd_sprite_instance(jeu, p.x, p.y, lev->floor[p.y][p.x]))
		return (ft_error_msg("bad sprite char in map\n", 0));
	if (lev->floor[p.y][p.x] == 'X' && lev->exit_exists == 0)
		lev->exit_exists = 1;
	else if (lev->floor[p.y][p.x] == 'Y' && lev->key_exists == 0)
		lev->key_exists = 1;
	else if (lev->floor[p.y][p.x] == 'X' || lev->floor[p.y][p.x] == 'Y')
		return (ft_error_msg("Too many doors or keys\n", 0));
	lev->floor[p.y][p.x] = '0';
	++lev->n_spris;
	return (1);
}

int		ft_found_not_wall(t_game *jeu, t_level *lev, t_vect_i p, int s)
{
	if (!jeu || !jeu->lev)
		return (0);
	if ((ft_findchar("NSEW", lev->floor[p.y][p.x])) != -1)
	{
		if (lev->player_sorient)
			return (ft_error_msg("too many player starts\n", 0));
		lev->player_sorient = lev->floor[p.y][p.x];
		lev->player_spos.x = p.x + 0.5;
		lev->player_spos.y = p.y + 0.5;
		lev->floor[p.y][p.x] = '0';
	}
	else if ((lev->floor[p.y][p.x] > '1' && lev->floor[p.y][p.x] <= s) \
		|| (ft_findchar("XY", lev->floor[p.y][p.x])) != -1)
	{
		if (!ft_found_sprite(jeu, lev, p))
			return (0);
	}
	else
		return (ft_error_msg("bad map char\n", 0));
	return (1);
}

int		ft_check_floor(t_game *jeu, t_level *lev)
{
	int			x;
	int			y;

	if (!jeu || !lev)
		return (0);
	jeu->lev = lev;
	y = -1;
	while (++y < lev->dim.y)
	{
		x = -1;
		while (lev->floor[y][++x])
		{
			if ((ft_findchar("01 ", lev->floor[y][x])) == -1 \
				&& (!ft_found_not_wall(jeu, lev, ft_fill_vect_i(x, y), \
				jeu->file->n_spri_types + 49)
				|| !ft_check_around(lev, x, y, jeu->file->n_spri_types + 49)))
				return (0);
		}
	}
	if (!ft_create_spris_tab(lev))
		return (ft_error_msg("failed to create 1st spris tab\n", 0));
	if (!lev->player_sorient)
		return (ft_error_msg("bad map no player start\n", 0));
	jeu->lev = NULL;
	return (1);
}
