/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:18:14 by tlamart           #+#    #+#             */
/*   Updated: 2020/10/27 23:05:32 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"

int		ft_vert_up(t_imge *img, t_coords cs, int color)
{
	while (cs.y1 <= cs.y2)
	{
		img->img_data[cs.y1 * img->img_wid + cs.x1] = color;
		cs.y1 += 1;
	}
	return (1);
}

int		ft_hor_right(t_imge *img, t_coords cs, int color)
{
	while (cs.x1 <= cs.x2)
	{
		img->img_data[cs.y1 * img->img_wid + cs.x1] = color;
		cs.x1 += 1;
	}
	return (1);
}

int		ft_vert_down(t_imge *img, t_coords cs, int color)
{
	while (cs.y1 >= cs.y2)
	{
		img->img_data[cs.y1 * img->img_wid + cs.x1] = color;
		cs.y1 -= 1;
	}
	return (1);
}

int		ft_hor_left(t_imge *img, t_coords cs, int color)
{
	while (cs.x1 >= cs.x2)
	{
		img->img_data[cs.y1 * img->img_wid + cs.x1] = color;
		cs.x1 -= 1;
	}
	return (1);
}

int		ft_notbresenham(t_imge *img, t_coords cs, int color)
{
	if (cs.y1 < cs.y2)
		return (ft_vert_up(img, cs, color));
	else if (cs.x1 < cs.x2)
		return (ft_hor_right(img, cs, color));
	else if (cs.y1 > cs.y2)
		return (ft_vert_down(img, cs, color));
	else if (cs.x1 > cs.x2)
		return (ft_hor_left(img, cs, color));
	return (0);
}
