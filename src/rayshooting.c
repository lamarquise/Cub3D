/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayshooting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 03:42:31 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 19:06:23 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect_d	ft_calc_delta_dist(t_vect_d ray)
{
	t_vect_d	delta_dist;

	if (ray.y == 0)
		delta_dist.x = 0;
	else if (ray.x == 0)
		delta_dist.x = 1;
	else
		delta_dist.x = fabs(1 / ray.x);
	if (ray.x == 0)
		delta_dist.y = 0;
	else if (ray.y == 0)
		delta_dist.y = 1;
	else
		delta_dist.y = fabs(1 / ray.y);
	return (delta_dist);
}

int			ft_dda(t_vect_i *map, t_vect_i *step, t_vect_d *side_dist, \
				t_vect_d *delta_dist)
{
	if (side_dist->x < side_dist->y)
	{
		side_dist->x += delta_dist->x;
		map->x += step->x;
		return (0);
	}
	else
	{
		side_dist->y += delta_dist->y;
		map->y += step->y;
		return (1);
	}
}

int			ft_shoot_ray(t_game *jeu, t_vect_d p_pos, t_vect_d ray, double *pwd)
{
	t_vect_d	side_dist;
	t_vect_d	delta_dist;
	t_vect_i	map;
	t_vect_i	step;
	int			side;

	map.x = (int)p_pos.x;
	map.y = (int)p_pos.y;
	delta_dist = ft_calc_delta_dist(ray);
	step.x = (ray.x < 0) ? -1 : 1;
	step.y = (ray.y < 0) ? -1 : 1;
	side_dist.x = (ray.x < 0) ? (p_pos.x - map.x) * delta_dist.x \
		: (map.x + 1.0 - p_pos.x) * delta_dist.x;
	side_dist.y = (ray.y < 0) ? (p_pos.y - map.y) * delta_dist.y \
		: (map.y + 1.0 - p_pos.y) * delta_dist.y;
	while (((char**)jeu->lev->floor)[map.y][map.x] != '1')
		side = ft_dda(&map, &step, &side_dist, &delta_dist);
	if (side == 0)
		*pwd = (map.x - p_pos.x + (1 - step.x) / 2) / ray.x;
	else
		*pwd = (map.y - p_pos.y + (1 - step.y) / 2) / ray.y;
	return (side);
}
