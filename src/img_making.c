


#include "cub3d.h"

	// for now assume wid and hei are / 10

	// eventually an arg is func that determins how img is made....
int			ft_create_img(t_img *pic, t_floorplan *level)
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
	
	pic->last_box = level->width * level->height;

	printf("level wid: %d, level hei: %d\n", level->width, level->height);
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
		else
			color = 0x000000;
//		printf("color: %#lx\n", color);
		y = 0;	// 1 to 10
		while (y < 1)
		{
			a = 0;
//			printf("coloring a row\n");
			x = 350;	// 1 to 10
			while (x < 450)
			{
//				printf("coloring a col\n");
//				printf("x: %d, y: %d\n", x, y);

//				pic->img_data[x + pic->img_wid * y] = color;

				a = x;
//				printf("a: %d\n", a);
				pic->img_data[a] = 0xFF0000;

//				a = x + pic->img_wid * y;
//				printf("a: %d\n", a);
//				pic->img_data[a] = color;
/*				pic->img_data[0] = color;
				pic->img_data[1] = color;
				pic->img_data[400] = color;
				pic->img_data[401] = color;
				pic->img_data[800] = color;
				pic->img_data[801] = color;
*/
//				pic->img_data[(x_step * U + x) + \
//					(pic->img_wid * (U * y_step + y))] = color;
//				printf("just colored\n");
				++x;
			}
//			x = 0;
//			while (x < 900)
//				pic->img_data[x++] = 0x0000FF;
//			printf("is this a problem ?\n");
			++y;
		}
//		printf("just colored\n");
		if (x_step < level->width - 1)
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





