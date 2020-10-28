/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 02:11:49 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 01:24:12 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_prime_level(t_game *jeu)
{
	if (!jeu)
		return (0);
	ft_init_player(jeu, jeu->lev);
	if (!(jeu->fpv = ft_create_imge(jeu->mlx, jeu->file->res.x, \
		jeu->file->res.y)))
		return (0);
	if (!ft_generate_minimap(jeu, jeu->lev))
		return (ft_error_msg("Failed to generate minimap\n", 0));
	if (!(jeu->yah = ft_create_imge(jeu->mlx, jeu->grid_pixs.x, \
		jeu->grid_pixs.y)))
		return (0);
	if (!ft_generate_crosshair(jeu))
		return (0);
	return (1);
}

int		ft_set_level(t_game *jeu)
{
	int		i;
	t_nlist	*tmp;

	if (!jeu)
		return (0);
	tmp = jeu->level_list;
	i = 0;
	while (i < jeu->cur_level && tmp)
	{
		++i;
		tmp = tmp->next;
	}
	if (tmp)
	{
		jeu->lev = (t_level*)tmp->content;
		if (!ft_prime_level(jeu))
			return (ft_error_msg("failed to prime level\n", 0));
	}
	else if (!ft_quit(jeu))
		return (0);
	return (1);
}

int		ft_game_engine(t_game *jeu)
{
	if (!jeu)
		return (0);
	mlx_hook(jeu->win->win_ptr, 2, (1L << 0), &ft_keypress, jeu);
	mlx_hook(jeu->win->win_ptr, 3, (1L << 1), &ft_keyrelease, jeu);
	mlx_hook(jeu->win->win_ptr, 4, (1L << 2), &ft_mouse_press, jeu);
	mlx_hook(jeu->win->win_ptr, 6, (1L << 6), &ft_mouse_move, jeu);	// could be (1L << 8)
	mlx_hook(jeu->win->win_ptr, 17, (1L << 17), &ft_quit, jeu);
	mlx_loop_hook(jeu->mlx->ptr, ft_keycodes, jeu);
	mlx_loop(jeu->mlx->ptr);
	return (1);
}

int		ft_start_game(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (!ft_prime_engine(jeu))
		return (ft_error_msg("failed to prime engine\n", 0));
	if (!ft_set_level(jeu))
		return (ft_error_msg("failed to set level\n", 0));
	if (jeu->set->save && !ft_screenshot(jeu))
		return (ft_error_msg("failed to take screenshot\n", 0));
	else if (!ft_game_engine(jeu))
		return (ft_error_msg("engine failed\n", 0));
	return (1);
}
