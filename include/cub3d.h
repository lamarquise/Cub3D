/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:39:52 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/16 19:40:40 by ericlazo         ###   ########.fr       */
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

	// Essencial Input file bol values

# define RES	0x02	// ie the second pos in bin number // 10
# define TNO    0x04
# define TSO    0x08
# define TWE    0x10
# define TEA    0x20
# define TS1    0x40	// may need to change...
# define CFL    0x80
# define CCE    0x100

	// Optional Input file bol values

# define BEX	0x02
# define BKE	0x04
# define BOP	0x08
# define BFL	0x10	// not sure i need the floor and ceiling ones...
# define BCE	0x20



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
//	char		s_dir;	// a char i guess...
	int			life;
	// respaun point/location
	// hitbox ???
	// weapon and or inventory linked list
}				t_player;

typedef struct	s_texture
{
	int		value;	// 0-3 is Wall dirs, 4 is spites
	char	*path;
	t_imge	*img;
}				t_texture;

typedef struct	s_sprite
{
	t_vect_d	pos;
	t_vect_d	dir;		// need this ?
	t_vect_d	plane;		// and this ?

	char		id;

	t_texture	*tex;

	// how do i make one a portal and one a key and all that shit...

	// life
	// texture
	// identifier	// like a numer or something
	// hitbox ???
	// weapon and or damage
}				t_sprite;		// has to be able to work for dif types
									// of sprite... like dif texture
typedef struct	s_input
{
	t_vect_i		res;
	
	t_texture		*no;		// i think better if pointers...
	t_texture		*so;
	t_texture		*ea;
	t_texture		*we;
	t_nlist			*sprites;	// just the ttextures for sprites...

//	int				exit;
	t_texture		*exit;		// tmp solution for testing

					// defunct...
	t_nlist			*tex_list;	//we put a table in the contents to store NO and path
	int				*index_tab;	// for this we want a predetermined order
	int				nsprites;
		// could be unncessary...
	// eventually need to know number of sprites...

	t_texture		*floor;
	t_texture		*ceiling;
//	int				f;
//	int				c;
}				t_input;

typedef struct	s_binput	// as in bonus input
{
	t_texture		*exit;		// X
	t_texture		*key;		// Y
	t_texture		*opener;	// Z
}				t_binput;

typedef struct	s_settings
{
	int		minimap;		// make all a single int bool ?
	int		bonus;
	int		save;
	int		pause;
	int		change_lev;
}				t_settings;

typedef struct	s_level
{
	char		**floor;
	t_vect_i	dim;
	int			last_box;
	t_vect_d	player_pos;
	char		player_orient;

	t_vect_i	exit_pos;
//	t_texture	*exit_t;	// don't need this here

	// could add other things too, like enemy strength, other shit ?

}				t_level;

typedef struct	s_game
{
	// save files ???

	t_input		*file;		// mal in main()
	t_binput	*b_file;
	t_nlist		*level_list; 
	t_level		*lev;
	int			n_of_levels;
	int			cur_level;
	t_player	*me;
	t_settings	*set;

	t_lmlx		*mlx;		// mal in main()
	t_wind		*win;		// mal in init_master()

	t_imge		*yah;		// You Are Here
	t_imge		*crosshair;
	t_imge		*minimap;	// not in seperate window for now
	t_imge		*fpv;	// mal in master_init()	// First Person View
	t_imge		*title_screen;


	int			sbol;	// standard file bol // put in file ???
	int			bbol;	// bonus file bol // put in b_file ?
	int			fog;	// pertains to the map display
	int			torch[127];	// could be 126 but not sure...
	t_vect_i	mouse;		// here for now...


	t_vect_i	grid_pixs;	// minimap stuff	// could put in t_level
	t_vect_i	grid_tl;	//top left			// also this
	int			grid_box_size;					// also this

//	t_imge		*hud;	// cuz i think only 1 imge for hud
}				t_game;

/*
typedef struct	s_key
{
	int     keycode;
	int     (*f)(t_game *jeu);	// make this void, and cast it after ???
}				t_key;
*/

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
int				ft_init_level(t_level *lev);
int				ft_init_player(t_game *jeu, t_level *lev);
int				ft_init_input(t_input *file);
int				ft_init_binput(t_binput *b_file);
int				ft_init_mlx(t_game *jeu);
int				ft_init_game(t_game *jeu);

/*
**	File Parser
*/

int				ft_get_file_lines(int fd, t_game *jeu, t_nlist **floor);
//int				ft_get_file_contents(int fd, t_game *jeu, t_input *file, \
//				t_nlist **floor, int *bol);
//int				ft_get_file_contents(int fd, t_input *file,\
//				t_nlist **floor, int *bol);
int				ft_parse_file(int fd, t_game *jeu);

/*
**	Line Parser
*/

int				ft_parse_optional_input(t_game *jeu, char **tab);
int				ft_parse_essencial_input(t_game *jeu, char **tab);
int				ft_parse_line(t_game *jeu, char *line, t_nlist **floor, int *map);
//int				ft_parse_line(t_game *jeu, t_input *file, char *line, int *bol);
//int				ft_parse_line(t_input *file, char *line, int *bol);

/*
**	Input Parser
*/

int				ft_expected_size(char **tab, int e);
int				ft_parse_res(char **tab, t_input *file);
//int				ft_parse_path(t_input *file, char **tab, int value);
//int				ft_parse_path(char **tab, char **path);
int				ft_parse_sprite_path(t_input *file, char **tab);
int				ft_parse_path_to_texture(char **tab, t_texture **tex);
int				ft_parse_colors(char **tab, t_texture **surface);



/*
**	Check Floor
*/

//void			ft_get_floor_dimentions(t_game *jeu, t_nlist *floor);
//int				ft_copy_floor(t_game *jeu, t_nlist *floor);
int				ft_g(char c);
int				ft_check_around(t_level *lev, int x, int y);
int				ft_check_floor(t_level *lev);
//int				ft_check_around(t_game *jeu, int x, int y);
//int				ft_check_floor(t_game *jeu);

/*
**	Level Parsing
*/
				// move to lib
//int				ft_contains_only(char *src, char *this);
int				ft_get_floor_dimentions(t_level *lev, t_nlist *floor);
t_level			*ft_create_level(t_nlist **floor);
int				ft_collect_levels(t_game *jeu, t_nlist *floor);

/*
**	Game Engine
*/

int				ft_prime_level(t_game *jeu, t_level *lev);
int				ft_prime_engine(t_game *jeu);
int				ft_set_level(t_game *jeu);
int				ft_game_engine(t_game *jeu);
int				ft_start_game(t_game *jeu);

/*
**	Display to Screen
*/

int				ft_display_minimap(t_game *jeu);
int				ft_display_crosshair(t_game *jeu);
int				ft_draw_imges(t_game *jeu);
int				ft_redraw(t_game *jeu);

/*
**	Generate
*/

int				ft_generate_fpv(t_game *jeu);
int				ft_generate_minimap(t_game *jeu, t_level *lev);
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
t_imge			*ft_select_tex(t_game *jeu, int side, t_vect_d ray_dir, \
				t_vect_i map_pos);

int				ft_raycasting(t_game *jeu);


/*
**	Minimap
*/

int				ft_sizing_minimap_imge(t_game *jeu, t_level *lev);
int				ft_draw_box(t_imge *img, int s_pos, int size, int color);
int				ft_fill_imge(t_imge *img, int color);
int				ft_draw_grid(t_game *jeu, t_level *lev, t_imge *img, int t_left, int size);
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

t_texture		*ft_new_ttexture(int value, char *path, t_imge *img);
int				ft_add_tex_to_nlist(t_nlist **list, int value, char *path, \
					t_imge *img);
//t_texture		*ft_new_ttexture(void *path, void *img);
//int				ft_add_texture(t_game *jeu, void *path, void *img);
int				ft_get_tex(t_game *jeu, t_imge *img, char *path);
int				ft_unpack_texture(t_game *jeu, t_texture *tex);
int				ft_unpack_list_textures(t_game *jeu, t_nlist *list);
int				ft_unpack_wall_textures(t_game *jeu);
//int				ft_unpack_textures(t_game *jeu);

/*
**	Keyhooks
*/

int				ft_keypress(int key, t_game *jeu);
int				ft_keyrelease(int key, t_game *jeu);
int				ft_keycodes(t_game *jeu);

//void			ft_light_torch(t_key *torch);
//void			ft_hooks_loop(t_game *jeu);

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





