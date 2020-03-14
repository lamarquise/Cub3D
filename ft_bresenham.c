/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:18:39 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/02 22:47:07 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_initd(t_line *d, t_coord *a, t_coord *b)
{
	d->x = b->x - a->x;
	d->y = b->y - a->y;
}

static void	ft_positive_diff(t_fdf *mlx, t_coord a, t_coord b, t_line d)
{
	if (d.x > d.y)
	{
		d.sign = d.x;
		d.x = -2 * d.y;
		d.y = 2 * d.sign;
		return (ft_positive_diff_dx_greater_than_dy(mlx, a, b, d));
	}
	else
	{
		d.sign = d.y;
		d.x *= -2;
		d.y = 2 * d.sign;
		return (ft_positive_diff_dy_greater_than_dx(mlx, a, b, d));
	}
}

static void	ft_negative_diff(t_fdf *mlx, t_coord a, t_coord b, t_line d)
{
	if (d.x > -d.y)
	{
		d.sign = d.x;
		d.x = -2 * d.y;
		d.y = 2 * d.sign;
		return (ft_negative_diff_dx_greater_than_dy(mlx, a, b, d));
	}
	else
	{
		d.sign = d.y;
		d.x *= -2;
		d.y = 2 * d.sign;
		return (ft_negative_diff_dy_greater_than_dx(mlx, a, b, d));
	}
}

void		ft_bresenham(t_fdf *mlx, t_coord a, t_coord b)
{
	t_line	d;

	if (b.x - a.x < 0)
		return (ft_bresenham(mlx, b, a));
	ft_initd(&d, &a, &b);
	if (d.x == 0 || d.y == 0)
		return (ft_notbresenham(mlx, a, b));
	else if (d.x > 0 && d.y > 0)
		return (ft_positive_diff(mlx, a, b, d));
	else
		return (ft_negative_diff(mlx, a, b, d));
}
