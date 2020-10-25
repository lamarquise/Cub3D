/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:37:27 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/25 03:56:20 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TO DO:

	// then game management...
	// multi-threading ? how would that even work ??? I mean i know but
	// still...
	// before push, double check all new funcs you added to your lib
		// durring this project

#include "cub3d.h"

	// TMP for testing
int		ft_print_file(t_game *jeu)
{
	ft_print_strtab((char**)jeu->lev->floor);

	return (1);
}

	// add to lib ?
	// to make sure is a .cub file
int		ft_check_str_end(char *str, char *end)
{
	int		sl;
	int		el;
	int		a;

	if (!str || !end)
		return (0);
	a = 0;
	sl = ft_strlen(str) - 1;	// for the \0
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

	// need a check and if there free all (as in structures and contents)
	// that can be called like whenever
	// assuming 1 file

//	./cub3d game_files/something.cub --save OR --bonus

	// add ret = and then ret that so know if have to use quit


int		main(int ac, char **av)
{
	int			fd;
	t_game		jeu;	// maybe i can't free these, just need to free the contents
	t_input		file;
	t_settings	set;

	if (ac < 2 || ac > 3 || !ft_check_str_end(av[1], ".cub"))
		return (ft_error_msg("usage: <file.cub> <--save> OR <--bonus>\n", 0));
	if (!ft_init_game(&jeu) || !ft_init_input(&file) || !ft_init_settings(&set) \
		|| !ft_init_mlx(&jeu))
		return (ft_error_msg("initialization failed\n", 0));
	jeu.file = &file;
	jeu.set = &set;
	if (ac == 3)
	{
		if (ft_strcmp(av[2], "--save") == 0)
			jeu.set->save = 1;
		else if (ft_strcmp(av[2], "--bonus") == 0)
		{
			printf("testing --bonus\n");
			jeu.set->bonus = 1;
		}
		else
			return (ft_error_msg("usage: <file.cub> <--save> OR <--bonus>\n", 0));
	}
	fd = open(av[1], O_RDONLY);		// put this in Start Game ?
	if (fd == -1 || !ft_parse_file(fd, &jeu))
		return (ft_error_msg("Bad .cub file\n", 0));
	printf("file parsed\n");
	if (!ft_start_game(&jeu))
		return (ft_error_msg("failed to run\n", 0));
	close(fd);

	ft_quit(&jeu);

//	system("leaks test");

	return (1);

	// a thing in main where ret = 0 if fails, (also displays msg) and free all each time

	// return (ret);
}






