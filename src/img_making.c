


#include "cub3d.h"

int			ft_gen_bground(t_game *jeu)
{
	long	c_co;
	long	f_co;
	int		pix;
	int		stop;

	c_co = jeu->file->c->r * 65536 + jeu->file->c->g * 256 + jeu->file->c->b;
	f_co = jeu->file->f->r * 65536 + jeu->file->f->g * 256 + jeu->file->f->b;
	pix = 0;
	stop = (jeu->file->res_x * jeu->file->res_y) / 2;
	while (pix < stop)
	{
		jeu->hud->bground->img_data[pix] = c_co;
		++pix;
	}
	stop = jeu->file->res_x * jeu->file->res_y;
	while (pix < stop)
	{
		jeu->hud->bground->img_data[pix] = f_co;	// do i have to fill
		++pix;										// 1 pix at a time ???
	}
	// cut screan in 2


	return (1);
}


	// assuming fov is the size of the map window
int			ft_make_map_fov(t_game *jeu)
{
	int		pos;

	pos = ft_coord_convert(jeu->map->win, jeu->map->fov, \
		jeu->me->x, jeu->me->y);

	printf("mex: %d, mey: %d,pos: %d\n", jeu->me->x, jeu->me->y, pos);

	jeu->map->fov->img_data[pos - jeu->map->floor->img_wid * 2] = 0xFF0000;
	jeu->map->fov->img_data[pos - (jeu->map->floor->img_wid) * 2] = 0xFF0000;
	jeu->map->fov->img_data[pos + (jeu->map->floor->img_wid)] = 0xFF0000;
	jeu->map->fov->img_data[pos + (jeu->map->floor->img_wid) * 2] = 0xFF0000;

	jeu->map->fov->img_data[pos - 2] = 0xFF0000;
	jeu->map->fov->img_data[pos - 1] = 0xFF0000;
	jeu->map->fov->img_data[pos + 1] = 0xFF0000;
	jeu->map->fov->img_data[pos + 2] = 0xFF0000;

	jeu->map->fov->img_data[pos] = 0xFF0000;

	return (1);
}


int			ft_make_2D_floor_img(t_game *jeu)
{
	int		y;
	int		x;
	int		box;
	int		x_step;
	int		y_step;
	long	color;
	t_nlist	*tmp;
	int		last_box;

	box = 0;
	x_step = 0;
	y_step = 0;
	color = 0;
	tmp = jeu->floor;	
	last_box = jeu->x_boxes * jeu->y_boxes;

//	printf("last box: %d\n", last_box);

	while (box < last_box)
	{
//		printf("creat img loop test 1\n");
		if (((char*)tmp->content)[x_step] == '1')
			color = 0xEEEEEE;
		else if (((char*)tmp->content)[x_step] == '0')
			color = 0x666666;
		else
			color = 0x000000;
//		printf("color: %#lx\n", color);
		y = 0;
		while (y < U)
		{
//			printf("coloring a row\n");
			x = 0;
			while (x < U)
			{
				jeu->map->floor->img_data[(x_step * (U + G) + x) + \
					(jeu->map->floor->img_wid * ((U + G) * \
					y_step + y))] = color;
//				printf("just colored\n");
				++x;
			}
			++y;
		}
		if (x_step < jeu->x_boxes - 1)
			++x_step;
		else
		{
			x_step = 0;
			++y_step;
			tmp = tmp->next;
		}
		++box;
	}
//	printf("creat img end\n");
	
	return (1);
}





