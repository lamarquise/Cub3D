/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 01:33:03 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/12 02:17:11 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMLX_H
# define MYMLX_H

# include "mlx.h"

typedef struct	s_imge
{
	void		*img_ptr;
	int			*img_data;
	int			img_wid;
	int			img_hei;
	int			last_pix;
}				t_imge;

typedef struct	s_wind
{
	void		*win_ptr;
	int			win_wid;
	int			win_hei;
	char		*name;
}				t_wind;

typedef struct	s_lmlx
{
	void		*ptr;
	int			bpp;
	int			s_l;
	int			endian;
}				t_lmlx;

#endif
