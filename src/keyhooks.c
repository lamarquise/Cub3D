

#include "cub3d.h"


void    ft_light_torch(t_key *torch)
{
	torch[0].keycode = 53;
	torch[0].f = &ft_quit;



}


int     ft_keyhooks(int keycode, t_mlx *mlx)
{
	static t_key    torch[20] = {{42, NULL}};
	int				i;

	i = 0;
	if (torch[0].keycode == 42)
		ft_light_torch(torch);
	while (i < 20)	// number of codes added
	{
		if (keycode == torch[i].keycode)
			return (torch[i].f(mlx));
		++i;
	}
	return (0);
}

void    ft_hooks_loop(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 2, 0, &ft_keyhooks, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, &ft_quit, mlx);
}
