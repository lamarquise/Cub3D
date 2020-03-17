

#include "cub3d.h"

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

/*
int		ft_quit_all(t_game *jeu)
{

	exit(0); // here instead ???
}
*/

	// void for now
void        ft_clear_imge(t_lmlx *mlx, t_imge *img)
{
	mlx_destroy_image(mlx->ptr, img->img_ptr);
	free(img);  // use a **img so i can scott free ??? or set to NULL ???
}
