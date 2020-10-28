/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:23:54 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 22:37:04 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_sort_sprites(int *spri_ord, double *spri_dist, int n_spris)
{
	int		j;
	int		sorted;
	int		tmp;
	double	tmp_dist;

	sorted = 1;
	while (sorted)
	{
		sorted = 0;
		j = -1;
		while (++j < n_spris - 1)
		{
			if (spri_dist[j] < spri_dist[j + 1])
			{
				tmp_dist = spri_dist[j + 1];
				spri_dist[j + 1] = spri_dist[j];
				spri_dist[j] = tmp_dist;
				tmp = spri_ord[j + 1];
				spri_ord[j + 1] = spri_ord[j];
				spri_ord[j] = tmp;
				sorted = 1;
			}
		}
	}
	return (1);
}

int			ft_calc_sprite_order(t_game *jeu, int *spri_ord)
{
	int		i;
	double	spri_dist[jeu->lev->n_spris];

	i = 0;
	while (i < jeu->lev->n_spris)
	{
		spri_ord[i] = i;
		spri_dist[i] = ((jeu->me->pos.x - jeu->lev->spris_tab[i].pos.x) \
						* (jeu->me->pos.x - jeu->lev->spris_tab[i].pos.x) \
						+ (jeu->me->pos.y - jeu->lev->spris_tab[i].pos.y) \
						* (jeu->me->pos.y - jeu->lev->spris_tab[i].pos.y));
		++i;
	}
	if (!(ft_sort_sprites(spri_ord, spri_dist, jeu->lev->n_spris)))
		return (0);
	return (1);
}
