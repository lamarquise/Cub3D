

#include "cub3d.h"

	// return the # for img_data[]

int		ft_coord_convert(t_mlx *mlx, t_map *file, int x_box, int y_box)
{
	int		ret;

	ret = 0;
		// adding y
	ret += (mlx->win_hei / 2 - mlx->pic->img_hei / 2 + y_box * U + U / 2) * mlx->win_wid;

		// adding x
	ret += (mlx->win_wid / 2 - mlx->pic->img_wid / 2 + x_box * U + U / 2);

}
