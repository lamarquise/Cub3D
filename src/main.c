



		// Should ft_scott_free() return (0) instead of (-1) ???



// TO DO:

	// start with getting mlx stuff from fractol and setting up new version
	// then parser
	// then game management...


	// fix ft_putendl and the likes in lib...
	// double check new lib functions
	// better Makefile for lib...
	// put GNL in lib, along with printf


	// before push, double check all new funcs you added to your lib
		// durring this project


#include "cub3d.h"





int		main(int ac, char **av)
{
	int		fd;
	int		line_n;

	t_map	file1;

	int		wid;
	int		hei;
	int		ret;
	

//	printf("main has happened\n");

	fd = 0;
	line_n = 0;
	if (!av)
		return (0);

	// testing:
	t_mlx	mlx;
	t_img	pic;


	pic.last_pix = 0;

	if (ac >= 2)		// if 3 or greater... look for '--save'
	{
//		printf("there is even an arg\n");
/*		// this is a good amount of the mlxinit stuff..
		mlx.ptr = mlx_init();

		look.win_ptr = mlx_new_window(mlx.ptr, 400, 400, "sup");

		look.img_ptr = mlx_new_image(mlx.ptr, 400, 400);
		look.img_data = (int*)mlx_get_data_addr(look.img_ptr, &mlx.bpp, &mlx.s_l, &mlx.endian);

		mlx_put_image_to_window(mlx.ptr, look.win_ptr, look.img_ptr, 0, 0);

		mlx_loop(mlx.ptr);	// necessary for window staying...
*/

		// im inclined to do the open here...
		// start by assuming there will be 1 file...
		// init the structures first I think... other func ?

		
		// if av[1] not end with .cub, ret 0 use strchr ? or somehting...


		fd = open(av[1], O_RDONLY);

//		printf("we have opend a file\n");
		
//		if (!ft_parse_file(fd, &file1))
//			return (0); // but free eventually

		ret = ft_parse_file(fd, &file1);
		printf("parse file ret: %d\n", ret);
		if (ret < 0)
			return (0);

		printf("and parsed it...\n");


		hei = (file1.level->width * U > file1.resolution_x ? \
				file1.level->width * U : file1.resolution_x);
		wid = (file1.level->height * U > file1.resolution_y ? \
				file1.level->height * U : file1.resolution_y);

		pic.img_wid = wid;
		pic.img_hei = hei;

		printf("wid: %d, hei: %d\n", wid, hei);


		// for now just making bird's eye view map....
		mlx.ptr = mlx_init();			// was wid, hei
		mlx.win_ptr = mlx_new_window(mlx.ptr, 800, 800, "sup");

		printf("window made\n");

		pic.img_ptr = mlx_new_image(mlx.ptr, 400, 400);

		pic.img_data = (int*)mlx_get_data_addr(pic.img_ptr,\
								&mlx.bpp, &mlx.s_l, &mlx.endian);

		printf("image inited\n");

		ft_create_img(&pic, file1.level);

		printf("created img\n");

		mlx_put_image_to_window(mlx.ptr, mlx.win_ptr, pic.img_ptr, 50, 50);

		printf("put img to win\n");

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
