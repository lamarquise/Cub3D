


#include "cub3d.h"

int		key_press(int keycode, t_window *win)
{
	if (keycode == ESC_KEY)
		close_window(win);
	if (keycode == W_KEY)
	{
		double move_speed = 0.1;
		if (win->set.map[(int)(win->set.player_x + win->set.player_dir_x * move_speed - 0.02)][(int)win->set.player_y] == '0')
			win->set.player_x += win->set.player_dir_x * move_speed;
		if (win->set.map[(int)win->set.player_x][(int)(win->set.player_y + win->set.player_dir_y * move_speed - 0.02)] == '0')
			win->set.player_y += win->set.player_dir_y * move_speed;
	}
	if (keycode == A_KEY)
	{
		double move_speed = 0.1;
		if (win->set.map[(int)(win->set.player_x - win->scene.plane_x * move_speed + 0.02)][(int)win->set.player_y] == '0')
			win->set.player_x -= win->scene.plane_x * move_speed;
		if (win->set.map[(int)win->set.player_x][(int)(win->set.player_y - win->scene.plane_y * move_speed + 0.02)] == '0')
			win->set.player_y -= win->scene.plane_y * move_speed;
	}
	if (keycode == S_KEY)
	{
		double move_speed = 0.1;
		if (win->set.map[(int)(win->set.player_x - win->set.player_dir_x * move_speed + 0.02)][(int)win->set.player_y] == '0')
			win->set.player_x -= win->set.player_dir_x * move_speed;
		if (win->set.map[(int)win->set.player_x][(int)(win->set.player_y - win->set.player_dir_y * move_speed + 0.02)] == '0')
			win->set.player_y -= win->set.player_dir_y * move_speed;
	}
	if (keycode == D_KEY)
	{
		double move_speed = 0.1;
		if (win->set.map[(int)(win->set.player_x + win->scene.plane_x * move_speed - 0.02)][(int)win->set.player_y] == '0')
			win->set.player_x += win->scene.plane_x * move_speed;
		if (win->set.map[(int)win->set.player_x][(int)(win->set.player_y + win->scene.plane_y * move_speed - 0.02)] == '0')
			win->set.player_y += win->scene.plane_y * move_speed;
	}
	if (keycode == RIGHT_KEY)
	{
		double rotSpeed = 0.04;
		double oldDirX = win->set.player_dir_x;
		win->set.player_dir_x = win->set.player_dir_x * cos(-rotSpeed) - win->set.player_dir_y * sin(-rotSpeed);
		win->set.player_dir_y = oldDirX * sin(-rotSpeed) + win->set.player_dir_y * cos(-rotSpeed);
		double oldPlaneX = win->scene.plane_x;
		win->scene.plane_x = win->scene.plane_x * cos(-rotSpeed) - win->scene.plane_y * sin(-rotSpeed);
		win->scene.plane_y = oldPlaneX * sin(-rotSpeed) + win->scene.plane_y * cos(-rotSpeed);
	}
	if (keycode == LEFT_KEY)
	{
		double rotSpeed = -0.04;
		double oldDirX = win->set.player_dir_x;
		win->set.player_dir_x = win->set.player_dir_x * cos(-rotSpeed) - win->set.player_dir_y * sin(-rotSpeed);
		win->set.player_dir_y = oldDirX * sin(-rotSpeed) + win->set.player_dir_y * cos(-rotSpeed);
		double oldPlaneX = win->scene.plane_x;
		win->scene.plane_x = win->scene.plane_x * cos(-rotSpeed) - win->scene.plane_y * sin(-rotSpeed);
		win->scene.plane_y = oldPlaneX * sin(-rotSpeed) + win->scene.plane_y * cos(-rotSpeed);
	}

	return (0);
}

void	hook_event(t_window *win)
{
	mlx_hook(win->win_ptr, 2, 0, key_press, win);
	mlx_hook(win->win_ptr, 17, (1L << 17), close_window, win);
}

int		close_window(t_window *win)
{
	window_destructor(win);
	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (LEAKS)
		system("leaks Cub3D");
	exit(0);
	return (0);
}

int		quit_error(t_window *win, char *error, void *tofree, void (*f)(char**))
{
	window_destructor(win);
	ft_putstr_fd("\033[0;31mError: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n\033[0m", 2);
	if (tofree && f)
		(*f)(tofree);
	if (LEAKS)
		system("leaks Cub3D");
	exit(0);
	return (0);
}
