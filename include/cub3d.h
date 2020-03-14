

	// NEW CONVENTION, IF STRUCT TYPE SAME AS NAME FOR VAR OF THAT TYPE
	// NAMED VAR HAS 1 FEWER LETER



#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# include "libft.h"
# include "mlx.h"

// include math stuff...
// my printf


# define U 25
# define G 2



typedef struct	s_imge
{
	void	*img_ptr;
	int		*img_data;
	int		img_wid;
	int		img_hei;
	int		last_pix;
}				t_imge;

typedef struct	s_wind
{
	void	*win_ptr;
	int		win_wid;
	int		win_hei;
	char	*name;		// necessary ???
}				t_wind;

typedef struct	s_lmlx
{
	void	*ptr;
	int		bpp;
	int		s_l;
	int		endian;
}				t_lmlx;

	// handeling the 
typedef struct	s_playwin
{
//	t_wind		*win;
//	t_img		*img;

}				t_playwin;

	// handleing the map window...
typedef stuct	s_mapwin
{
	t_floorplan	*floor;		// have this too ???

	// or just
	int			x;		// better names...
	int			y;
	int			last_box;
	// also this ???
	t_nlist		*flines;	// better name ???

	t_wind		*win;
	t_imge		*floor;
	t_imge		*fov;


	// other things you could see in the map window, like which level, ...

}				t_mapwin;


// level contains all info from the file
// in level is a things that holds stuff for map window
// and a things that holds stuff for HUD window

typedef struct	s_level
{
	t_nlist	*flines;	// better name


	// basic map info, dims ??


	t_mapwin	*map;
	t_playwin	*hud;	// better name

	// sprites...

}				t_level;





typedef struct	s_floorplan		// dif name !!!!
{
	// a linked list of gnl lines
	t_nlist	*floor;

	// where to put version with more resolution ???
	// or multiply x and y_boxes  by 10 ???

	int		x_boxes;
	int		y_boxes;
	int		last_box;

}				t_floorplan;






typedef struct	s_player
{
	int		x;	// ints for now
	int		y;
	int		box;
	char	s_dir;	// a char i guess...
	int		life;
	// life ???
	// orientation
	// position x and y
	// respaun point/location
	// hitbox ???
	// weapon and or inventory linked list
}				t_player;

typedef struct	s_sprite
{
	// life
	// orientation
	// pos x and y
	// texture
	// identifier	// like a numer or something
	// hitbox ???
	// weapon and or damage
}				t_sprite;		// has to be able to work for dif types
									// of sprite... like dif texture
typedef struct	s_input
{
	int				res_x;
	int				res_y;

	char			*no_tex;	// just contains the path str ???
	char			*so_tex;
	char			*we_tex;
	char			*ea_tex;

	char			*sprit_tex;

	int				f_r;		// how to make these a path ???
	int				f_g;		// like for textured floor or celing...
	int				f_b;

	int				c_r;
	int				c_g;
	int				c_b;

// colors for bird's eye view map ???


	// floor color	// make var capable of taking a texture for bonus
	// cealing color // idem
	
}				t_input;

	// hold everything.
typedef struct	s_game
{
	// list of levels (linked list?)

	// player states
	// mlx container

	// induvidual level contains sprites and their states...

	// save files ???


	t_lmlx		*mlx;
	t_input		*file;	// thing that was read.

	t_level		*niv;	// conatins the map the stuff for win making...

	t_player	*me;
}				t_game;

// consider multiple level, multiple files...


typedef struct	s_key
{
	int     keycode;
	int     (*f)(t_mlx *mlx);
}				t_key;

// inventory structure ???
// weapons structure, like damage etc, armor ???



	// Parse Files
int				ft_expected_size(char **tab, int e);
int				ft_retrieve_file_contents(int fd, t_nlist **f_lines);
int				ft_parse_file(int fd, t_map *file);


	// Img Making
int				ft_create_img(t_img *img, t_floorplan *level, t_playerstate *player);


	// List Stuff
int				ft_print_nlst(t_nlist *lst);


	// Mlx Stuff
void			ft_clear(t_mlx *mlx);
int				ft_quit(t_mlx *mlx);
t_wind			*ft_init_wind(t_lmlx *mlx, char *name, int x, int y);


	// Keyhooks
void			ft_hooks_loop(t_mlx *mlx);


	// Window Math
int				ft_coord_convert(t_mlx *mlx, t_map *file, int x_box, int y_box);


	// Imge Stuff
t_imge			*ft_init_imge(t_lmlx *mlx, int x, int y);
void			ft_clear_imge(t_lmlx *mlx, t_imge *img);




#endif





