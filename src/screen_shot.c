/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_shot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:19:13 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/31 22:48:49 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

int		ft_write_bmp_header(t_game *jeu, int fd, int filesize)
{
	int				i;
	int				tmp;
	unsigned char	bmpfileheader[54];

	if (!jeu)
		return (0);
	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	ft_set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = jeu->file->res.x;
	ft_set_int_in_char(bmpfileheader + 18, tmp);
	tmp = jeu->file->res.y;
	ft_set_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

int		ft_get_bmp_color(t_game *jeu, int x, int y)
{
	int	color;

	if (!jeu)
		return (-1);
	color = *(int*)(jeu->fpv->img_data + (4
		* jeu->file->res.x * (jeu->file->res.y - 1 - y)) + (4 * x));
	return (color);
}

int		ft_write_bmp_data(t_game *jeu, int file)
{
	int					i;
	int					j;
	int					color;

	if (!jeu)
		return (0);
	i = 0;
	while (i < jeu->file->res.y)
	{
		j = 0;
		while (j < jeu->file->res.x)
		{
			color = ft_get_bmp_color(jeu, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_screen_shot(t_game *jeu)
{
	int			filesize;
	int			file;

	if (!jeu || !ft_draw_imges(jeu))
		return (0);

	filesize = 54 + (3 * jeu->file->res.x * jeu->file->res.y);
	if ((file = open("screenshot.bmp", \
		O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644)) < 0)
		return (0);
	if (!ft_write_bmp_header(jeu, file, filesize))
		return (0);
	if (!ft_write_bmp_data(jeu, file))
		return (0);
	close(file);
	ft_putstr_fd("\033[32;1mScreenshot saved as 'screenshot.bmp'.\033[0m\n", 1);
	ft_quit(jeu);
	return (1);
}
