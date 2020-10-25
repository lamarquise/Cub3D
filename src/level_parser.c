/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 02:33:08 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/25 03:59:49 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


	// add to lib	// if it works lol
/*
int			ft_contains_only(char *src, char *this)
{

	printf("contains only: %s\n", src);

	while (src)
	{
		if (ft_findchar(this, *src) == -1)
			return (0);
		++src;
	}
	return (1);
}
*/


int		ft_get_floor_dimentions(t_level *lev, t_nlist *floor)
{
	int			n;
//	t_nlist		*tmp;

//	tmp = floor;
	if (!lev || !floor)
		return (ft_error_msg("failed to send lev or floor\n", 0));
//	while (floor && n != 0 /*&& ft_contains_only(" \n", (char*)floor->content)*/)
	while (floor && (n = ft_strlen((char*)floor->content)) != 0)
	{
//		printf("floor str: %s, n = %d\n", (char*)floor->content, n);
		if (n > lev->dim.x)
			lev->dim.x = n;
		++(lev->dim.y);
		floor = floor->next;
	}
//	printf("get dim dim x: %d, y: %d\n", lev->dim.x, lev->dim.y);
	lev->last_box = lev->dim.x * lev->dim.y;
	return (1);
}

t_level	*ft_create_level(t_nlist **floor)
{
	int			a;
//	int			n;
	t_level		*lev;
	char		**new_floor;

	lev = NULL;
	new_floor = NULL;// i think i still need to malloc this shit...	dif func?
//	printf("testing create level 1\n");
	if (!(lev = malloc(sizeof(t_level))) || !ft_init_level(lev))
		return (NULL);
//	printf("testing create level 2\n");
	if (!ft_get_floor_dimentions(lev, *floor))
		return (NULL);		// there is no map, but no error
//	printf("testing create level 3\n");
//	printf("dim x: %d, y: %d\n", lev->dim.x, lev->dim.y);
	if (!(new_floor = (char**)malloc(sizeof(char*) * (lev->dim.y + 1))))
		return (NULL);
	a = 0;
	while (a < lev->dim.y)
	{
		if (!(new_floor[a] = (char*)ft_memalloc(sizeof(char) * (lev->dim.x + 1))))
			return (NULL);
		new_floor[a] = ft_memset(new_floor[a], ' ', lev->dim.x);
		new_floor[a] = ft_strcpy(new_floor[a], (char*)(*floor)->content);
		*floor = (*floor)->next;
//		printf("testing create level 4\nnew floor str: |%s|\n", new_floor[a]);
		++a;
	}
	new_floor[a] = 0;
//	printf("testing create level 5\n");
	lev->floor = new_floor;
//	printf("create lev floor:\n");
//	ft_print_strtab(lev->floor);
	// check floor here ?
	return (lev);
}

	// make sure if empty lines before or after, it still works
int		ft_collect_levels(t_game *jeu, t_nlist *floor)
{
	//go through whole thing looking for empty lines, copy floor between
	t_nlist		*tmp;
	t_level		*lev;

	tmp = floor;
	lev = NULL;
	while (tmp)
	{
//		if (n == 0 /*|| ft_contains_only(" \n", (char*)tmp->content)*/)
		if (!ft_strlen((char*)tmp->content))
			tmp = tmp->next;
		else
		{
//			printf("collect levels test 2\n");
			if (!(lev = ft_create_level(&tmp)))
				return (ft_error_msg("failed to create level\n", 0));
//			printf("collect levels test 3\n");
			if (!ft_check_floor(jeu, lev))
				return (ft_error_msg("bad floor\n", 0));
//			printf("collect levels test 4\n");
			if (!ft_nlstadd_back(&jeu->level_list, \
				ft_nlstnew((void*)lev, 0)))
				return (ft_error_msg("failed to add new floor to list\n", 0));
			++jeu->n_of_levels;

//			ft_print_strtab((char**)((t_level*)jeu->level_list->content)->floor);
//			printf("collect levels test 5\n");
		}
	}
	printf("levels collected\n");

	if (!jeu->set->bonus && jeu->n_of_levels > 1)
		return (ft_error_msg("not bonus, bad file, too many levels\n", 0));
	return (1);
}

