/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:37:27 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/29 14:20:15 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_str_end(char *str, char *end)
{
	int		sl;
	int		el;
	int		a;

	if (!str || !end)
		return (0);
	a = 0;
	sl = ft_strlen(str) - 1;
	el = ft_strlen(end) - 1;
	while (el > 0)
	{
		if (str[sl] != end[el])
			return (0);
		--sl;
		--el;
	}
	return (1);
}

int		ft_run(t_game *jeu, int ac, char **av)
{
	int			fd;

	if (!jeu || !av)
		return (0);
	if (ac == 3)
	{
		if (ft_strcmp(av[2], "--save") == 0)
			jeu->set->save = 1;
		else if (ft_strcmp(av[2], "--bonus") == 0)
			jeu->set->bonus = 1;
		else
			return (ft_error_msg("usage: <file.cub> <--save> OR <--bonus>\n", \
					0));
	}
	if ((fd = open(av[1], O_RDONLY)) == -1 || !ft_parse_file(fd, jeu) \
		|| !ft_start_game(jeu))
		return (ft_error_msg("failed to run\n", 0));
	close(fd);
	return (1);
}

int		main(int ac, char **av)
{
	t_game		jeu;
	t_input		file;
	t_settings	set;
	t_player	me;

	if (ac < 2 || ac > 3 || !ft_check_str_end(av[1], ".cub"))
		return (ft_error_msg("Usage: <file.cub> <--save> OR <--bonus>\n", 0));
	if (!ft_init_game(&jeu) || !ft_init_input(&file) \
		|| !ft_init_settings(&set) || !ft_init_mlx(&jeu))
	{
		ft_quit(&jeu);
		return (ft_error_msg("Error\nInitialization failed\n", 0));
	}
	jeu.file = &file;
	jeu.set = &set;
	jeu.me = &me;
	if (!ft_run(&jeu, ac, av))
	{
		ft_quit(&jeu);
		return (ft_error_msg("Error\n", 0));
	}
	ft_quit(&jeu);
	return (1);
}
