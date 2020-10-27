/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 01:22:22 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/26 15:42:36 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_create_file_header(unsigned char *file_header, t_game *jeu, int pad_size)
{
	int	file_size;

	file_size = 14 + 40 + (4 * jeu->file->res.x + pad_size) * jeu->file->res.y;
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(14 + 40);
	file_header[0 + 14] = (unsigned char)(40);
	file_header[4 + 14] = (unsigned char)(jeu->file->res.x);
	file_header[5 + 14] = (unsigned char)(jeu->file->res.x >> 8);
	file_header[6 + 14] = (unsigned char)(jeu->file->res.x >> 16);
	file_header[7 + 14] = (unsigned char)(jeu->file->res.x >> 24);
	file_header[8 + 14] = (unsigned char)(jeu->file->res.y);
	file_header[9 + 14] = (unsigned char)(jeu->file->res.y >> 8);
	file_header[10 + 14] = (unsigned char)(jeu->file->res.y >> 16);
	file_header[11 + 14] = (unsigned char)(jeu->file->res.y >> 24);
	file_header[12 + 14] = (unsigned char)(1);
	file_header[14 + 14] = (unsigned char)(4 * 8);
}

int		ft_screenshot(t_game *jeu)
{
	int				fd;
	unsigned char	padding[3];
	unsigned char	file_header[14 + 40];
	int				i;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0700);
	padding[0] = 0;
	padding[1] = 0;
	padding[2] = 0;
	ft_bzero(file_header, 14 + 40);
	ft_create_file_header(file_header, jeu, (4 - (jeu->file->res.x * 4) % 4) % 4);

	if (!ft_draw_imges(jeu))
		return (ft_error_msg("failed to draw imges\n", 0));	// free things ?

	write(fd, file_header, 14 + 40);
	i = jeu->file->res.y - 1;
	while (i > 0)
	{
		write(fd, (unsigned char*)jeu->fpv->img_data + (i * jeu->file->res.x * 4), \
			4 * jeu->file->res.x);
		write(fd, padding, (4 - (jeu->file->res.x * 4) % 4) % 4);
		--i;
	}
	close(fd);
	ft_putstr_fd("\033[32;1mScreenshot saved as 'screenshot.bmp'.\033[0m\n", 1);
	ft_quit(jeu);
	return (1);
}
