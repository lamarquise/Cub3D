

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# include "libft.h"

# include "mlx.h"

// include mlx stuff...
// include math stuff...
// my printf



# define U 50



	// will need to make some mlx handling structs, see fractol for insp

	// make a generic linked list structure...

typedef struct	s_img
{
	void	*img_ptr;
	int		*img_data;
	
	int		img_wid;
	int		img_hei;
	int		last_pix;	// img starts at 0...

	int		last_box;	// exists for now...

}				t_img;

/*
typedef struct	s_win
{
	void	*win_ptr;
	t_img	*img;
}				t_win;
*/

typedef struct	s_mlx
{
	void	*ptr;
	void	*win_ptr;
	
	int		bpp;
	int		s_l;
	int		endian;
	
}				t_mlx;



	//	parsing structure...
typedef struct	s_floorplan
{
	// a linked list of gnl lines
	// the x and y sizes of the map
	t_nlist	*floor;

	int		width;
	int		height;

}				t_floorplan;

typedef struct	s_map
{
	int		resolution_x;
	int		resolution_y;
	
	// var for north texture
	// var for south texture
	// var for east texture
	// var for west texture

	char	*no_tex;	// just contains the path str ???
	char	*so_tex;
	char	*we_tex;
	char	*ea_tex;

	char	*sprit_tex;
	

	int		f_r;		// how to make these a path ???
	int		f_g;		// like for textured floor or celing...
	int		f_b;
	
	int		c_r;
	int		c_g;
	int		c_b;

// colors for bird's eye view map ???


	// floor color	// make var capable of taking a texture for bonus
	// cealing color // idem

	// sprite texture
	
	// player start orientation ???	does this need to be in this stuct
	
	t_floorplan	*level;		// good name ??? also, have levels ???
	// make floorplan a linked list??? or multiple files sent as av means 
	// many levels, or all in a single file ???


	// linked list of sprites ???

}				t_map;

// inventory structure ???
// weapons structure, like damage etc, armor ???


typedef struct	s_playerstate
{
	// life ???
	// orientation
	// position x and y
	
	// hitbox ???
	// weapon and or inventory linked list


}				t_playerstate;

typedef struct	s_spritestate
{
	// life
	// orientation
	// pos x and y

	// texture
	
	// identifier	// like a numer or something

	// hitbox ???

	// weapon and or damage


}				t_spritestate;		// has to be able to work for dif types
									// of sprite... like dif texture


	// Parse Files
int				ft_expected_size(char **tab, int e);
int				ft_retrieve_file_contents(int fd, t_nlist **f_lines);
int				ft_parse_file(int fd, t_map *file);


	// Img Making
int				ft_create_img(t_img *img, t_floorplan *level);


	// List Stuff
int				ft_print_nlst(t_nlist *lst);

#endif





