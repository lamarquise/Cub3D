

#include "cub3d.h"

t_imge      *ft_create_imge(t_lmlx *mlx, int x, int y)
{
	t_imge	*new;

	new = NULL;
	if (!(new = malloc(sizeof(t_imge))))
		return (NULL);
	if (!(new->img_ptr = mlx_new_image(mlx->ptr, x, y)))
		return (NULL);      // also free new...
	if (!(new->img_data = (int*)mlx_get_data_addr(new->img_ptr, \
		&mlx->bpp, &mlx->s_l, &mlx->endian)))
		return (NULL);      // also free...
	new->img_wid = x;
	new->img_hei = y;
	new->last_pix = x * y;
	return (new);
}

t_wind	*ft_create_wind(t_lmlx *mlx, char *name, int x, int y)
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
