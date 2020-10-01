/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:32:40 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/19 23:46:23 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// all the stuff that runs the game...



int		ft_hud_port(t_game *jeu)
{

	printf("pre raycasting\n");

	ft_raycasting(jeu);

	printf("post raycasting\n");
	
	mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
		jeu->hud->img_ptr, 0, 0);

//	mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
//		jeu->file->so_tex->img_ptr, 0, 0);
	return (1);
}

	// may rename
int		ft_map_port(t_game *jeu)
{	
//	ft_make_2D_floor_img(jeu);	// secure ?

	int		x;
	int		y;

	x = jeu->win->win_wid - jeu->minimap->img_wid;	// do math elsewhere
	y = jeu->win->win_hei - jeu->minimap->img_hei;
	if (jeu->set->minimap == 1)
	{

		mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
			jeu->minimap->img_ptr, x, y);

		ft_place_player(jeu);
		mlx_put_image_to_window(jeu->mlx->ptr, jeu->win->win_ptr, \
			jeu->fpv->img_ptr, x, y);
	}
	return (1);
}

	// its basically a draw all... make better ???
int		ft_master_port(t_game *jeu)
{
//	ft_make_2D_floor_img(jeu);	// secure ?		// this does not work at all
//	mlx_put_image_to_window(jeu->mlx->ptr, jeu->mwin->win_ptr, \
//		jeu->map->img_ptr, G / 2, G / 2);

//	ft_hud_port(jeu);
	ft_map_port(jeu);	// secure ??

	return (1);
}

int		ft_master(t_game *jeu)
{
	if (!ft_master_init(jeu))		// call before master ???
		return (ft_error_msg("init game failed\n", 0));	// free somthing?

	if (!ft_master_port(jeu))
		return (ft_error_msg("master port failed\n", 0));	// free something?


//	mlx_loop_hook(jeu->mlx->ptr, ft_master_port, jeu);

	ft_hooks_loop(jeu);		// right place for the hook loop ?

	mlx_loop(jeu->mlx->ptr);	// and the mlx loop ?

	return (1);
}



