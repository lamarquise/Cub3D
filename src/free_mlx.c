/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:21:47 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 23:46:39 by ericlazo         ###   ########.fr       */
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
	free(img);
	return (1);
}

int		ft_free_twind(t_game *jeu)
{
	if (!jeu || !jeu->mlx)
		return (0);
	if (!jeu->win)
		return (1);
	if (jeu->mlx->ptr && jeu->win->win_ptr)
		mlx_destroy_window(jeu->mlx->ptr, jeu->win->win_ptr);
	free(jeu->win);
	jeu->win = NULL;
	return (1);
}

int		ft_free_tlmlx(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (!jeu->mlx)
		return (1);
	if (jeu->mlx->ptr)
		free(jeu->mlx->ptr);
	free(jeu->mlx);
	jeu->mlx = NULL;
	return (1);
}
