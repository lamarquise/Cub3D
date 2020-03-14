


#include "cub3d.h"

	// for now assume wid and hei are / 10

	// eventually an arg is func that determins how img is made....
int			ft_create_img(t_img *pic, t_floorplan *level, t_playerstate *player)
{
	int		y;
	int		x;
	int		box;
	int		x_step;
	int		y_step;
	long	color;
	int		a;
	t_nlist	*tmp;
	int		s_cord;

	box = 0;
	s_cord = 0;
	x_step = 0;
	y_step = 0;
	color = 0;
	tmp = level->floor;	// tmp is an nlist
	pic->last_pix = pic->img_wid * pic->img_hei;
	
	pic->last_box = level->x_boxes * level->y_boxes;
	
		// maybe this isnt where i should be adding the payer part.
	player->box = player->x + player->y * level->x_boxes;

	printf("level wid: %d, level hei: %d\n", level->x_boxes, level->y_boxes);
	printf("img wid:  %d, img hei: %d\n", pic->img_wid, pic->img_hei);
	printf("x_step: %d, y_step: %d\n", x_step, y_step);
	printf("last pix: %d, last box: %d\n", pic->last_pix, pic->last_box);

	while (box < pic->last_box)
	{
//		printf("creat img loop test 1\n");
		if (((char*)tmp->content)[x_step] == '1')
			color = 0xEEEEEE;
		else if (((char*)tmp->content)[x_step] == '0')
			color = 0x666666;
//		else if ((ft_findchar("NSEW", ((char*)tmp->content)[x_step])) != -1)
//			color = 0xFF0000;	// orange square if player...
		else
			color = 0x000000;
//		printf("color: %#lx\n", color);
		y = 0;	// 1 to 10
		while (y < U)
		{
			a = 0;
//			printf("coloring a row\n");
			x = 0;	// 1 to 10
			while (x < U)
			{
				pic->img_data[(x_step * (U + G) + x) + \
					(pic->img_wid * ((U + G) * y_step + y))] = color;
//				printf("just colored\n");
				++x;
			}
			++y;
		}
//		a = ft_coord_convert(mlx, file, x_step, y_step);

//		printf("just colored\n");
		if (x_step < level->x_boxes - 1)
			++x_step;
		else
		{
			x_step = 0;
			++y_step;
			tmp = tmp->next;
		}		// find better way of using pos...
		++box;
//		pos = x_step * 10 + (y_step * level->width * 10);
//		printf("creat img loop end, pos: %d\n", pos);
	}
	printf("creat img end\n");
	
	return (1);
}





