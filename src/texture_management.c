/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:34:17 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 01:51:05 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*ft_new_ttexture(int value, char *path, t_imge *img)
{
	t_texture *new;

	if (!(new = (t_texture*)malloc(sizeof(t_texture))))
		return (NULL);
	new->value = value;
	new->path = path;
	new->img = img;
	return (new);
}

int			ft_add_tex_to_nlist(t_nlist **list, int value, char *path, \
			t_imge *img)
{
	t_texture	*new;

	if (!list || !path)
		return (0);
	new = NULL;
	if (!(new = ft_new_ttexture(value, path, img)))
		return (ft_error_msg("failed to make new ttexture\n", 0));
	if (!ft_nlstadd_secback(list, (void*)new))
	{
		free(new);
		return (ft_error_msg("failed to add to back of list\n", 0));
	}
	return (1);
}
