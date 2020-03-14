

#include "cub3d.h"

void	ft_clear(t_mlx *mlx)
{
	printf("quit test 1\n");
	if (mlx->pic->img_ptr)// && mlx->img->img_data)
	{
		printf("quit test 1,5\n");
		mlx_destroy_image(mlx->ptr, mlx->pic->img_ptr);		// segfaults???
	}
	if (mlx->win_ptr)
	{
		mlx_clear_window(mlx->ptr, mlx->win_ptr);
		mlx_destroy_window(mlx->ptr, mlx->win_ptr);
	}
	printf("quit test 2\n");
}

int		ft_quit(t_mlx *mlx)
{
	ft_clear(mlx);
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
}


// specialized funcs for map windows vs FPS windows ???
