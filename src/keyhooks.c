/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 23:45:11 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/04 02:43:19 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_redraw(t_game *jeu)
{
	// none of that gets done to player, maybe i don't need it for fpv ?	

	if (jeu->fpv->img_ptr)
		mlx_destroy_image(jeu->mlx->ptr, jeu->fpv->img_ptr);
	if (!(jeu->fpv->img_ptr = mlx_new_image(jeu->mlx->ptr,\
		jeu->fpv->img_wid, jeu->fpv->img_hei)))
		return (0);
	jeu->fpv->img_data = (int*)mlx_get_data_addr(jeu->fpv->img_ptr,\
		&jeu->mlx->bpp, &jeu->mlx->s_l, &jeu->mlx->endian);

	mlx_clear_window(jeu->mlx->ptr, jeu->win->win_ptr);		// secure ???
	if (!ft_draw_imges(jeu))
		return (0);
	return (1);
}

int		ft_keypress(int key, t_game *jeu)
{
//	usleep(1000);
/*	if ((key == 46 || key == 53) && jeu->torch[key] == 1)
		jeu->torch[key] = 0;
	else
*/		jeu->torch[key] = 1;
	return (1);
}

int		ft_keyrelease(int key, t_game *jeu)
{
//	if (key != 46 && key != 53)	// definitly fucks things up for the map display (flikers)
		jeu->torch[key] = 0;
	return (1);	// may end up returning 0
}



	// all the rest is defunct



/*
	// move to init ???
void    ft_light_torch(t_key *torch)
{
	torch[0].keycode = 53;
	torch[0].f = ft_quit;
	torch[1].keycode = 46;
	torch[1].f = ft_map;
	torch[2].keycode = 45;
	torch[3].f = ft_normal_or_not;

//	jeu->torch = torch;
}
*/
/*
int     ft_keyhooks(int keycode, t_game *jeu)
{
	static t_key    torch[20] = {{42, NULL}};
	int				i;

	i = 0;
	if (torch[0].keycode == 42)
		ft_light_torch(torch);
	while (i < 8)	// number of codes added
	{
		if (keycode == torch[i].keycode)
			return (torch[i].f(jeu));
		++i;
	}
	return (0);
}

void    ft_hooks_loop(t_game *jeu)
{
	mlx_hook(jeu->win->win_ptr, 2, 0, &ft_keyhooks, jeu);
	mlx_hook(jeu->win->win_ptr, 17, 0, &ft_quit, jeu);

		// didn't work...
//	mlx_loop_hook(jeu->mlx->ptr, ft_keycodes, jeu);
	// add all the other hooks
}
*/





