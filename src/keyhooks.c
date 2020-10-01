/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 23:45:11 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/01 04:59:07 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d.h"


/*
int		ft_redraw(t_game *jeu)
{

	mlx_destroy_image(jeu->mlx->ptr, jeu->minimap->img_ptr);
	
	if (!(either->img->img_ptr = mlx_new_image(either->jeu->mlx->ptr,\
		either->img->img_wid, either->img->img_hei)))
		return (0);
	either->img->img_data = (int*)mlx_get_data_addr(either->img->img_ptr,\
	&either->jeu->mlx->bpp, &either->jeu->mlx->s_l,\
	&either->jeu->mlx->endian);

	ft_map_port(either->jeu);
	return (1);
}
*/

int		ft_redraw(t_game *jeu)
{
//	if (jeu->minimap->img_ptr)
//		mlx_destroy_image(jeu->mlx->ptr, jeu->minimap->img_ptr);	

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
	jeu->torch[key] = 1;
	return (1);	// may end up returning 0
}

int		ft_keyrelease(int key, t_game *jeu)
{
	jeu->torch[key] = 0;
	return (1);	// may end up returning 0
}

/*
void    ft_light_torch(t_key *torch)
{
	torch[0].keycode = 53;
	torch[0].f = ft_quit;
	torch[1].keycode = 13;
	torch[1].f = &ft_move_forward;
	torch[2].keycode = 1;
	torch[2].f = &ft_move_backward;
	torch[3].keycode = 0;
	torch[3].f = ft_move_left;
	torch[4].keycode = 2;
	torch[4].f = ft_move_right;
	torch[5].keycode = 46;
	torch[5].f = ft_map_or_not;
	torch[6].keycode = 124;
	torch[6].f = ft_rot_right;
	torch[7].keycode = 123;
	torch[7].f = ft_rot_left;
}

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

	// add all the other hooks

}

*/
