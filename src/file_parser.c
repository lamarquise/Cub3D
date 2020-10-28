/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:46:53 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 01:17:15 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_get_file_lines(int fd, t_game *jeu, t_nlist **floor)
{
	int		i;
	int		map;
	int		ret;
	char	*s;
	char	*line;

	i = 0;
	map = 0;
	s = ft_strnew(1);
	line = NULL;
	while ((ret = gnl(&line, &s, 42, fd)) > 0)
	{
		if (!ft_parse_line(jeu, line, floor, &map))
		{
			free(s);
			ft_scott_free(&line, 0);
			return (ft_error_msg("parse line failed\n", 0));
		}
		ft_scott_free(&line, 0);
	}
	free(s);
	if (!*floor || jeu->sbol < 511)
		return (ft_error_msg("incorrect file\n", 0));
	return (1);
}

int		ft_parse_file(int fd, t_game *jeu)
{
	t_nlist		*floor;

	floor = NULL;
	if (!(ft_get_file_lines(fd, jeu, &floor)) || !ft_collect_levels(jeu, floor))
	{
		ft_nlstdel_all(&floor);
		return (ft_error_msg("file reader failed\n", 0));
	}
	if (!ft_nlstdel_all(&floor))
		return (ft_error_msg("failed to del nlst floor\n", 0));
	if (!jeu->set->bonus && jeu->n_of_levels > 1)
		return (ft_error_msg("not bonus, bad file, too many levels\n", 0));
	if (!ft_unpack_wall_textures(jeu))
		return (ft_error_msg("failed to unpack wall tex in file parser\n", 0));
	if (!ft_unpack_list_textures(jeu, jeu->file->spri_type_texs))
		return (ft_error_msg("failed to unpack sprite tex file parser\n", 0));
	if (jeu->set->bonus && jeu->file->floor && jeu->file->floor->path \
		&& !ft_unpack_texture(jeu, jeu->file->floor))
		return (ft_error_msg("failed to unpack floor tex file parser\n", 0));
	if (jeu->set->bonus && jeu->file->ceiling && jeu->file->ceiling->path \
		&& !ft_unpack_texture(jeu, jeu->file->ceiling))
		return (ft_error_msg("failed to unpack ceiling tex file parser\n", 0));
	return (1);
}
