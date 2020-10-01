/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 02:07:19 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/30 02:03:39 by ericlazo         ###   ########.fr       */
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






