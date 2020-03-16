

		// parser.c is much better
		// line_parser.c should work


		// Should ft_scott_free() return (0) instead of (-1) ???



// TO DO:

	// then game management...


	// learn mark down for README.md
	// fix ft_putendl and the likes in lib...
	// double check new lib functions
	// put GNL in lib, along with printf


	// before push, double check all new funcs you added to your lib
		// durring this project


#include "cub3d.h"

	// put in dif folder ???
int		ft_init_input(t_input *file)
{
	t_color		*celing;
	t_color		*floor;

	if (!(celing = malloc(sizeof(t_color))))
		return (0);
	if (!(floor = malloc(sizeof(t_color))))
		return (0);
	file->res_x = -1;
	file->res_y = -1;
	file->no_tex = NULL;
	file->so_tex = NULL;
	file->we_tex = NULL;
	file->ea_tex = NULL;
	file->sprite_tex = NULL;
	celing->r = -1;
	celing->g = -1;
	celing->b = -1;
//	celing->path = NULL;
	floor->r = -1;
	floor->g = -1;
	floor->b = -1;
//	floor->path = NULL;
	file->c = celing;
	file->f = floor;
/*	file->f_r = -1;
	file->f_g = -1;
	file->f_b = -1;
	file->c_r = -1;
	file->c_g = -1;
	file->c_b = -1;
*/
	return (0);
}

int		ft_cor_end(char *str, char *end)
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

	// assuming 1 file

int		main(int ac, char **av)
{
	int		fd;
	t_game	jeu;
	t_input	file;
	int		ret;

	ft_init_input(&file);
	jeu.file = &file;

	if (ac < 2)
		return (ft_error_msg("usage: <file.cub> <--save>\n"));
	else if (ac == 2 || ac == 3)	// 2 and 3 for now
	{
		if (!ft_cor_end(av[1], ".cub"))
			return (ft_error_msg("usage: <file.cub>\n"));

	//	printf("it is .cub\n");

		fd = open(av[1], O_RDONLY);
		
		if (!ft_parse_file(fd, &jeu))
			return (ft_error_msg("Bad .cub file\n"));

		if (ac == 3)
		{
			// do the picture of first frame...
		}
//		else
			// everything else

		ret = ft_master_port(&jeu);
		if (ret < 1)
		{
			printf("ret: %d\n", ret);
			return (0);
		}

		// function that does all the game stuff...


		close(fd);
	}
	return (1);
}

/*
int		main(int ac, char **av)
{
	int			fd;
	int			line_n;

	t_map		file1;
	t_player	me;

	int				ret;
	

//	printf("main has happened\n");

	fd = 0;
	line_n = 0;
	file1.player = &player;
	if (!av)
		return (0);

	// testing:
	t_mlx			mlx;
	t_img			pic;

	mlx.pic = &pic;

	pic.last_pix = 0;

	if (ac >= 2)		// if 3 or greater... look for '--save'
	{
//		printf("there is even an arg\n");
		// this is a good amount of the mlxinit stuff..
		mlx.ptr = mlx_init();

		look.win_ptr = mlx_new_window(mlx.ptr, 400, 400, "sup");

		look.img_ptr = mlx_new_image(mlx.ptr, 400, 400);
		look.img_data = (int*)mlx_get_data_addr(look.img_ptr, &mlx.bpp, &mlx.s_l, &mlx.endian);

		mlx_put_image_to_window(mlx.ptr, look.win_ptr, look.img_ptr, 0, 0);

		mlx_loop(mlx.ptr);	// necessary for window staying...


		// im inclined to do the open here...
		// start by assuming there will be 1 file...
		// init the structures first I think... other func ?

		
		// if av[1] not end with .cub, ret 0 use strchr ? or somehting...


		fd = open(av[1], O_RDONLY);

//		printf("we have opend a file\n");
		
//		if (!ft_parse_file(fd, &file1))
//			return (0); // but free eventually

		ret = ft_parse_file(fd, &file1);
//		printf("parse file ret: %d\n", ret);
		if (ret < 0)
			return (0);


//		printf("and parsed it...\n");

			// res_x = hei ???
		mlx.win_wid = (file1.level->x_boxes * (U + G) + 2 * G > file1.res_x ? \
				file1.level->x_boxes * (U + G) + 2 * G : file1.res_x);
		mlx.win_hei = (file1.level->y_boxes * (U + G) + 2 * G > file1.res_y ? \
				file1.level->y_boxes * (U + G) + 2 * G: file1.res_y);

		// do this: ????
//		file1.res_x = mlx.win_wid
//		file1.res_y = mlx.win_hei


			// gap only in between
		pic.img_wid = file1.level->x_boxes * (U + G) - G;	// do this better for now...
		pic.img_hei = file1.level->y_boxes * (U + G) - G;

//		printf("wid: %d, hei: %d\n", wid, hei);


		// for now just making bird's eye view map....
		mlx.ptr = mlx_init();			// was wid, hei
		mlx.win_ptr = mlx_new_window(mlx.ptr, mlx.win_wid, mlx.win_hei, "sup");

//		printf("window made\n");

		pic.img_ptr = mlx_new_image(mlx.ptr, pic.img_wid, pic.img_hei);

		pic.img_data = (int*)mlx_get_data_addr(pic.img_ptr,\
								&mlx.bpp, &mlx.s_l, &mlx.endian);

//		printf("image inited\n");

		ft_create_img(&pic, file1.level);

//		printf("created img\n");

		int		x_disp;	//displacement
		int		y_disp;

			// may need to take odd numbers and shit into account ???
		x_disp = mlx.win_wid / 2 - pic.img_wid / 2;
		y_disp = mlx.win_hei / 2 - pic.img_hei / 2;

		mlx_put_image_to_window(mlx.ptr, mlx.win_ptr, pic.img_ptr, x_disp, y_disp);

//		printf("put img to win\n");

		ft_hooks_loop(&mlx);

		mlx_loop(mlx.ptr);


//		ft_print_nlst(file1.level->floor);

		// i need a print everything in the linked list func...



		// init function for mlx
		// open and gnl ? ie a parser...
		// grid check...
		// the thing that runs the game/program
		// clean, free, etc close...


		close(fd);
	}
	return (0);
}

*/


