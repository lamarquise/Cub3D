

#include "cub3d.h"


// all the stuff that runs the game...



int		ft_hud_port(t_game *jeu)
{
	if (jeu)	// tmp, remove
		return (0);
//	ft_gen_bground(jeu);	// secure ?

//	mlx_put_image_to_window(jeu->mlx->ptr, jeu->hud->win->win_ptr, \
//		jeu->hud->bground->img_ptr, 0, 0);

	ft_hooks_loop(jeu->hud);

	return (1);
}

	// may rename
	// this is where all the functions that edit the img are called.
int		ft_map_port(t_game *jeu)
{	
	ft_make_2D_floor_img(jeu);	// secure ?

	ft_make_map_fov(jeu);




	mlx_put_image_to_window(jeu->mlx->ptr, jeu->map->win->win_ptr, \
		jeu->map->img->img_ptr, G, G);


	// multiple imgs overlaying each other is not really an option...


	// solution: ? multiple functions that edit in layers the same img
	// in a particular order

	// otherwise would have to dynamically change the size of dif imgs
	// that's not happening, way too complicated...


	ft_hooks_loop(jeu->map);		// a hooks for each wind ???	
	return (1);
}

int		ft_master_port(t_game *jeu)
{
	if (!ft_master_init(jeu))
		return (ft_error_msg("init game failed\n"));


	ft_map_port(jeu);	// secure ??

//	ft_play_port(jeu);
	
	mlx_loop(jeu->mlx->ptr);
	return (1);
}
