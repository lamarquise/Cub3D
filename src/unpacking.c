/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpacking.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:50:02 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 01:50:16 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_get_tex(t_game *jeu, t_imge *img, char *path)
{
	if (!jeu || !img || !path)
		return (0);
	if (!(img->img_ptr = mlx_xpm_file_to_image(jeu->mlx->ptr, \
		path, &img->img_wid, &img->img_hei)))
		return (ft_error_msg("file to xpm failed\n", 0));
	if (!(img->img_data = (int*)mlx_get_data_addr(img->img_ptr, \
		&jeu->mlx->bpp, &jeu->mlx->s_l, &jeu->mlx->endian)))
		return (0);
	return (1);
}

int			ft_unpack_texture(t_game *jeu, t_texture *tex)
{
	if (!jeu || !tex)
		return (ft_error_msg("missing jeu or tex\n", 0));
	if (!tex->path)
		return (ft_error_msg("missing path\n", 0));
	if (!(tex->img = ft_init_imge()))
		return (ft_error_msg("init imge failed\n", 0));
	if (!ft_get_tex(jeu, tex->img, tex->path))
		return (ft_error_msg("xpm to imge failed\n", 0));
	return (1);
}

int			ft_unpack_list_textures(t_game *jeu, t_nlist *list)
{
	t_nlist		*tmp;
	t_texture	*tex;

	if (!jeu || !jeu->mlx || !list)
		return (0);
	tmp = list;
	while (tmp)
	{
		if (!((t_texture*)tmp->content))
			return (ft_error_msg("missing t_texture\n", 0));
		tex = (t_texture*)tmp->content;
		if (!ft_unpack_texture(jeu, tex))
			return (ft_error_msg("failed to unpack t_texture\n", 0));
		tmp = tmp->next;
	}
	return (1);
}

int			ft_unpack_wall_textures(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (!ft_unpack_texture(jeu, jeu->file->no))
		return (0);
	if (!ft_unpack_texture(jeu, jeu->file->so))
		return (0);
	if (!ft_unpack_texture(jeu, jeu->file->ea))
		return (0);
	if (!ft_unpack_texture(jeu, jeu->file->we))
		return (0);
	return (1);
}
