/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:30:56 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/26 04:09:56 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

	// move

int     ft_expected_size(char **tab, int e)
{
	int		i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		++i;
	return (i == e ? 1 : 0);
}

int		ft_parse_res(char **tab, t_input *file)
{
	int		x;
	int		y;

	if (!tab || !file)
		return (0);
	if (!ft_expected_size(tab, 3))
		return (ft_error_msg("res wrong tab size\n", 0));
	if (file->res.x > 0 || file->res.y > 0)
		return (ft_error_msg("res already inited\n", 0));
	x = ft_atoi(tab[1]);
	y = ft_atoi(tab[2]);
	if (x < 200 || y < 200)
		return (ft_error_msg("res inputes too small\n", 0));
	file->res.x = x;
	file->res.y = y;
	return (1);
}

int		ft_parse_sprite_type_path(t_input *file, char **tab, char id)
{
	char	*path;
	t_nlist *new;

	path = NULL;
	new = NULL;
	if (!file || !tab)
		return (0);
	if (id == 'S')
	{
		id = 50 + file->n_spri_types;
		++file->n_spri_types;
	}
	if (!ft_expected_size(tab, 2) || !ft_check_str_end(tab[1], ".xpm"))
		return (ft_error_msg("bad .xpm file\n", 0));
	if (!(path = ft_strdup(tab[1])))
		return (ft_error_msg("path dup failed\n", 0));
	if (!ft_add_tex_to_nlist(&file->spri_type_texs, (int)id, path, NULL))
	{
		free(path);
		return (ft_error_msg("failed to add tex to nlist\n", 0));
	}
	return (1);
}

int		ft_parse_path_to_texture(char **tab, t_texture **tex)
{
	if (!tab || !tex)
		return (0);
	if (!ft_expected_size(tab, 2))
		return (ft_error_msg("path wrong tab size\n", 0));
	if (*tex)
		return (ft_error_msg("already a texture\n", 0));
	if (!ft_check_str_end(tab[1], ".xpm"))		// or png eventually
		return (ft_error_msg("not an .xpm file\n", 0));
	if (!(*tex = ft_new_ttexture(0, ft_strdup(tab[1]), NULL)))
		return (ft_error_msg("failed to create a ttex\n", 0));
	return (1);
}

	// split in 2 ?
int		ft_parse_colors(char **tab, t_texture **surface)
{
	int		r;
	int		g;
	int		b;
	char	**nums;

	if (!tab || !surface)
		return (0);
	if (*surface || !ft_expected_size(tab, 2) || !(nums = ft_split(tab[1], ",")))
		return (ft_error_msg("already a surface or  wrong tab size\n", 0));
	if (ft_expected_size(nums, 3))
	{
		if (!ft_str_isdigit(nums[0]) || !ft_str_isdigit(nums[1]) \
			|| !ft_str_isdigit(nums[2]))
		{
			ft_free_strtab(nums);
			return (ft_error_msg("color in file isn't a number\n", 0));
		}
		r = ft_atoi(nums[0]);
		g = ft_atoi(nums[1]);
		b = ft_atoi(nums[2]);
		if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		{
			ft_free_strtab(nums);
			return (ft_error_msg("color inputs not btw 0 and 255 inclusive\n", 0));
		}
		if (!(*surface = ft_new_ttexture(-1, NULL, NULL)))
		{
			ft_free_strtab(nums);
			return (ft_error_msg("failed to create a ttex\n", 0));
		}
		(*surface)->value = ft_rgb_to_int(r, g, b, 0);
	}
	else if (ft_expected_size(nums, 1) && !ft_parse_path_to_texture(tab, surface))
	{
		ft_free_strtab(nums);
		return (ft_error_msg("failed to parse path to texture\n", 0));
	}
	ft_free_strtab(nums);
	return (1);
}

