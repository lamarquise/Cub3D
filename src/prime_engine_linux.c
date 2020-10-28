/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime_engine_linux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 22:50:06 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 15:50:09 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_prime_engine(t_game *jeu)
{
	int		screen_x;
	int		screen_y;

	if (!jeu || !jeu->mlx || !jeu->mlx->ptr)
		return (0);
	jeu->fog = 100;
	mlx_get_screen_size(jeu->mlx->ptr, &screen_x, &screen_y);
	jeu->file->res.x = fmin(jeu->file->res.x, screen_x);
	jeu->file->res.y = fmin(jeu->file->res.y, screen_y);
	if (!(jeu->win = ft_create_wind(jeu->mlx, "Cub3D", \
		jeu->file->res.x, jeu->file->res.y)))
		return (0);
	return (1);
}
