/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:21:47 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/25 02:09:00 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_free_timge(t_game *jeu, t_imge *img)
{
	if (!jeu || !jeu->mlx)
		return (0);
	if (!img)
		return (1);
	if (jeu->mlx->ptr && img->img_ptr)
		mlx_destroy_image(jeu->mlx->ptr, img->img_ptr);
	// does this kill the data too ?
	// until we know one way or other don't use

//	if (jeu->mlx->ptr && img->img_ptr)
//		free(img->img_ptr);

	free(img);
	// can't set to NULL since don't know which one it is
	return (1);
}

	// looks good
int		ft_free_twind(t_game *jeu)
{
	if (!jeu || !jeu->mlx)
		return (0);
	if (!jeu->win)	// very redundant
		return (1);
	if (jeu->mlx->ptr && jeu->win->win_ptr)
		mlx_destroy_window(jeu->mlx->ptr, jeu->win->win_ptr);
	free(jeu->win);
	jeu->win = NULL;
	return (1);
}

	// looks good
int		ft_free_tlmlx(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (!jeu->mlx)	// redundant but clear
		return (1);
	if (jeu->mlx->ptr)
	{
		free(jeu->mlx->ptr);
		free(jeu->mlx);
		jeu->mlx = NULL;
	}
	return (1);
}
