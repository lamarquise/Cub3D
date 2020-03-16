

#include "cub3d.h"

	// return the # for img_data[]

int		ft_coord_convert(t_wind *win, t_imge *img, int x_box, int y_box)
{
	int		ret;

	ret = 0;
	if (!win)		// dumb
		return (0);
		// adding y
//	ret += (win->win_hei / 2 - img->img_hei / 2 + y_box * (U + G) + U / 2) * win->win_wid;

		// adding x
//	ret += (win->win_wid / 2 - img->img_wid / 2 + x_box * (U + G) + U / 2);

	ret += (y_box * (U + G) + U / 2) * img->img_wid;
	ret += x_box * (U + G) + U / 2;



	return (ret);
}


int		ft_2D_to_1D(int x, int y, int width)
{
	return (x + y * width);
}
