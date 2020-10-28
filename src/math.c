/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 02:07:19 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 01:29:12 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect_i	ft_fill_vect_i(int x, int y)
{
	t_vect_i v;

	v.x = x;
	v.y = y;
	return (v);
}

int		ft_expected_size(char **tab, int e)
{
	int		i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		++i;
	return (i == e ? 1 : 0);
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

int		ft_pix_imge(t_imge *img, int pos, int color)
{
	if (!img || pos < 0 || pos >= img->last_pix)
		return (0);
	(img->img_data)[pos] = color;
	return (1);
}

int		ft_draw_col_to_imge(t_imge *img, t_vect_i row, int col, int color)
{
	int		pos;

	if (!img || row.x < 0 || row.y > img->img_hei)
		return (ft_error_msg("bad draw col inputs\n", 0));
	while (row.x < row.y)
	{
		pos = col + row.x * img->img_wid;
		if (!ft_pix_imge(img, pos, color))
			return (0);
		++row.x;
	}
	return (1);
}
