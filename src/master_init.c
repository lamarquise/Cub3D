

#include "cub3d.h"

int		ft_init_hud(t_game *jeu)
{
	// modify res x and y if they are bigger than screen
	// how big is sceen ????

	int		x;
	int		y;

	x = jeu->file->res_x;
	y = jeu->file->res_y;					// dif name ???
	if (!(jeu->hud->win = ft_create_wind(jeu->mlx, "HUD", x, y)))
		return (0);
	if (!(jeu->hud->img = ft_create_imge(jeu->mlx, x, y)))
		return (0);

	jeu->map->jeu = jeu;	// links back to itself

	// more ???

	return (1);
}

int		ft_init_map(t_game *jeu)
{
	int		x;
	int		y;

	x = jeu->x_boxes * (U + G) + G;		// these numbers could easily
	y = jeu->y_boxes * (U + G) + G;		// be changed...
	if (!(jeu->map->win = ft_create_wind(jeu->mlx, "Map", x, y)))
		return (0);
	x -= G * 2;
	y -= G * 2;
	if (!(jeu->map->img = ft_create_imge(jeu->mlx, x, y)))
		return (0);

	jeu->map->jeu = jeu;	// links back to itself
	return (1);
}

int		ft_master_init(t_game *jeu)
{
	t_lmlx		*mlx;
	t_screen	*map;
	t_screen	*hud;

	if (!(mlx = malloc(sizeof(t_lmlx))))
		return (0);
	if (!(map = malloc(sizeof(t_screen))))
		return (0);
	if (!(hud = malloc(sizeof(t_screen))))
		return (0);

	jeu->mlx = mlx;
	jeu->map = map;
	jeu->hud = hud;
	mlx->ptr = mlx_init();	// secure ???

	if (!ft_init_map(jeu))
		return (ft_error_msg("init mapwin failed\n"));

//	if (!ft_init_hud(jeu))
//		return (ft_error_msg("init playwin failed\n"));

	// create map floor img here ??

	return (1);
}
