/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 02:07:19 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 21:24:37 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_2d_to_1d(int x, int y, int width)
{
	return (x + y * width);
}

int		ft_rgb_to_int(int r, int g, int b, int t)
{
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
	if (t > 255)
		t = 255;
	else if (t < 0)
		t = 0;
	return (t << 24 | r << 16 | g << 8 | b);
}

	// ok so we're saying we've already done the math to translate x,y 2D coords to
	// 1D table coords
	// could do x and y rather than pos if wanted cuz have img wid & hei...
	// leave for now
//		ft_pix_img
int		ft_pix_imge(t_imge *img, int pos, int color)
{
	if (!img || pos < 0 || pos >= img->last_pix)// last_pix + 1? + y ? not sure, best no
		return (0);
	(img->img_data)[pos] = color;
	return (1);
}

int		ft_draw_col_to_imge(t_imge *img, int start_row, int end_row, int col, int color)
{
	int		pos;

//	printf("s row: %d, e row: %d, col: %d, color: %d\n", start_row, end_row, col, color);

	if (!img || start_row < 0 || end_row > img->img_hei)
		return (ft_error_msg("bad draw col inputs\n", 0));
	while (start_row < end_row)
	{
		pos = col + start_row * img->img_wid;
		if (!ft_pix_imge(img, pos, color))
			return (0);
		++start_row;
	}
	return (1);
}
