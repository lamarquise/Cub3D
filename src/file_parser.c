/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:46:53 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/25 18:46:52 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// May need to double secure some things, make sure free if fails


#include "cub3d.h"

	// a temporary solution ???
	// not at all generic or modular...
int		ft_fill_tex_list(t_game *jeu)
{
	if (!ft_add_texture(jeu, &jeu->file->no_path, &jeu->file->no_tex))
		return (0);
	if (!ft_add_texture(jeu, &jeu->file->so_path, &jeu->file->so_tex))
		return (0);
	if (!ft_add_texture(jeu, &jeu->file->we_path, &jeu->file->we_tex))
		return (0);
	if (!ft_add_texture(jeu, &jeu->file->ea_path, &jeu->file->ea_tex))
		return (0);

	if (!ft_add_texture(jeu, &jeu->file->sprite_path, &jeu->file->sprite_tex))
		return (0);

	// would need to add more for more sprites or whatever
	// there must be a more efficient way...


	return (1);
}

int		ft_get_file_contents(int fd, t_input *file, t_nlist **floor, int *bol)
{
	int		i;
//	int		len;
	int		ret;
	char	*s;		// if gnl fail does s get free'd ???
	char	*line;


	i = 0;
//	s = NULL;	// will this work ???
	s = ft_strnew(1);	// better way of doing this ?
	line = NULL;
	while ((ret = gnl(&line, &s, 42, fd)) > 0)	// use full gnl ???
	{											// i think not
		if (ft_strlen(line) > 0)
		{
			if (*bol < 511)	//511 right? means all bits on//other condition?
			{	// will this if work ?
				if (!ft_parse_line(file, line, bol))
					return (ft_error_msg("parse line failed\n", 0));
//				printf("bol: %d\n", *bol);
				++i;
			}
			else if (!ft_nlstadd_back(floor, ft_nlstnew(ft_strdup(line), 0)))
				return (0);	// also free shit, like everything
		}
		ft_scott_free(&line, 0);	// worth it ???
	}

//	ft_print_nlst(*floor);

	if (!*floor || *bol < 511)
		return (ft_error_msg("incorrect file\n", 0));
	return (1);
}

								// send both jeu and file ???
int		ft_parse_file(int fd, t_game *jeu)
{
	t_nlist		*floor;	// may not need this.... keep here for copy floor
	t_player	*me;

	// free if error to be set up...

	floor = NULL;
	if (!(ft_get_file_contents(fd, jeu->file, &floor, &jeu->bol)))
		return (ft_error_msg("file reader failed\n", 0));

	if (!ft_fill_tex_list(jeu))	// something better eventually ?
		return (0);
	
	if (!(me = malloc(sizeof(t_player))))
		return (0);
	me->life = 100;
	jeu->me = me;
	if (!ft_copy_floor(jeu, floor))
		return (ft_error_msg("failed to copy floor\n", 0));
	if (!ft_nlstdel_all(&floor))	// can i del_all in copy floor ?
		return (ft_error_msg("failed to del nlst floor\n", 0));
	if (!ft_check_floor(jeu))
		return (ft_error_msg("floor failed check\n", 0));

		// elsewhere ?
	ft_unpack_textures(jeu);

	return (1);
}

