/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:57:12 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/29 15:13:01 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parse_optional_input(t_game *jeu, char **tab)
{
	int		ret;

	if (!jeu || !tab)
		return (0);
	ret = 0;
	if (!(jeu->bbol & BEX) && !ft_strcmp(tab[0], "X"))
		ret = (ft_parse_sprite_type_path(jeu->file, tab, 'X') > 0 ? 1 : 0);
	else if (!(jeu->bbol & BKE) && !ft_strcmp(tab[0], "Y"))
		ret = (ft_parse_sprite_type_path(jeu->file, tab, 'Y') > 0 ? 2 : 0);
	jeu->bbol |= (1 << ret);
	return (ret);
}

int		ft_parse_more_essencial(t_game *jeu, char **tab)
{
	int		ret;

	if (!jeu || !tab)
		return (0);
	ret = 0;
	if (!ft_strcmp(tab[0], "S"))
	{
		if (!jeu->set->bonus && jeu->sbol & TS1)
			return (ft_error_msg("Too many Sprites\n", 0));
		ret = (ft_parse_sprite_type_path(jeu->file, tab, 'S') > 0 ? 6 : 0);
	}
	else if (!(jeu->sbol & CFL) && !ft_strcmp(tab[0], "F"))
	{
		ret = (ft_parse_surfaces(tab, &jeu->file->floor) > 0 ? 7 : 0);
		if (!jeu->set->bonus && jeu->file->floor->path)
			return (ft_error_msg("Textured floor but not bonus\n", 0));
	}
	else if (!(jeu->sbol & CCE) && !ft_strcmp(tab[0], "C"))
	{
		ret = (ft_parse_surfaces(tab, &jeu->file->ceiling) > 0 ? 8 : 0);
		if (!jeu->set->bonus && jeu->file->ceiling->path)
			return (ft_error_msg("Textured ceiling but not bonus\n", 0));
	}
	return (ret);
}

int		ft_parse_essencial_input(t_game *jeu, char **tab)
{
	int		ret;

	if (!jeu || !tab)
		return (ft_error_msg("no jeu or no tab\n", 0));
	ret = 0;
	if (!(jeu->sbol & RES) && !ft_strcmp(tab[0], "R"))
		ret = (ft_parse_res(tab, jeu->file) > 0 ? 1 : 0);
	else if (!(jeu->sbol & TNO) && !ft_strcmp(tab[0], "NO"))
		ret = (ft_parse_path_to_texture(tab, &jeu->file->no) > 0 ? 2 : 0);
	else if (!(jeu->sbol & TSO) && !ft_strcmp(tab[0], "SO"))
		ret = (ft_parse_path_to_texture(tab, &jeu->file->so) > 0 ? 3 : 0);
	else if (!(jeu->sbol & TWE) && !ft_strcmp(tab[0], "WE"))
		ret = (ft_parse_path_to_texture(tab, &jeu->file->we) > 0 ? 4 : 0);
	else if (!(jeu->sbol & TEA) && !ft_strcmp(tab[0], "EA"))
		ret = (ft_parse_path_to_texture(tab, &jeu->file->ea) > 0 ? 5 : 0);
	else
		ret = ft_parse_more_essencial(jeu, tab);
	jeu->sbol |= (1 << ret);
	return (ret);
}

int		ft_check_input_values(t_game *jeu, char *line, char **tab, int *map)
{
	if (!jeu || !tab || !map)
		return (0);
	if (tab[0][0] <= 'W' && tab[0][0] >= 'C')
	{
		if (!ft_parse_essencial_input(jeu, tab))
			return (ft_error_msg("bad essencial input\n", 0));
	}
	else if ((tab[0][0] == 'X' || tab[0][0] == 'Y'))
	{
		if (!ft_parse_optional_input(jeu, tab))
			return (ft_error_msg("bad optional input\n", 0));
	}
	else
		*map = 1;
	if (!*map && (*line && *tab && **tab && tab[0][0] != line[0]))
		return (0);
	return (1);
}

int		ft_parse_line(t_game *jeu, char *line, t_nlist **floor, int *map)
{
	char	**tab;

	if (!jeu || !line || !floor || !map || !(tab = ft_split(line, " ")))
		return (0);
	if (ft_strlen(line) > 0 && ft_expected_size(tab, 0))
	{
		ft_free_strtab(tab);
		return (ft_error_msg("parse line bad line\n", 0));
	}
	if (!*map && !ft_expected_size(tab, 0))
	{
		if (!ft_check_input_values(jeu, line, tab, map))
		{
			ft_free_strtab(tab);
			return (0);
		}
	}
	if (*map && !ft_nlstadd_back(floor, ft_nlstnew(ft_strdup(line), 0)))
	{
		ft_free_strtab(tab);
		return (ft_error_msg("parse line failed\n", 0));
	}
	ft_free_strtab(tab);
	return (1);
}
