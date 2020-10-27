/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 00:10:32 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/26 01:19:34 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"

void		ft_init_dir(t_line *d, t_coords *cs)
{
	d->x = cs->x2 - cs->x1;
	d->y = cs->y2 - cs->y1;
}

int		ft_pos_dif(t_imge *img, t_coords cs, t_line d, int color)
{
	if (d.x > d.y)
	{
		d.sign = d.x;
		d.x = -2 * d.y;
		d.y = 2 * d.sign;
		return (ft_pos_dif_dx_greater_than_dy(img, cs, d, color));
	}
	else
	{
		d.sign = d.y;
		d.x *= -2;
		d.y = 2 * d.sign;
		return (ft_pos_dif_dy_greater_than_dx(img, cs, d, color));
	}
}

int		ft_neg_dif(t_imge *img, t_coords cs, t_line d, int color)
{
	if (d.x > -d.y)
	{
		d.sign = d.x;
		d.x = -2 * d.y;
		d.y = 2 * d.sign;
		return (ft_neg_dif_dx_greater_than_dy(img, cs, d, color));
	}
	else
	{
		d.sign = d.y;
		d.x *= -2;
		d.y = 2 * d.sign;
		return (ft_neg_dif_dy_greater_than_dx(img, cs, d, color));
	}
}

int		ft_bresenham(t_imge *img, t_coords cs, int color)
{
	t_line	d;
	int		tmp;

	if (cs.x2 - cs.x1 < 0)
	{
		tmp = cs.x1;
		cs.x1 = cs.x2;
		cs.x2 = tmp;
		tmp = cs.y1;
		cs.y1 = cs.y2;
		cs.y2 = tmp;
		return (ft_bresenham(img, cs, color));
	}
	ft_init_dir(&d, &cs);
	if (d.x == 0 || d.y == 0)
		return (ft_notbresenham(img, cs, color));
	else if (d.x > 0 && d.y > 0)
		return (ft_pos_dif(img, cs, d, color));
	else
		return (ft_neg_dif(img, cs, d, color));
}
