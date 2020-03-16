

#include "cub3d.h"


// all the stuff that runs the game...



int		ft_play_port(t_game *jeu)
{
	ft_gen_bground(jeu);	// secure ?

	mlx_put_image_to_window(jeu->mlx->ptr, jeu->hud->win->win_ptr, \
		jeu->hud->bground->img_ptr, 0, 0);

//	ft_hooks_loop(jeu);

	return (1);
}

int		ft_init_playwin(t_game *jeu)
{
	// modify res x and y if they are bigger than screen
	// how big is sceen ????

	int		x;
	int		y;

	x = jeu->file->res_x;
	y = jeu->file->res_y;
	if (!(jeu->hud->win = ft_init_wind(jeu->mlx, "HUD", x, y)))
		return (0);

	if (!(jeu->hud->bground = ft_init_imge(jeu->mlx, x, y)))
		return (0);

	// other imgs...

	return (1);
}


int		ft_map_port(t_game *jeu)
{	
	ft_make_2D_floor_img(jeu);	// secure ?
	
	mlx_put_image_to_window(jeu->mlx->ptr, jeu->map->win->win_ptr, \
		jeu->map->floor->img_ptr, G, G);

	ft_make_map_fov(jeu);

	mlx_put_image_to_window(jeu->mlx->ptr, jeu->map->win->win_ptr, \
		jeu->map->fov->img_ptr, G, G);


	// multiple imgs overlaying each other is not really an option...


	// solution: ? multiple functions that edit in layers the same img
	// in a particular order

	// otherwise would have to dynamically change the size of dif imgs
	// that's not happening, way too complicated...





	ft_hooks_loop(jeu);		// a hooks for each wind ???	
	return (1);
}

int		ft_init_mapwin(t_game *jeu)
{
	// makes the window
	// makes the imgs	// does not fill the imgs

	int		x;
	int		y;

	x = jeu->x_boxes * (U + G) + G;		// these numbers could easily
	y = jeu->y_boxes * (U + G) + G;		// be changed...
	if (!(jeu->map->win = ft_init_wind(jeu->mlx, "Map", x, y)))
		return (0);
	x -= G * 2;
	y -= G * 2;
	if (!(jeu->map->floor = ft_init_imge(jeu->mlx, x, y)))
		return (0);

	if (!(jeu->map->fov = ft_init_imge(jeu->mlx, x, y)))
		return (0);

	// create map img here ???
//	jeu->map->fov = ???

	return (1);
}

int		ft_master_init(t_game *jeu)
{
	t_lmlx		*mlx;
	t_mapwin	*map;
	t_playwin	*hud;

	if (!(mlx = malloc(sizeof(t_lmlx))))
		return (0);
	if (!(map = malloc(sizeof(t_mapwin))))
		return (0);
	if (!(hud = malloc(sizeof(t_playwin))))
		return (0);

	jeu->mlx = mlx;
	jeu->map = map;
	jeu->hud = hud;
	mlx->ptr = mlx_init();	// secure ???

	if (!ft_init_mapwin(jeu))
		return (ft_error_msg("init mapwin failed\n"));

	if (!ft_init_playwin(jeu))
		return (ft_error_msg("init playwin failed\n"));

	// create map floor img here ??

	return (1);
}


int		ft_master_port(t_game *jeu)
{
	if (!ft_master_init(jeu))
		return (ft_error_msg("init game failed\n"));


	// create map floor img here ???

	ft_map_port(jeu);	// secure ??

//	ft_play_port(jeu);
	

	mlx_loop(jeu->mlx->ptr);

	return (1);
}
