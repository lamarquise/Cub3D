/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:39:52 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/06 04:34:53 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



	// NEW CONVENTION, IF STRUCT TYPE SAME AS NAME FOR VAR OF THAT TYPE
	// NAMED VAR HAS 1 FEWER LETER



#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# include <math.h>

# include "bresenham.h"
# include "mymlx.h"
# include "libft.h"
# include "mlx.h"

// include math stuff...

# define RES	0x02	// ie the second pos in bin number // 10
# define PNO    0x04
# define PSO    0x08
# define PWE    0x10
# define PEA    0x20
# define PS1    0x40
# define CFL    0x80
# define CCE    0x100

// can add more sprites here, PS2 and such

# define WHITE	0xFFFFFF
# define RED	0xD62727
# define YELLOW	0xEAD725
# define GREEN	0x03BF23
# define BLUE	0x3A7ECC
# define PURPLE	0x925CC3
# define BLACK	0x000000


# define ROT_SPEED 0.02		// was 0.04 in old keyhook system
# define STEP_SIZE 0.05		// was 0.1 in old keyhook system

# define S_MAP	0x01
# define S_PAU	0x02
# define S_BON	0x04



typedef struct	s_vect_i
{
	int		x;
	int		y;
}				t_vect_i;

typedef struct	s_vect_d
{
	double	x;
	double	y;
}				t_vect_d;

typedef struct	s_player
{
	t_vect_d	pos;
	t_vect_d	dir;
	t_vect_d	plane;

//	int			box;	// the index of the box you're in
	char		s_dir;	// a char i guess...
	int			life;
	// respaun point/location
	// hitbox ???
	// weapon and or inventory linked list
}				t_player;

typedef struct	s_sprite
{
	// int	index_in_tex_list;
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
	t_vect_i		res;
	char			*no_path;	// just contains the path str ???
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*sprite_path;

	int				f;
	int				c;
	// will add pathes later...

	t_imge			*no_tex;
	t_imge			*so_tex;
	t_imge			*we_tex;
	t_imge			*ea_tex;
	
	t_imge			*sprite_tex;

// colors for bird's eye view map ???
	// floor color	// make var capable of taking a texture for bonus
	// cealing color // idem	
}				t_input;


typedef struct	s_settings
{
	int		minimap;		// make all a single int bool ?
	int		bonus;
	int		pause;
}				t_settings;


typedef struct	s_texture
{
	void	*path;
	void	*img;
}				t_texture;

typedef struct	s_game
{
	// the fd ???
	// list of levels (linked list?)
	// save files ???

	t_input		*file;		// mal in main()
	char		**floor;	// mal in copy_floor()
	t_vect_i	boxes;

	int			last_box;	// still works ???
	t_lmlx		*mlx;		// mal in main()
	t_wind		*win;		// mal in init_master()
	t_imge		*hud;	// cuz i think only 1 imge for hud

	t_vect_i	grid_pixs;	// minimap stuff
	t_vect_i	grid_tl;	//top left
	int			fog;
	int			grid_box_size;
	t_imge		*yah;		// You Are Here
	t_imge		*crosshair;
	t_imge		*minimap;	// not in seperate window for now
	t_imge		*fpv;	// mal in master_init()	// First Person View


				// more like keys that can be released torch			
	int			torch[127];	// could be 126 but not sure...
	int			bol;
	t_nlist		*tex_list;	// list of all textures

	t_player	*me;		// mal in file_parser()
	t_settings	*set;		// mal in ? master() ?
//	int			settings;	// sadly bitwise ops didnt work... :(

	// here for now...
	t_vect_i	mouse;


}				t_game;

typedef struct	s_key
{
	int     keycode;
	int     (*f)(t_game *jeu);	// make this void, and cast it after ???
}				t_key;

// consider multiple level, multiple files...


// inventory structure ???
// weapons structure, like damage etc, armor ???


/*
**	Main
*/

int				ft_check_str_end(char *str, char *end);

/*
**	Init Structures
*/

int				ft_init_settings(t_settings *set);
int				ft_init_player(t_game *jeu);
int				ft_init_input(t_input *file);
int				ft_init_mlx(t_game *jeu);
int				ft_init_game(t_game *jeu);

/*
**	Parse File
*/

int				ft_get_file_contents(int fd, t_input *file,\
				t_nlist **floor, int *bol);
int				ft_parse_file(int fd, t_game *jeu);

/*
**	Parse Line
*/

int				ft_expected_size(char **tab, int e);
int				ft_parse_res(char **tab, t_input *file);
int				ft_parse_path(char **tab, char **path);
int				ft_parse_colors(char **tab, int *color);
int				ft_parse_line(t_input *file, char *line, int *bol);

/*
**	Check Floor
*/

void			ft_get_floor_dimentions(t_game *jeu, t_nlist *floor);
int				ft_copy_floor(t_game *jeu, t_nlist *floor);
int				ft_g(char c);
int				ft_check_around(t_game *jeu, int x, int y);
int				ft_check_floor(t_game *jeu);

/*
**	Game Engine
*/

int				ft_game_engine(t_game *jeu);
int				ft_draw_imges(t_game *jeu);
int				ft_prime_engine(t_game *jeu);
int				ft_display_minimap(t_game *jeu);
int				ft_display_crosshair(t_game *jeu);

	// dif name
int				ft_keycodes(t_game *jeu);


/*
**	Generate
*/

int				ft_generate_fpv(t_game *jeu);
int				ft_generate_minimap(t_game *jeu);
int				ft_generate_player(t_game *jeu);
int				ft_generate_crosshair(t_game *jeu);


/*
**	Raycasting
*/

int				ft_draw_pix_to_imge(t_imge *img, int pos, int color);
int				ft_draw_col_to_imge(t_imge *img, int start_row, \
					int end_row, int col, int color);
int				ft_ray_dir(t_vect_i *step, t_vect_i *map_pos, t_vect_d *pos, \
				t_vect_d *side_dist, t_vect_d *ray_dir, t_vect_d *delta_dist);
int				ft_dda(t_game *jeu, t_vect_i *map_pos, t_vect_i *step, \
				t_vect_d *side_dist, t_vect_d *delta_dist);

int				ft_raycasting(t_game *jeu);


/*
**	Minimap
*/

int				ft_sizing_minimap_imge(t_game *jeu);
int				ft_draw_box(t_imge *img, int s_pos, int size, int color);
int				ft_fill_imge(t_imge *img, int color);
int				ft_draw_grid(t_game *jeu, t_imge *img, int t_left, int size);
int				ft_fill_rect(t_imge *img, int s_pos, int dimx, int dimy, int color);

/*
**	Create MLX Entities
*/

t_imge			*ft_init_imge();	// norm ???
t_imge			*ft_create_imge(t_lmlx *mlx, int x, int y);
t_wind			*ft_create_wind(t_lmlx *mlx, char *name, int x, int y);

/*
**	Textures
*/

t_texture		*ft_new_ttexture(void *path, void *img);
int				ft_add_texture(t_game *jeu, void *path, void *img);
int				ft_get_tex(t_game *jeu, t_imge *img, char *path);
int				ft_unpack_textures(t_game *jeu);

/*
**	Keyhooks
*/

//int				ft_map_redraw(t_game *jeu);
int				ft_redraw(t_game *jeu);
void			ft_light_torch(t_key *torch);
void			ft_hooks_loop(t_game *jeu);
int				ft_keypress(int key, t_game *jeu);
int				ft_keyrelease(int key, t_game *jeu);

/*
**	Math
*/

int				ft_2d_to_1d(int x, int y, int width);
int				ft_rgb_to_int(int r, int g, int b, int t);



/*
**	Player Commands (new name, just movement ?
*/

	// move these to a seperate file
int				ft_move_forward(t_game *jeu);
int				ft_move_backward(t_game *jeu);
int				ft_move_left(t_game *jeu);
int				ft_move_right(t_game *jeu);

int				ft_rot_right(t_game *jeu);
int				ft_rot_left(t_game *jeu);

/*
**	Toggle Buttons
*/

//int				ft_toggle_on(t_game *jeu, int shift);	// sadly bitwise
//int				ft_toggle_off(t_game *jeu, int shift);	// didn't work...
int				ft_toggle_on(int *button);
int				ft_toggle_off(int *button);


/*
**	Mouse Commands
*/

int				ft_capture_mouse_pos(int x, int y, t_game *jeu);
int				ft_mouse_move(int x, int y, t_game *jeu);


// Move to lib later

int				ft_print_nlist(t_nlist *lst);



/*
**	Quit
*/
	/*
void			ft_clear(t_screen *either);
int				ft_quit(t_screen *either);
int				ft_quit_all(t_game *jeu);
void			ft_clear_imge(t_lmlx *mlx, t_imge *img);
*/
int				ft_quit(t_game *jeu);

#endif





