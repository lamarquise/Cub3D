/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:34:17 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/25 02:58:03 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// May need to double secure some things, make sure free if fails


#include "cub3d.h"

t_texture   *ft_new_ttexture(int value, char *path, t_imge *img)
{
	t_texture *new;

//	if (!path)
//		return (NULL);
	if (!(new = (t_texture*)malloc(sizeof(t_texture))))
		return (NULL);
	new->value = value;
	new->path = path;
	new->img = img;
	return (new);
}

		// more like make a tex and add it to a possibly non existant nlist
int         ft_add_tex_to_nlist(t_nlist **list, int value, char *path, t_imge *img)
{
	t_texture   *new;

	new = NULL;	// necessary ???
	if (!list || !path)  // not img because may send NULL to start with
		return (0);
	if (!(new = ft_new_ttexture(value, path, img)))
		return (ft_error_msg("failed to make new ttexture\n", 0));
	if (!ft_nlstadd_back(list, ft_nlstnew((void*)new, 0)))	//secure even if do func call
		return (ft_error_msg("failed to add to back of list\n", 0));// within other call
	return (1);
}


/*
	// only used for sprites, i think...
	// desperately need to free some shit
	// change so is unpacking from linked list of textures...
int     ft_unpack_textures(t_game *jeu)
{
	t_nlist		*tmp;
	t_texture	*tex;
	
	if (!jeu->mlx || !jeu->file->tex_list)
		return (0);
	tmp = jeu->file->tex_list;
	while (tmp)
	{
		if (!((t_texture*)tmp->content))	// is the cast necessary ???
			return (ft_error_msg("missing t_texture\n", 0));
		tex = (t_texture*)tmp->content;
		if (!tex->path)
			return (ft_error_msg("missing path\n", 0));
		if (!(tex->img = ft_init_imge()))
			return (ft_error_msg("init imge failed\n", 0));
		if (!ft_get_tex(jeu, tex->img, tex->path))
			return (ft_error_msg("xpm to imge failed\n", 0));
		tmp = tmp->next;
	}
	return (1);
}
*/

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

int		ft_unpack_texture(t_game *jeu, t_texture *tex)
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

int		ft_unpack_list_textures(t_game *jeu, t_nlist *list)
{
	t_nlist		*tmp;
	t_texture	*tex;

	if (!jeu->mlx || !list)
		return (0);
	tmp = list;
	while (tmp)
	{
		if (!((t_texture*)tmp->content))	// is the cast necessary ???
			return (ft_error_msg("missing t_texture\n", 0));
		tex = (t_texture*)tmp->content;
		if (!ft_unpack_texture(jeu, tex))
			return (ft_error_msg("failed to unpack t_texture\n", 0));
		tmp = tmp->next;
	}
	return (1);
}

int		ft_unpack_wall_textures(t_game *jeu)
{
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

