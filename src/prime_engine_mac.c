/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime_engine_mac.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 22:39:21 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/25 22:42:06 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_prime_engine(t_game *jeu)
{
	jeu->fog = 100;
	if (!(jeu->win = ft_create_wind(jeu->mlx, "Cub3D", \
		jeu->file->res.x, jeu->file->res.y)))
		return (0);
	return (1);
}
