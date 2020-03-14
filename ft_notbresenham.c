/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_notbresenham.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:18:14 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/03 08:32:24 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_vert_up(t_fdf *mlx, t_coord a, t_coord b)
{
	while (a.y <= b.y)
	{
		mlx->img_data[mlx->map_origin + a.y
		* mlx->win_width + a.x] = mlx->color;
		a.y += 1;
	}
}

static void	ft_hor_right(t_fdf *mlx, t_coord a, t_coord b)
{
	while (a.x <= b.x)
	{
		mlx->img_data[mlx->map_origin + a.y
		* mlx->win_width + a.x] = mlx->color;
		a.x += 1;
	}
}

static void	ft_vert_down(t_fdf *mlx, t_coord a, t_coord b)
{
	while (a.y >= b.y)
	{
		mlx->img_data[mlx->map_origin + a.y
		* mlx->win_width + a.x] = mlx->color;
		a.y -= 1;
	}
}

static void	ft_hor_left(t_fdf *mlx, t_coord a, t_coord b)
{
	while (a.x >= b.x)
	{
		mlx->img_data[mlx->map_origin + a.y
		* mlx->win_width + a.x] = mlx->color;
		a.x -= 1;
	}
}

void		ft_notbresenham(t_fdf *mlx, t_coord a, t_coord b)
{
	if (a.y < b.y)
		return (ft_vert_up(mlx, a, b));
	else if (a.x < b.x)
		return (ft_hor_right(mlx, a, b));
	else if (a.y > b.y)
		return (ft_vert_down(mlx, a, b));
	else if (a.x > b.x)
		return (ft_hor_left(mlx, a, b));
}
