/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:39:52 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/29 00:35:08 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>

	// REMOVE !!!!!
# include <stdio.h>

# include <fcntl.h>

# include <math.h>

# if defined(__APPLE__)
#  include <key_macos.h>
# else
#  include <key_linux.h>
# endif

	// could but dif .h's in the if condition

# include "bresenham.h"
# include "mymlx.h"
# include "libft.h"
# include "mlx.h"		// or "mlx.h" ?

# define RES	0x02
# define TNO    0x04
# define TSO    0x08
# define TWE    0x10
# define TEA    0x20
# define TS1    0x40
# define CFL    0x80
# define CCE    0x100

# define BEX	0x02
# define BKE	0x04
# define BOP	0x08

# define WHITE	0xFFFFFF
# define RED	0xD62727
# define YELLOW	0xEAD725
# define GREEN	0x03BF23
# define BLUE	0x3A7ECC
# define PURPLE	0x925CC3
# define BLACK	0x000000
# define NO		0x00FFFFFF
# define ROT_SPEED 0.04
# define STEP_SIZE 0.05

typedef struct	s_vect_i
{
	int		x;
	int		y;
}				t_vect_i;

typedef	struct	s_vect_t
{
	t_vect_i	a;
	t_vect_i	b;
}				t_vect_t;

typedef struct	s_vect_d
{
	double	x;
	double	y;
}				t_vect_d;

typedef struct	s_texture
{
	int		value;
	char	*path;
	t_imge	*img;
}				t_texture;

typedef struct	s_player
{
	t_vect_d	pos;
	t_vect_d	dir;
	t_vect_d	plane;
	int			zoom_factor;
	int			life;
	int			key;
}				t_player;

typedef struct	s_sprite
{
	t_texture	*tex;
	t_vect_d	pos;
	t_vect_d	dir;
	char		id;
	int			anim_color;
	int			life;

}				t_sprite;

typedef struct	s_input
{
	t_vect_i		res;
	t_texture		*no;
	t_texture		*so;
	t_texture		*ea;
	t_texture		*we;
	t_nlist			*spri_type_texs;
	int				n_spri_types;
	t_texture		*floor;
	t_texture		*ceiling;
}				t_input;

typedef struct	s_level
{
	char		**floor;
	t_vect_i	dim;
	int			last_box;
	t_vect_d	player_spos;
	char		player_sorient;
	t_nlist		*spris_list;
	t_sprite	*spris_tab;
	int			n_spris;
	int			exit_exists;
	int			exit_index;
	int			key_exists;
	int			key_index;
}				t_level;

typedef struct	s_settings
{
	int		minimap;
	int		bonus;
	int		zoom;
	int		save;
	int		pause;
	int		change_lev;
}				t_settings;

typedef struct	s_game
{
	t_input		*file;
	t_nlist		*level_list; 
	t_level		*lev;
	int			n_of_levels;
	int			cur_level;
	t_player	*me;
	t_settings	*set;
	t_lmlx		*mlx;
	t_wind		*win;
	t_imge		*yah;
	t_imge		*crosshair;
	t_imge		*minimap;
	t_imge		*fpv;
	int			sbol;
	int			bbol;
	int			fog;
	int			torch[65364];
	t_vect_i	mouse;
	t_vect_i	grid_pixs;
	t_vect_i	grid_tl;
	int			grid_box_size;
	int			side;
}				t_game;

/*
**	Main
*/

int				ft_check_str_end(char *str, char *end);
int				ft_run(t_game *jeu, int ac, char **av);

/*
**	Init More Structures
*/

int				ft_init_settings(t_settings *set);
int				ft_init_level(t_level *lev);
int				ft_finish_init_player(t_game *jeu, t_level *lev);
int				ft_init_player(t_game *jeu, t_level *lev);

/*
**	Init Structures
*/

int				ft_init_input(t_input *file);
int				ft_init_torch(t_game *jeu);
int				ft_init_mlx(t_game *jeu);
int				ft_init_game(t_game *jeu);

/*
**	File Parser
*/

int				ft_get_file_lines(int fd, t_game *jeu, t_nlist **floor);
int				ft_parse_file(int fd, t_game *jeu);

/*
**	Line Parser
*/

int				ft_parse_optional_input(t_game *jeu, char **tab);
int				ft_parse_essencial_input(t_game *jeu, char **tab);
int				ft_check_input_values(t_game *jeu, char **tab, int *map);
int				ft_parse_line(t_game *jeu, char *line, t_nlist **floor, int *map);

/*
**	Input Parser
*/

int				ft_parse_res(char **tab, t_input *file);
int				ft_parse_sprite_type_path(t_input *file, char **tab, char id);
int				ft_parse_path_to_texture(char **tab, t_texture **tex);
int				ft_parse_color(char **nums);
int				ft_parse_surfaces(char **tab, t_texture **surface);


/*
**	Floor Management
*/

int				ft_g(char c, char s);
int				ft_check_around(t_level *lev, int x, int y, char s);
int				ft_found_sprite(t_game *jeu, t_level *lev, t_vect_i p);
int				ft_found_not_wall(t_game *jeu, t_level *lev, t_vect_i p, int s);
int				ft_check_floor(t_game *jeu, t_level *lev);

/*
**	Level Parsing
*/

int				ft_get_floor_dimentions(t_level *lev, t_nlist *floor);
int				ft_fill_floor(t_nlist **floor, t_level *lev, char **new_floor);
t_level			*ft_create_level(t_nlist **floor);
int				ft_add_level(t_game *jeu, t_level *lev);
int				ft_collect_levels(t_game *jeu, t_nlist *floor);

/*
**	Game Engine
*/

int				ft_prime_level(t_game *jeu);
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
int             ft_casting(t_game *jeu);

/*
**	Save
*/

void			ft_create_file_header(unsigned char *file_header, \
				t_game *jeu, int pad_size);
int				ft_screenshot(t_game *jeu);

/*
**	Generate
*/

int				ft_generate_fpv(t_game *jeu);
int				ft_generate_crosshair(t_game *jeu);

/*
**	Generate Minimap
*/

int				ft_generate_sight_lines(t_game *jeu);
int				ft_generate_player(t_game *jeu);
int				ft_generate_minimap(t_game *jeu, t_level *lev);

/*
**	Raycasting
*/

t_vect_i		ft_get_wall_texture(t_game *jeu, t_imge *tex_img, double pwd, \
				t_vect_d ray);
t_vect_i		ft_calc_sliver_limits(t_game *jeu, int sliver_hei);
int				ft_generate_wall_sliver(t_game *jeu, int x, double *pwd, t_vect_d ray);
int             ft_draw_fc(t_game *jeu, t_vect_i sliver_limits, int x);
int				ft_raycasting(t_game *jeu, double *z_buffer);

/*
**	Rayshooting
*/

t_vect_d		ft_calc_delta_dist(t_vect_d ray);
int				ft_dda(t_vect_i *map, t_vect_i *step, t_vect_d *side_dist, \
				t_vect_d *delta_dist);
int				ft_shoot_ray(t_game *jeu, t_vect_d p_pos, t_vect_d ray, double *pwd);

/*
**	Floorcasting
*/

int				ft_draw_floor(t_game *jeu, int x, int y, t_vect_i tex);
int				ft_draw_ceiling(t_game *jeu, int x, int y, t_vect_i tex);
t_vect_i		ft_get_floor_tex(t_imge *img, t_vect_d *floor, t_vect_i *cell);
int				ft_shoot_floor_ray(t_game *jeu, t_vect_d *floor, \
				t_vect_d *floor_step, double row_dist);
int				ft_floorcasting(t_game *jeu);

/*
**	Sprite Order
*/

int				ft_sort_sprites(int *spri_ord, double *spri_dist, int n_spris);
int				ft_calc_sprite_order(t_game *jeu, int *spri_ord);

/*
**	Spritecasting
*/

t_vect_d		ft_calc_sprite_transform(t_game *jeu, int i, int *spri_ord);
int				ft_calc_sprite_screen_x(t_game *jeu, t_vect_d *tran);
t_vect_t        ft_calc_draw_dims(t_game *jeu, t_vect_t *spri_dims, t_vect_d *tran);
void			ft_draw_sprite(t_game *jeu, t_vect_t *spri_dims, \
				double *z_buffer, t_vect_d *transform);
int				ft_spritecaster(t_game *jeu, double *z_buffer);

/*
**	Minimap
*/

int				ft_sizing_minimap_imge(t_game *jeu, t_level *lev);
int				ft_draw_box(t_imge *img, int s_pos, int size, int color);
int				ft_fill_imge(t_imge *img, int color);
int				ft_draw_grid(t_game *jeu, t_imge *img, int t_left);
int				ft_fill_rect(t_imge *img, int s_pos, t_vect_i dim, int color);

/*
**	Create MLX Entities
*/

t_imge			*ft_init_imge(void);
t_imge			*ft_create_imge(t_lmlx *mlx, int x, int y);
t_wind			*ft_create_wind(t_lmlx *mlx, char *name, int x, int y);

/*
**	Texture Management
*/

t_texture		*ft_new_ttexture(int value, char *path, t_imge *img);
int				ft_add_tex_to_nlist(t_nlist **list, int value, char *path, \
				t_imge *img);

/*
**	Unpacking
*/

int				ft_get_tex(t_game *jeu, t_imge *img, char *path);
int				ft_unpack_texture(t_game *jeu, t_texture *tex);
int				ft_unpack_list_textures(t_game *jeu, t_nlist *list);
int				ft_unpack_wall_textures(t_game *jeu);

/*
**	Sprite Management
*/

t_sprite		*ft_new_tsprite(t_texture *tex, int x, int y, char c);
int				ft_lstadd_sprite_instance(t_game *jeu, int x, int y, char c);
int				ft_create_spris_tab(t_level *lev);


/*
**	Keyhooks
*/

int				ft_keypress(int key, t_game *jeu);
int				ft_keyrelease(int key, t_game *jeu);
int				ft_more_keycodes(t_game *jeu, t_level *lev);
int				ft_keycodes(t_game *jeu);

/*
**	Math
*/

t_vect_i		ft_fill_vect_i(int x, int y);
int				ft_expected_size(char **tab, int e);
int				ft_rgb_to_int(int r, int g, int b, int t);
int				ft_pix_imge(t_imge *img, int pos, int color);
int				ft_draw_col_to_imge(t_imge *img, t_vect_i row, int col, int color);

/*
**	Player Movement
*/

int				ft_move_forward(t_game *jeu);
int				ft_move_backward(t_game *jeu);
int				ft_move_left(t_game *jeu);
int				ft_move_right(t_game *jeu);

/*
**	Player Rotation
*/

int				ft_rot_right(t_game *jeu, double rot_speed);
int				ft_rot_left(t_game *jeu, double rot_speed);

/*
**	Toggle Buttons
*/

int				ft_toggle_on(int *button);
int				ft_toggle_off(int *button);

/*
**	Mouse Commands
*/

int				ft_mouse_move(int x, int y, t_game *jeu);
int				ft_mouse_press(int button, int x, int y, t_game *jeu);
int     		ft_fire(t_game *jeu, t_vect_t map_step, t_vect_d delta_dist, \
				t_vect_d side_dist);
int				ft_shoot_something(t_game *jeu);

/*
**	Sprite Behavior
*/

int				ft_rot_sprite(t_level *lev, int i);
int				ft_move_sprite(t_level *lev, int i);
int				ft_kill_sprite(t_game *jeu, int index);

/*
**	More nList
*/

int				ft_print_nlist(t_nlist *lst);
int				ft_finish_del_spris(t_nlist **lst, t_nlist **tmp, int n);
int				ft_nlstdel_n_sprite(t_nlist **lst, int n);
int				ft_nlstadd_secback(t_nlist **lst, void *content);

/*
**	Free MLX
*/

int				ft_free_timge(t_game *jeu, t_imge *img);
int				ft_free_twind(t_game *jeu);
int				ft_free_tlmlx(t_game *jeu);

/*
**	Free Sprites
*/

int				ft_free_ttexture_contents(t_game *jeu, t_texture *tex);
int				ft_free_tsprite_contents(t_sprite *spri);
int				ft_free_tsprite_tab(t_sprite *spris, int n);

/*
**	Free Lists
*/

int				ft_free_texture_list(t_game *jeu, t_nlist **lst);
int				ft_free_sprites_list(t_nlist **lst);
int				ft_free_level_list(t_nlist **lst);

/*
**	Quit
*/

int				ft_finish_free_input(t_game *jeu);
int				ft_free_tinput_contents(t_game *jeu);
int				ft_free_tlevel_contents(t_level *lev);
int				ft_finish_quit(t_game *jeu);
int				ft_quit(t_game *jeu);

/*
**	Utils
*/

size_t			ft_sstrlen(const char *s);
int				ft_sfindchar(char *str, char c);
char			*ft_strsub(char *s, unsigned int start, size_t len);
int				ft_ibzero(void *s, size_t n);
char			*ft_gstrjoin(char **s1, char *s2);


/*
**	Prime Engine Mac and Linux
*/

int				ft_prime_engine(t_game *jeu);

#endif





