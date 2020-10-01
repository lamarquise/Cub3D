/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:37:27 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/27 19:41:19 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		// parser.c is much better
		// line_parser.c should work

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
	ft_print_strtab(jeu->floor);

	return (1);
}

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

int		main(int ac, char **av)
{
	int		fd;
	t_game	jeu;
	t_input	file;
	int		ret;

	ret = 0;

	ft_init_game(&jeu);
	ft_init_input(&file);
	jeu.file = &file;

	if (ac < 2)
		return (ft_error_msg("usage: <file.cub> <--save>\n", 0));
	else if (ac == 2 || ac == 3)	// 2 and 3 for now
	{
		if (!ft_check_str_end(av[1], ".cub"))
			return (ft_error_msg("usage: <file.cub>\n", 0));

	//	printf("it is .cub\n");

		fd = open(av[1], O_RDONLY);
	
		if (!ft_init_mlx(&jeu))
			return(0);
		if (!ft_parse_file(fd, &jeu))
			return (ft_error_msg("Bad .cub file\n", 0));
//		ft_print_file(&jeu);
/*		if (ac == 3)
		{
			// do the picture of first frame...
		}
		else
			// everything else
*/
//		if (!ft_print_strtab(jeu.floor))
//			return (0);

		printf("file parsed\n");
		if (!ft_prime_engine(&jeu))
			return (0);

		if (!ft_game_engine(&jeu))
			return (ft_error_msg("engine failed\n", 0));


//		if (!ft_master(&jeu))
//			return (ft_error_msg("master failed\n", 0));

		close(fd);
	}
	return (1);
}

