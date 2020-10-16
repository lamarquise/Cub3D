/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:46:53 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/16 04:05:42 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// May need to double secure some things, make sure free if fails


#include "cub3d.h"

	// new line parsing algo, we grab each line, send it, once get to map
	// start storing in linked list


			// have to get rid of bol, and why not file too
int		ft_get_file_lines(int fd, t_game *jeu, t_nlist **floor)
{
	int		i;
	int		map;
//	int		len;
	int		ret;
	char	*s;		// if gnl fail does s get free'd ???
	char	*line;

	i = 0;
	map = 0;
//	s = NULL;	// will this work ???
	s = ft_strnew(1);	// better way of doing this ?
	line = NULL;
	while ((ret = gnl(&line, &s, 42, fd)) > 0)
	{

		if (!ft_parse_line(jeu, line, floor, &map))
			return (ft_error_msg("parse line failed\n", 0));
/*
//		printf("%s\n", line);
		if (*bol < 511)
		{
			if (!ft_parse_line(jeu, file, line, bol))
				return (ft_error_msg("parse line failed\n", 0));
//			printf("bol: %d\n", *bol);
			++i;
		}
		else if (*bol == 511 && !ft_nlstadd_back(floor, ft_nlstnew(ft_strdup(line), 0)))
			return (ft_error_msg("parse line failed\n", 0)); // also free everything
*/

		ft_scott_free(&line, 0);	// worth it ???
	}
//	ft_print_nlist(*floor);
	if (!*floor || jeu->sbol < 511)
		return (ft_error_msg("incorrect file\n", 0));

	// need a check all but floor func called here

	return (1);
}

								// send both jeu and file ???
int		ft_parse_file(int fd, t_game *jeu)
{
	t_nlist		*floor;	// may not need this.... keep here for copy floor
	t_player	*me;
//	t_nlist		*floors;	// the linked list of all the floor plans

	// free if error to be set up...

	floor = NULL;
//	floors = NULL;
	if (!(ft_get_file_lines(fd, jeu, &floor)))
		return (ft_error_msg("file reader failed\n", 0));
	if (jeu->file->nsprites < 1)	// temporary ??
		return (ft_error_msg("file reader, no sprite\n", 0));
	
	if (!(me = malloc(sizeof(t_player))))
		return (0);
	me->life = 100;
	jeu->me = me;		// don't init here ???

//	ft_print_nlist(floor);

	if (!ft_collect_levels(jeu, floor))
		return (ft_error_msg("failed to copy floor\n", 0));

	if (!ft_nlstdel_all(&floor))	// can i del_all in copy floor ?
		return (ft_error_msg("failed to del nlst floor\n", 0));

	if (!ft_unpack_wall_textures(jeu))
		return (ft_error_msg("failed to unpack textures in file parser\n", 0));

	if (jeu->set->bonus && !ft_unpack_texture(jeu, jeu->b_file->exit))
		return (ft_error_msg("failed to unpack exit texture in file parser\n", 0));


	if (jeu->set->bonus && jeu->file->floor && jeu->file->floor->path != NULL \
		&& !ft_unpack_texture(jeu, jeu->file->floor))
	{
		printf("testing floor texture unpacking\n");
		return (ft_error_msg("failed to unpack floor texture in file parser\n", 0));
	}
	if (jeu->set->bonus && jeu->file->ceiling->path \
		&& !ft_unpack_texture(jeu, jeu->file->ceiling))
		return (ft_error_msg("failed to unpack ceiling texture in file parser\n", 0));

		printf("done parsing\n");

	return (1);
}






