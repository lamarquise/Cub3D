/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:57:12 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/23 22:47:35 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


	// Is there a more efficient way of doing strcmp...
	// Check freeing, especially in error conditions.


#include "cub3d.h"

int		ft_parse_optional_input(t_game *jeu, char **tab)
{
	int		ret;

	ret = 0;
	if (!(jeu->bbol & BEX) && !ft_strcmp(tab[0], "X"))
		ret = (ft_parse_sprite_type_path(jeu->file, tab, 'X') > 0 ? 1 : 0);
	else if (!(jeu->bbol & BKE) && !ft_strcmp(tab[0], "Y"))
		ret = (ft_parse_sprite_type_path(jeu->file, tab, 'Y') > 0 ? 2 : 0);
/*	else if (!(jeu->bbol & BOP) && !ft_strcmp(tab[0], "Z"))
		ret = (ft_parse_sprite_type_path(jeu->file, tab, 'Z') > 0 ? 3 : 0);
*/
	jeu->bbol |= (1 << ret);
	return (ret);
}

	// could break into 2 funcs if need the room
int		ft_parse_essencial_input(t_game *jeu, char **tab)
{
	int		ret;

	if (!jeu || !tab)	// or file or bol ???
		return (ft_error_msg("no jeu or no tab\n", 0));
	ret = 0;
		// maybe...
	if (ft_strlen(tab[0]) == 0)
		return (1);

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
	else if (!ft_strcmp(tab[0], "S"))
	{
		if (!jeu->set->bonus && jeu->sbol & TS1)
			return (ft_error_msg("Too many Sprites\n", 0));
		ret = (ft_parse_sprite_type_path(jeu->file, tab, 'S') > 0 ? 6 : 0);
	}
	else if (!(jeu->sbol & CFL) && !ft_strcmp(tab[0], "F"))
		ret = (ft_parse_colors(tab, &jeu->file->floor) > 0 ? 7 : 0);
	else if (!(jeu->sbol & CCE) && !ft_strcmp(tab[0], "C"))
		ret = (ft_parse_colors(tab, &jeu->file->ceiling) > 0 ? 8 : 0);

	jeu->sbol |= (1 << ret);
//	printf("ret: %d, bol: %d\n", ret, *bol);
//	printf("parse line ret: %d\n", ret);
	return (ret);
}

int		ft_parse_line(t_game *jeu, char *line, t_nlist **floor, int *map)
{
	char	**tab;

	tab = NULL;
	if (!line)
		return (ft_error_msg("no line\n", 0));
	tab = ft_split(line, " ");	// secure ???	// rework split
	if (!*map && !ft_expected_size(tab, 0))
	{
		if (tab[0][0] <= 'W' && tab[0][0] >= 'C')
		{
			if (!ft_parse_essencial_input(jeu, tab))
				return (ft_error_msg("bad essencial input\n", 0));
		}
		else if (tab[0][0] == 'X' || tab[0][0] == 'Y')
		{
			if (!ft_parse_optional_input(jeu, tab))
				return (ft_error_msg("bad optional input\n", 0));
		}
		else
			*map = 1;

//		if (jeu->file->floor && jeu->file->floor->path)
//			printf("floor path: %s\n", jeu->file->floor->path);
	}
	if (*map && !ft_nlstadd_back(floor, ft_nlstnew(ft_strdup(line), 0)))
			return (ft_error_msg("parse line failed\n", 0)); // also free everything
	ft_free_strtab(tab);
	return (1);
}



