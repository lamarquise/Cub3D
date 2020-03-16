


#include "cub3d.h"



int		ft_quit_map(t_mapwin *map, t_lmlx *mlx)
{

	if (map->floor && map->floor->img_ptr)
		mlx_destroy_image(mlx->ptr, map->floor->img_ptr);	// sercure ???
	if (map->fov && map->fov->img_ptr)
		mlx_destroy_image(mlx->ptr, map->fov->img_ptr);

	// add more imge's as need be...

	if (map->win && map->win->win_ptr)
	{
		mlx_clear_window(mlx->ptr, map->win->win_ptr);		// secure these?
		mlx_destroy_window(mlx->ptr, map->win->win_ptr);
	}

	// do i need to free things ?? like 

	// destroy imgs

	// clear wind
	// destroy wind

	// exit(0);	???


}


//int		ft_quit_hud()



int		ft_quit_all(t_game *jeu)
{
	ft_quit_map(jeu->map, jeu->mlx);

	//ft_quit_hud();

	exit(0);
}
