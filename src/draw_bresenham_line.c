/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bresenham_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 00:22:14 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/26 01:44:46 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


	// all ret void for now...

#include "bresenham.h"

int		ft_pos_dif_dx_greater_than_dy(t_imge *img, t_coords cs,
		t_line err, int color)
{
	while (cs.x1 <= cs.x2)
	{
		img->img_data[cs.y1 * img->img_wid + cs.x1] = color;
		cs.x1 += 1;
		err.sign += err.x;
		if (err.sign < 0)
		{
			cs.y1 += 1;
			err.sign += err.y;
		}
	}
	return (1);
}

int		ft_pos_dif_dy_greater_than_dx(t_imge *img, t_coords cs,
		t_line err, int color)
{
	while (cs.y1 <= cs.y2)
	{
		img->img_data[cs.y1 * img->img_wid + cs.x1] = color;
		cs.y1 += 1;
		err.sign += err.x;
		if (err.sign < 0)
		{
			cs.x1 += 1;
			err.sign += err.y;
		}
	}
	return (1);
}

int		ft_neg_dif_dx_greater_than_dy(t_imge *img, t_coords cs,
		t_line err, int color)
{
	while (cs.x1 <= cs.x2)
	{
		img->img_data[cs.y1 * img->img_wid + cs.x1] = color;
		cs.x1 += 1;
		err.sign -= err.x;
		if (err.sign < 0)
		{
			cs.y1 -= 1;
			err.sign += err.y;
		}
	}
	return (1);
}

int		ft_neg_dif_dy_greater_than_dx(t_imge *img, t_coords cs,
		t_line err, int color)
{
	while (cs.y1 >= cs.y2)
	{
		img->img_data[cs.y1 * img->img_wid + cs.x1] = color;
		cs.y1 -= 1;
		err.sign -= err.x;
		if (err.sign > 0)
		{
			cs.x1 += 1;
			err.sign += err.y;
		}
	}
	return (1);
}
