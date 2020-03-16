

#include "cub3d.h"


void    ft_light_torch(t_key *torch)
{
	torch[0].keycode = 53;
	torch[0].f = &ft_quit;


	// W:126 A:123 S:125 D:124 

	// arrow up: 116 down: 121



}


int     ft_keyhooks(int keycode, t_game *jeu)
{
	static t_key    torch[20] = {{42, NULL}};
	int				i;

	i = 0;
	if (torch[0].keycode == 42)
		ft_light_torch(torch);
	while (i < 20)	// number of codes added
	{
		if (keycode == torch[i].keycode)
			return (torch[i].f(jeu));
		++i;
	}
	return (0);
}

void    ft_hooks_loop(t_game *jeu)
{		//was mlx->win_ptr
	mlx_hook(jeu->map->win->win_ptr, 2, 0, &ft_keyhooks, jeu);
	mlx_hook(jeu->map->win->win_ptr, 17, 0, &ft_quit, jeu);
}
