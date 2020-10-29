/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 00:38:51 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/29 13:54:14 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H

# include "mymlx.h"
# include "cub3d.h"

typedef struct	s_coords
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}				t_coords;

typedef struct	s_line
{
	int		x;
	int		y;
	int		sign;
}				t_line;

/*
**	Not Bresenham
*/

int				ft_vert_up(t_imge *img, t_coords cs, int color);
int				ft_hor_right(t_imge *img, t_coords cs, int color);
int				ft_vert_down(t_imge *img, t_coords cs, int color);
int				ft_hor_left(t_imge *img, t_coords cs, int color);
int				ft_notbresenham(t_imge *img, t_coords cs, int color);

/*
**	Bresenham
*/

void			ft_init_dir(t_line *d, t_coords *cs);
int				ft_pos_dif(t_imge *img, t_coords cs, t_line d, int color);
int				ft_neg_dif(t_imge *img, t_coords cs, t_line d, int color);
int				ft_bresenham(t_imge *img, t_coords cs, int color);

/*
**	Draw Line
*/

int				ft_pos_dif_dx_greater_than_dy(t_imge *img, t_coords cs,
				t_line err, int color);
int				ft_pos_dif_dy_greater_than_dx(t_imge *img, t_coords cs,
				t_line err, int color);
int				ft_neg_dif_dx_greater_than_dy(t_imge *img, t_coords cs,
				t_line err, int color);
int				ft_neg_dif_dy_greater_than_dx(t_imge *img, t_coords cs,
				t_line err, int color);

#endif
