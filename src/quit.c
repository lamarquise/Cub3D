/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 23:46:18 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/21 23:02:47 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d.h"
/*
		// will make it clear more things eventually
void	ft_clear(t_screen *either)
{
	printf("quit test 1\n");
	if (either->img->img_ptr)// && mlx->img->img_data)
	{
		printf("quit test 1,5\n");
		mlx_destroy_image(either->jeu->mlx->ptr, either->img->img_ptr);		// segfaults???
	}
	if (either->win->win_ptr)
	{
		mlx_clear_window(either->jeu->mlx->ptr, either->win->win_ptr);
		mlx_destroy_window(either->jeu->mlx->ptr, either->win->win_ptr);
	}
	printf("quit test 2\n");
}

int		ft_quit(t_screen *either)
{
	ft_clear(either);
	exit(0);
}
*/

	// a temporary solution
	// should be fine tho..
	// do i need to free things ???.
int		ft_quit(t_game *jeu)
{
	if (jeu->minimap && jeu->minimap->img_ptr)
		mlx_destroy_image(jeu->mlx->ptr, jeu->minimap->img_ptr);
	if (jeu->fpv && jeu->fpv->img_ptr)
		mlx_destroy_image(jeu->mlx->ptr, jeu->fpv->img_ptr);
	if (jeu->win->win_ptr)
	{
		mlx_clear_window(jeu->mlx->ptr, jeu->win->win_ptr);
		mlx_destroy_window(jeu->mlx->ptr, jeu->win->win_ptr);
	}
	exit(0);
	return (1);
}


/*
int		ft_quit_all(t_game *jeu)
{

	exit(0); // here instead ???
}
*/

	// useful ???
	// void for now
void        ft_clear_imge(t_lmlx *mlx, t_imge *img)
{
	mlx_destroy_image(mlx->ptr, img->img_ptr);
	free(img);  // use a **img so i can scott free ??? or set to NULL ???
}



