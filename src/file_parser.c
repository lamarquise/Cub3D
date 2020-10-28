/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:46:53 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/28 20:13:55 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_get_nl(char **line, int fd)
{
	static char	*s;
	ssize_t		i;
	char		*p;
	char		b[17];

	p = NULL;
	if ((i = ft_sfindchar(s, '\n')) != -1)
	{
		if (!(*line = ft_strsub(s, 0, (size_t)i++)) \
			|| (!(p = ft_strsub(s, i, ft_sstrlen(s) - (size_t)i))))
			return (-1);
		free(s);
		s = p;
		return (1);
	}
	if (!line || !ft_ibzero(b, 17) || (i = read(fd, b, 16)) < -1
		|| (i > 0 && !(p = ft_gstrjoin(&s, b)))
		|| (s && s[0] && ++i == 1 && !(*line = ft_gstrjoin(&s, (void*)0)))
		|| (i < 1 && !(*line) && !(*line = ft_strsub(NULL, 0, 0))) || i < 0)
		return (-1);
	free(s);
	s = p;
	return ((i > 0) ? ft_get_nl(line, fd) : 0);
}

int		ft_get_file_lines(int fd, t_game *jeu, t_nlist **floor)
{
	int		i;
	int		map;
	int		ret;
	char	*line;

	i = 0;
	map = 0;
	line = NULL;
	ret = 1;
	while ((ret = ft_get_nl(&line, fd)) > 0)
	{
		if (!ft_parse_line(jeu, line, floor, &map))
		{
			ft_scott_free(&line, 0);
			return (ft_error_msg("parse line failed\n", 0));
		}
//		printf("line: |%s|\n", line);
//		printf("in get lines\n");
//		ft_print_nlist(*floor);
		ft_scott_free(&line, 0);
//		printf("\n");
//		line = NULL;
	}
//	printf("end get file lines\n");
//	ft_print_nlist(*floor);
	free(line);
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
//	printf("after collect levels\n");
//	ft_print_nlist(floor);
	if (!ft_nlstdel_all(&floor))
		return (ft_error_msg("failed to del nlst floor\n", 0));
//	printf("after del all\n");
//	ft_print_nlist(floor);
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
