

#include "cub3d.h"

	// different params ??? return img instead ???
t_imge		*ft_init_imge(t_lmlx *mlx, int x, int y)
{
	t_imge	*new;

	new = NULL;
	if (!(new = malloc(sizeof(t_imge))))
		return (NULL);
	if (!(new->img_ptr = mlx_new_image(mlx->ptr, x, y)))
		return (NULL);		// also free new.
	if (!(new->img_data = (int*)mlx_get_data_addr(new->img_ptr, \
		&mlx->bpp, &mlx->s_l, &mlx->endian)))
		return (NULL);		// also free...
	new->img_wid = x;
	new->img_hei = y;
	new->last_pix = x * y;
	return (new);
}


	// void for now
void		ft_clear_imge(t_lmlx *mlx, t_imge *img)
{
	mlx_destroy_image(mlx->ptr, img->img_ptr);
	free(img);	// use a **img so i can scott free ??? or set to NULL ???
}


