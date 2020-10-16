/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:57:12 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/16 03:49:32 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


	// Is there a more efficient way of doing strcmp...
	// Check freeing, especially in error conditions.


#include "cub3d.h"


	// actually, very similar to ft_expected size...
	// seems redundant
	// put this in the lib
int		ft_strtab_size(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

int		ft_parse_optional_input(t_game *jeu, char **tab)
{
	int		ret;

	ret = 0;
	if (!(jeu->bbol & BEX) && !ft_strcmp(tab[0], "X"))
	{
//		if (!jeu->set->bonus)	// do before func is called !!!
//			return (ft_error_msg("Exit not allowed unless <--bonus>\n", 0));
//		printf("exit found\n");
		ret = (ft_parse_path_to_texture(tab, &jeu->b_file->exit) > 0 ? 1 : 0);

	}
	else if (!(jeu->bbol & BKE) && !ft_strcmp(tab[0], "Y"))
	{
		ret = (ft_parse_path_to_texture(tab, &jeu->b_file->key) > 0 ? 2 : 0);
	}
	else if (!(jeu->bbol & BOP) && !ft_strcmp(tab[0], "Z"))
	{
		ret = (ft_parse_path_to_texture(tab, &jeu->b_file->opener) > 0 ? 3 : 0);

	}

	jeu->bbol |= (1 << ret);
	return (ret);
}

	// sbol

			// can get rid of bol i think ? have the room now
	// could replace jeu with file again???
int		ft_parse_essencial_input(t_game *jeu, char **tab)
{
	int		ret;

	if (!jeu || !tab)	// or file or bol ???
		return (ft_error_msg("no jeu or no tab\n", 0));
	ret = 0;
//	tab = ft_split(line, " ");	// secure ???

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
	{		// could have an int sep from bool for n of sprites
		if (!jeu->set->bonus && jeu->sbol & TS1)
			return (ft_error_msg("Too many Sprites\n", 0));
		ret = (ft_parse_sprite_path(jeu->file, tab) > 0 ? 6 : 0);	// was 6, make 0 ?
	}
	else if (!(jeu->sbol & CFL) && ft_strcmp(tab[0], "F"))	// eventually floor texs
		ret = (ft_parse_colors(tab, &jeu->file->ceiling) > 0 ? 7 : 0);
	else if (!(jeu->sbol & CCE) && ft_strcmp(tab[0], "C"))
		ret = (ft_parse_colors(tab, &jeu->file->ceiling) > 0 ? 8 : 0);

//	ft_free_strtab(tab);
//	if (ret != 17)
		jeu->sbol |= (1 << ret);
//	else
//		ret = 1;
//	printf("ret: %d, bol: %d\n", ret, *bol);
//	printf("parse line ret: %d\n", ret);
	return (ret);
}

	// goes through lines, divying out until


int		ft_parse_line(t_game *jeu, char *line, t_nlist **floor, int *map)
{
	char	**tab;
	int		tabsize;

	if (!line)
		return (ft_error_msg("no line\n", 0));
	tab = ft_split(line, " ");	// secure ???	// rework split

	// not my favorit algo, may need reworking...
	tabsize = ft_strtab_size(tab);	// not gonna work cuz what if map has spaces in top
	if (!*map && tabsize > 0)				// line ???
	{
		// do prev line parser things
		// all non bonus stuff

		// use X Y and Z for exit key and change room (cuz greater than other letters!)
		if (tab[0][0] <= 'W' && tab[0][0] >= 'C')
		{

			if (!ft_parse_essencial_input(jeu, tab))
				return (ft_error_msg("bad essencial input\n", 0));
			// send to OG manager of things func with non bonus file !!!
			// figure out how to do textured floors later
			// i think sprite management is good tho
		}
		else if (tab[0][0] >= 'X' && tab[0][0] <= 'Z')
		{
			if (!ft_parse_optional_input(jeu, tab))
				return (ft_error_msg("bad optional input\n", 0));
			// a sort of equivalent func as above is called
			// but just handles bonus file stuff
		}
		else
			*map = 1;
		
	}

		// only useful if map == 0
//	if (ft_strlen(tab[0]) == 0)
//		return (1);


	// if can't be anything but a map, we do map
	// has to be at the end
	// everything before must rule out all other possibilities, valid and invalid

//	printf("map = %d\n", *map);

	if (*map && !ft_nlstadd_back(floor, ft_nlstnew(ft_strdup(line), 0)))
			return (ft_error_msg("parse line failed\n", 0)); // also free everything

	ft_free_strtab(tab);
	return (1);
}



