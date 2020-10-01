/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:29:06 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/21 23:07:01 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// also handle fpv img for now...
int		ft_init_minimap(t_game *jeu)
{
	int		x;
	int		y;

	x = jeu->x_boxes * (U + G) + G;		// these numbers could easily
	y = jeu->y_boxes * (U + G) + G;		// be changed...
//	if (!(jeu->mwin = ft_create_wind(jeu->mlx, "Map", x, y)))
//		return (0);
	x -= G;
	y -= G;
	if (!(jeu->minimap = ft_create_imge(jeu->mlx, x, y)))
		return (0);

		// full size imge ? for now...
	if (!(jeu->fpv = ft_create_imge(jeu->mlx, x, y)))
		return (0);

	ft_make_minimap_img(jeu);

	return (1);
}

int		ft_master_init(t_game *jeu)
{
	t_settings	*set;

	if (!(set = malloc(sizeof(t_settings))))
		return (0);
	jeu->set = set;

	if (!ft_init_minimap(jeu))
		return (ft_error_msg("init mapwin failed\n", 0));	// and free set

	// add more progressively

	return (1);
}
