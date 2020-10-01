/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:21:14 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/23 02:18:33 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// free if fail here ?
	// new name...


#include "cub3d.h"

	// void ???
void		ft_get_floor_dimentions(t_game *jeu, t_nlist *floor)
{
	int		n;
	t_nlist	*tmp;

	tmp = floor;
	while (tmp)
	{
		if ((n = ft_strlen((char*)tmp->content)) > jeu->boxes.x)
			jeu->boxes.x = n;
		tmp = tmp->next;
		++(jeu->boxes.y);
	}
	jeu->last_box = jeu->boxes.x * jeu->boxes.y;
//	return (1);
}

	// should be pretty good now..
int		ft_copy_floor(t_game *jeu, t_nlist *floor)
{
	int			a;
	char		**new_floor;
	t_nlist		*tmp;

	// need a free **new_floor if error, Celia's error func !!!

	ft_get_floor_dimentions(jeu, floor);

	if (!(new_floor = (char**)malloc(sizeof(char*) * (jeu->boxes.y + 1))))
		return (0);
	tmp = floor;
	a = 0;
	while (a < jeu->boxes.y)
	{	// ft_memalloc might be overkill but better safe than sorry
		if (!(new_floor[a] = (char*)ft_memalloc(sizeof(char) \
							* (jeu->boxes.x + 1))))
			return (0);
		new_floor[a] = ft_memset(new_floor[a], ' ', jeu->boxes.x);
		new_floor[a] = ft_strcpy(new_floor[a], (char*)tmp->content);
		tmp = tmp->next;
		++a;
	}
	new_floor[a] = 0;
	jeu->floor = new_floor;
	return (1);
}

	// this is way worse...
int		ft_g(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' \
		|| c == 'E' || c == 'W')
		return (1);
	return (0);
}

int		ft_check_around(t_game *jeu, int x, int y)
{
	if (jeu->floor[y][x] == '1')
		return (1);
	if (x == 0 || x == jeu->boxes.x - 1 || y == 0 || y == jeu->boxes.y - 1 \
		|| !ft_g(jeu->floor[y][x - 1]) || !ft_g(jeu->floor[y - 1][x]) \
		|| !ft_g(jeu->floor[y][x + 1]) || !ft_g(jeu->floor[y + 1][x]) \
		|| !ft_g(jeu->floor[y - 1][x - 1]) || !ft_g(jeu->floor[y + 1][x - 1]) \
		|| !ft_g(jeu->floor[y - 1][x + 1]) || !ft_g(jeu->floor[y + 1][x + 1]))
		return (0);
	return (1);
}

int		ft_check_floor(t_game *jeu)
{
	int			x;
	int			y;
	
	y = 0;
	while (y < jeu->boxes.y)
	{
		x = 0;
		while (x < jeu->boxes.x)
		{			// is this the most efficient logic ?
			if ((ft_findchar("012 ", jeu->floor[y][x])) == -1)
			{
				if ((ft_findchar("NSEW", jeu->floor[y][x])) != -1)
				{
					jeu->me->s_dir = jeu->floor[y][x];
					jeu->me->pos.x = x + 0.5;
					jeu->me->pos.y = y + 0.5;
					jeu->floor[y][x] = '0';
				}
				else
					return (ft_error_msg("bad map char\n", 0));
			}
			if (!ft_check_around(jeu, x, y))
			{
				printf("x: %d, y: %d, char: %c\n", x, y, jeu->floor[y][x]);
				return (ft_error_msg("map not closed\n", 0));
			}
/*			if (jeu->floor[y][x] != '1')
			{
				 ft_check_around(jeu, x, y)
				return (ft_error_msg("map not closed\n"));
			}
*/
			++x;
		}
		++y;
	}
	ft_init_player(jeu);
	return (1);
}



