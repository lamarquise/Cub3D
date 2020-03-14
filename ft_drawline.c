/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:02:03 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/03 08:14:37 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	ft_positive_diff_dx_greater_than_dy(t_fdf *mlx, t_coord a,
		t_coord b, t_line err)
{
	while (a.x <= b.x)
	{
		mlx->img_data[mlx->map_origin + a.y
		* mlx->win_width + a.x] = mlx->color;
		a.x += 1;
		err.sign += err.x;
		if (err.sign < 0)
		{
			a.y += 1;
			err.sign += err.y;
		}
	}
}

void	ft_positive_diff_dy_greater_than_dx(t_fdf *mlx, t_coord a,
		t_coord b, t_line err)
{
	while (a.y <= b.y)
	{
		mlx->img_data[mlx->map_origin + a.y
		* mlx->win_width + a.x] = mlx->color;
		a.y += 1;
		err.sign += err.x;
		if (err.sign < 0)
		{
			a.x += 1;
			err.sign += err.y;
		}
	}
}

void	ft_negative_diff_dx_greater_than_dy(t_fdf *mlx, t_coord a,
		t_coord b, t_line err)
{
	while (a.x <= b.x)
	{
		mlx->img_data[mlx->map_origin + a.y
		* mlx->win_width + a.x] = mlx->color;
		a.x += 1;
		err.sign -= err.x;
		if (err.sign < 0)
		{
			a.y -= 1;
			err.sign += err.y;
		}
	}
}

void	ft_negative_diff_dy_greater_than_dx(t_fdf *mlx, t_coord a,
		t_coord b, t_line err)
{
	while (a.y >= b.y)
	{
		mlx->img_data[mlx->map_origin + a.y
		* mlx->win_width + a.x] = mlx->color;
		a.y -= 1;
		err.sign -= err.x;
		if (err.sign > 0)
		{
			a.x += 1;
			err.sign += err.y;
		}
	}
}
