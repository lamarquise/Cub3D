/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 02:33:08 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 01:19:55 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_get_floor_dimentions(t_level *lev, t_nlist *floor)
{
	int			n;

	if (!lev || !floor)
		return (ft_error_msg("failed to send lev or floor\n", 0));
	while (floor && (n = ft_strlen((char*)floor->content)) != 0)
	{
		if (n > lev->dim.x)
			lev->dim.x = n;
		++(lev->dim.y);
		floor = floor->next;
	}
	lev->last_box = lev->dim.x * lev->dim.y;
	return (1);
}

int		ft_fill_floor(t_nlist **floor, t_level *lev, char **new_floor)
{
	int		a;

	if (!floor || !lev || !new_floor)
		return (0);
	a = 0;
	while (a < lev->dim.y && *floor)
	{
		if (!(new_floor[a] = (char*)ft_memalloc(sizeof(char) \
			* (lev->dim.x + 1))))
			return (0);
		new_floor[a] = ft_memset(new_floor[a], ' ', lev->dim.x);
		new_floor[a] = ft_strcpy(new_floor[a], (char*)(*floor)->content);
		*floor = (*floor)->next;
		++a;
	}
	return (1);
}

t_level	*ft_create_level(t_nlist **floor)
{
	t_level		*lev;
	char		**new_floor;

	if (!floor)
		return (0);
	lev = NULL;
	new_floor = NULL;
	if (!(lev = malloc(sizeof(t_level))))
		return (NULL);
	if (!ft_init_level(lev) || !ft_get_floor_dimentions(lev, *floor)
		|| !(new_floor = (char**)ft_memalloc(sizeof(char*) * (lev->dim.y + 1))))
	{
		free(lev);
		return (NULL);
	}
	if (!ft_fill_floor(floor, lev, new_floor))
	{
		free(lev);
		ft_free_strtab(new_floor);
		return (NULL);
	}
	lev->floor = new_floor;
	return (lev);
}

int		ft_add_level(t_game *jeu, t_level *lev)
{
	if (!jeu || !lev)
		return (0);
	if (!ft_check_floor(jeu, lev))
		return (ft_error_msg("bad floor\n", 0));
	if (!ft_nlstadd_secback(&jeu->level_list, (void*)lev))
		return (ft_error_msg("failed to add lev to list\n", 0));
	++jeu->n_of_levels;
	return (1);
}

int		ft_collect_levels(t_game *jeu, t_nlist *floor)
{
	t_nlist		*tmp;
	t_level		*lev;

	if (!jeu || !floor)
		return (0);
	tmp = floor;
	while (tmp)
	{
		lev = NULL;
		if (!ft_strlen((char*)tmp->content))
			tmp = tmp->next;
		else
		{
			if (!(lev = ft_create_level(&tmp)))
				return (ft_error_msg("failed to create level\n", 0));
			if (!ft_add_level(jeu, lev))
			{
				ft_free_tlevel_contents(lev);
				free(lev);
				return (ft_error_msg("bad floor\n", 0));
			}
		}
	}
	return (1);
}
