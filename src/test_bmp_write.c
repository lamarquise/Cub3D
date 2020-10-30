/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bmp_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 21:04:04 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/30 23:10:25 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int		write_bmp_header(int fd, int filesize, t_imge *img)
{
	int				i;
	int				tmp;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = img->img_wid;
	set_int_in_char(bmpfileheader + 18, tmp);
	tmp = img->img_hei;
	set_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[27] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

//	get_color(t_window *w, int x, int y)
static int		get_color(t_imge *img, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int*)(img->img_data
			+ (4 * (int)img->img_wid * ((int)img->img_hei - 1 - y))
			+ (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int		write_bmp_data(int file, t_imge *img, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < (int)img->img_hei)
	{
		j = 0;
		while (j < (int)img->img_wid)
		{
			color = get_color(img, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_save_bmp(t_game *jeu)
{
	t_imge		*img;
	int			filesize;
	int			file;
	int			pad;

	if (!ft_draw_imges(jeu))
		return (ft_error_msg("failed to draw imges\n", 0)); // free things ?

	img = jeu->fpv;
	pad = (4 - ((int)img->img_wid * 3) % 4) % 4;
	filesize = 54 + (3 * ((int)img->img_wid + pad) * (int)img->img_hei);
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT
									| O_TRUNC | O_APPEND)) < 0)
		return (0);
	if (!write_bmp_header(file, filesize, img))
		return (0);
	if (!write_bmp_data(file, img, pad))
		return (0);
	close(file);
	return (1);
}
