/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:34:17 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/20 02:00:28 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// May need to double secure some things, make sure free if fails


#include "cub3d.h"

t_texture   *ft_new_ttexture(void *path, void *img)
{
	t_texture *new;

	if (!(new = malloc(sizeof(t_texture))))
		return (NULL);
	new->path = path;
	new->img = img;
	return (new);
}

int         ft_add_texture(t_game *jeu, void *path, void *img)
{
	t_texture   *new;

	if (!jeu || !path || !img)  // may not be right ?
		return (0);
	if (!(new = ft_new_ttexture(path, img)))
		return (ft_error_msg("failed to make new ttexture\n", 0));
	if (!ft_nlstadd_back(&jeu->tex_list, ft_nlstnew((void*)new, 0)))
		return (ft_error_msg("failed to add to back of list\n", 0));
	return (1);
}

int		ft_get_tex(t_game *jeu, t_imge *img, char *path)
{

//	printf("path: %s\n", path);

	if (!(img->img_ptr = mlx_xpm_file_to_image(jeu->mlx->ptr, \
		path, &img->img_wid, &img->img_hei)))
		return (ft_error_msg("file to xpm failed\n", 0));
	if (!(img->img_data = (int*)mlx_get_data_addr(img->img_ptr, \
		&jeu->mlx->bpp, &jeu->mlx->s_l, &jeu->mlx->endian)))
		return (0);

	return (1);
}

int     ft_unpack_textures(t_game *jeu)
{
	t_nlist		*tmp;
	t_texture	*tex;

	if (!jeu->mlx || !jeu->tex_list)
		return (0);
	tmp = jeu->tex_list;
	while (tmp)
	{
		if (!((t_texture*)tmp->content))	// is the cast necessary ???
			return (ft_error_msg("missing t_texture\n", 0));
		tex = (t_texture*)tmp->content;
		if (!tex->path)
			return (ft_error_msg("missing path\n", 0));
		if (!(*((t_imge**)tex->img) = ft_init_imge()))
			return (ft_error_msg("init imge failed\n", 0));
		if (!ft_get_tex(jeu, *((t_imge**)tex->img), *((char**)tex->path)))
			return (ft_error_msg("xpm to imge failed\n", 0));
		tmp = tmp->next;
	}
	return (1);
}









