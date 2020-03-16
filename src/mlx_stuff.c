

#include "cub3d.h"

		// will make it clear more things eventually
void	ft_clear(t_game *jeu)
{
	printf("quit test 1\n");
	if (jeu->map->floor->img_ptr)// && mlx->img->img_data)
	{
		printf("quit test 1,5\n");
		mlx_destroy_image(jeu->mlx->ptr, jeu->map->floor->img_ptr);		// segfaults???
	}
	if (jeu->map->win->win_ptr)
	{
		mlx_clear_window(jeu->mlx->ptr, jeu->map->win->win_ptr);
		mlx_destroy_window(jeu->mlx->ptr, jeu->map->win->win_ptr);
	}
	printf("quit test 2\n");
}

int		ft_quit(t_game *jeu)
{
	ft_clear(jeu);
	exit(0);
}



// a function that inits/creats a new window


t_wind	*ft_init_wind(t_lmlx *mlx, char *name, int x, int y)
{
	t_wind	*new;

	new = NULL;
	if (!(new = malloc(sizeof(t_wind))))
		return (NULL);
	if (!(new->win_ptr = mlx_new_window(mlx->ptr, x, y, name)))
		return (NULL);
	new->win_wid = x;
	new->win_hei = y;
	new->name = name;	// necessary ???
	return (new);
}


// specialized funcs for map windows vs FPS windows ???
