/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_entities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:25:56 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 15:16:47 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_imge	*ft_init_imge(void)
{
	t_imge	*new;

	if (!(new = malloc(sizeof(t_imge))))
		return (NULL);
	new->img_ptr = NULL;
	new->img_data = NULL;
	new->img_wid = -1;
	new->img_hei = -1;
	return (new);
}

t_imge	*ft_create_imge(t_lmlx *mlx, int x, int y)
{
	t_imge	*new;

	if (!mlx)
		return (NULL);
	new = NULL;
	if (!(new = malloc(sizeof(t_imge))))
		return (NULL);
	if (!(new->img_ptr = mlx_new_image(mlx->ptr, x, y)) \
		|| !(new->img_data = (int*)mlx_get_data_addr(new->img_ptr, \
		&mlx->bpp, &mlx->s_l, &mlx->endian)))
	{
		free(new);
		return (NULL);
	}
	new->img_wid = x;
	new->img_hei = y;
	new->last_pix = x * y;
	return (new);
}

t_wind	*ft_create_wind(t_lmlx *mlx, char *name, int x, int y)
{
	t_wind	*new;

	if (!mlx || !name)
		return (NULL);
	new = NULL;
	if (!(new = malloc(sizeof(t_wind))))
		return (NULL);
	if (!(new->win_ptr = mlx_new_window(mlx->ptr, x, y, name)))
	{
		free(new);
		return (NULL);
	}
	new->win_wid = x;
	new->win_hei = y;
	new->name = name;
	return (new);
}
