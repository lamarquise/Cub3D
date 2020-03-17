

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

# define S 10	// step size
# define U 30	// map square size	// should be a multiple of 10 and odd ?
# define G 2	// map gap size		// do we count these in the steps ???
									// i think we have to...

	// necessary ???
typedef struct	s_imge
{
	void	*img_ptr;
	int		*img_data;
	int		img_wid;
	int		img_hei;
	int		last_pix;
}				t_imge;

	// necessary ???
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

typedef struct	s_screen
{
	struct s_game		*jeu;		// redirects back to game container
	t_wind				*win;
	t_imge				*img;		// call it img


	// contain sprites here?

	// other things you could see in the map window, like which level, ...
}				t_screen;

typedef struct	s_player
{
	int		x;	// ints for now
	int		y;
//	int		box;
	char	s_dir;	// a char i guess...
	int		life;
	// orientation
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
typedef struct	s_color
{
	int		r;
	int		g;
	int		b;

	// put path in too so can do either ???
//	char	*path;
	// for now just input color
}				t_color;

typedef struct	s_input
{
	int				res_x;
	int				res_y;

	char			*no_tex;	// just contains the path str ???
	char			*so_tex;
	char			*we_tex;
	char			*ea_tex;
	char			*sprite_tex;

	t_color			*f;		// is this better ???
	t_color			*c;


// colors for bird's eye view map ???
	// floor color	// make var capable of taking a texture for bonus
	// cealing color // idem	
}				t_input;

typedef struct	s_game
{
	// list of levels (linked list?)
	// save files ???

		// keep mlx info with win ???
	t_lmlx		*mlx;	// mal in main()
	t_input		*file;	// mal in main()

//	t_level		*niv;
	// OR
	t_nlist		*floor;		// mal in parse_file()
	int			x_boxes;	
	int			y_boxes;
	int			last_box;

	t_screen	*map;
	t_screen	*hud;

//	t_mapwin	*map;		// mal in master_init()
//	t_playwin	*hud;		// mal in master_init()

	t_player	*me;		// mal in file_parser()

	// a spirite container struct.

}				t_game;

// consider multiple level, multiple files...


typedef struct	s_key
{
	int     keycode;
	int     (*f)(t_screen *either);
}				t_key;

// inventory structure ???
// weapons structure, like damage etc, armor ???



	// Parse File
int				ft_expected_size(char **tab, int e);
int				ft_get_file_contents(int fd, t_input *file, t_nlist **floor);
int				ft_check_map(t_game *jeu, t_nlist *floor);
int				ft_parse_file(int fd, t_game *jeu);

	// Parse Line
int				ft_parse_res(char **tab, t_input *file);
int				ft_parse_path(char **tab, char *path);
int				ft_parse_colors(char **tab, t_color *color);
int				ft_parse_line(t_input *file, char *line);

	// Master
int				ft_hud_port(t_game *jeu);
int				ft_map_port(t_game *jeu);
int				ft_master_port(t_game *jeu);

	// Master Init
int				ft_init_hud(t_game *jeu);
int				ft_init_map(t_game *jeu);
int				ft_master_init(t_game *jeu);

	// Create MLX Entities
t_imge			*ft_create_imge(t_lmlx *mlx, int x, int y);
t_wind			*ft_create_wind(t_lmlx *mlx, char *name, int x, int y);

	// Make Map
int				ft_make_2D_floor_img(t_game *jeu);
int				ft_gen_bground(t_game *jeu);
int				ft_make_map_fov(t_game *jeu);

	// Make HUD

	// List Stuff
int				ft_print_nlst(t_nlist *lst);

	// Keyhooks
void			ft_hooks_loop(t_screen *either);

	// Math
int				ft_coord_convert(t_wind *win, t_imge *img, int x_box, int y_box);
int				ft_2D_to_1D(int x, int y, int width);

	// Quit
void			ft_clear(t_screen *either);
int				ft_quit(t_screen *either);
int				ft_quit_all(t_game *jeu);
void			ft_clear_imge(t_lmlx *mlx, t_imge *img);

#endif





