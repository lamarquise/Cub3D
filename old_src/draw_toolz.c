/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_toolz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:28:32 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/17 16:28:43 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int		ft_fill_imge_with(t_imge *img, int color)
{
	int		i;

	if (!img)
		return (0);
	i = 0;
	while (i < img->last_pix)
		img->img_data[i++] = color;
	return (1);
}

int		ft_draw_crosshairs(t_imge *img, int center, int size_fact, int color)
{
	int		i;

	i = 1;
	while (i < size_fact + 1)
	{
		img->img_data[center - i - 1] = color;
		img->img_data[center - i - 1 - img->img_wid] = color;
		img->img_data[center + i] = color;
		img->img_data[center + i - img->img_wid] = color;
		img->img_data[center - (i + 1) * img->img_wid] = color;
		img->img_data[center - (i + 1) * img->img_wid - 1] = color;
		img->img_data[center + i * img->img_wid] = color;
		img->img_data[center + i * img->img_wid - 1] = color;
		++i;
	}
	return (1);
}

	// void ??
int		ft_draw_rect(t_imge *img, int start, int r_wid, int r_hei, int color)
{
	int		x;
	int		y;

	// sercure ???

	y = 0;
	while (y < r_hei)
	{
		x = 0;
		while (x < r_wid)
		{
			img->img_data[(start + x + y * img->img_wid)] = color;
			++x;
		}
		++y;
	}
	return (1);
}


