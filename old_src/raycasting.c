/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:43:38 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/25 18:44:46 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"


void	pixel(t_game *jeu, int x, int y, int color)
{
//	printf("pixel put\n");

	if (x >= 0 && x < jeu->file->res_x && y >= 0 && y < jeu->file->res_y)
		(jeu->hud->img_data)[y * jeu->file->res_x + x] = color;
//	printf("pixel put end\n");
	
}

void	draw_line_ver(t_game *jeu, int x, int start, int end, int color)
{
	while (start < end)
	{
		pixel(jeu, x, start, color);
		start++;
	}
}

void	draw_square(t_game *jeu, int x, int y, int size, int color)
{
	int i = 0;
	while(i < size)
	{
		int j = 0;
		while (j < size)
		{
			pixel(jeu, x + i, y + j, color);
			j++;
		}
		i++;
	}
}


/*
void	minimap(t_window *win)
{
	int px = (int)win->set.player_x;
	int py = (int)win->set.player_y;
	int x = 0;
	int offsetx = jeu->file->res_x - 300;
	while (jeu->floor[x])
	{
		int y = 0;
		int offsety = jeu->file->res_y - 20;
		while (jeu->floor[x][y])
		{
			
			if (jeu->floor[x][y] == '1')
			{
				draw_square(win, y + offsety, x + offsetx, 5, RED);
			}
			if (jeu->floor[x][y] == '0')
			{
				draw_square(win, y + offsety, x + offsetx, 5, WHITE);
			}
			if (jeu->floor[x][y] == '2')
			{
				draw_square(win, y + offsety, x + offsetx, 5, YELLOW);
			}
			if (jeu->floor[x][y] == 'N' || jeu->floor[x][y] == 'W')
			{
				draw_square(win, y + offsety, x + offsetx, 5, BLUE);
			}
			if (x == px && y == py)
				draw_square(win, y + offsety, x + offsetx, 5, BLUE);
			y++;
			offsety += 5;
		}
		x++;
		offsetx += 5;
	}
}
*/



int		ft_raycasting(t_game *jeu)
{

	printf("Raycasting test 1\n");

	int x;
	double posX = jeu->me->x;
	double posY = jeu->me->y;

	// consider adding time btw frames
	double	time;
	double	old_time;

	time = 0;
	old_time = 0;
	x = 0;

	while (x < jeu->file->res_x)
	{

		printf("Raycasting test 1\n");

		//calculate rays pos and dir
		// cameraX is FOV 2 * atan(0.66/1) = 66 degees
		// -1 cuz starts at 0 goes to 1 thus also *2
		double cameraX = 2 * x / (double)jeu->file->res_x - 1;
		double rayDirX = jeu->me->d_x + jeu->plane_x * cameraX;
		double rayDirY = jeu->me->d_y + jeu->plane_y * cameraX;

		//index of the map based on player position
		int mapX = (int)posX;
		int mapY = (int)posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
		double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //variable to know if wall hit
		int side; //variable to know what side of wall hit

		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		//digital differencial algorithm DDA
		while (hit == 0)
		{
			printf("Raycasting test 4 hit loop\n");
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (jeu->floor[mapY][mapX] == '1' || jeu->floor[mapY][mapX] == '2')
			{
				hit = 1;
				//printf("x = %d, hit %d %d\t", x, mapX, mapY);
			}
		}

		printf("Raycasting test 5 out of hit loop\n");

		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
      	else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(jeu->file->res_y / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + jeu->file->res_y / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + jeu->file->res_y / 2;
		if(drawEnd >= jeu->file->res_y)
			drawEnd = jeu->file->res_y;
		
		draw_line_ver(jeu, x, 0, drawStart, jeu->file->c);
		draw_line_ver(jeu, x, drawEnd, jeu->file->res_y, jeu->file->f);
		
		printf("Raycasting test 6\n");
		
		//PARTIE TEXTURE
		int color;

		double wallX;
		if (side == 0)
			wallX = posY + perpWallDist * rayDirY;
		else
			wallX = posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);
		
		//determiner quelle texture-> en fonction orientation

		t_imge 	*texture;

		texture = NULL;
		if (jeu->floor[mapY][mapX] == '1')
		{
			if (side == 0)
			{
				if (rayDirX < 0)
					texture = jeu->file->no_tex; //N
				else
					texture = jeu->file->so_tex; //S
			}
			else
			{
				if (rayDirY < 0)
					texture = jeu->file->we_tex; //W
				else
					texture = jeu->file->ea_tex; //E
			}
		}

		printf("Raycasting test 8\n");

		int texX = (int)(wallX * (double)texture->img_wid);
		if (side == 0 && rayDirX > 0)
			texX = texture->img_wid - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texture->img_wid - texX - 1;
		
		printf("Raycasting test 9\n");
		double step = 1.0 * texture->img_hei / lineHeight;
		double texPos = (drawStart - jeu->file->res_y / 2 + lineHeight / 2) * step;
		int y = drawStart;

		printf("drawStart: %d, drawEnd: %d\n", drawStart, drawEnd);	
		printf("mapX: %d, mapY: %d\n", mapX, mapY);	
		while (y < drawEnd)
		{
//			printf("Raycasting test 10\n");
			
			int texY = (int)texPos & (texture->img_hei - 1);
			texPos += step;
//			printf("Raycasting test 10 pre floor\n");
			if (jeu->floor[mapX][mapY] == '1')
			{
//				printf("Raycasting test 10 floor\n");
				color = texture->img_data[texture->img_hei * texY + texX];
			}
			else
			{
//				printf("Raycasting test 10 yellow\n");
				color = YELLOW;
			}
			pixel(jeu, x, y, color);
//			printf("Raycasting test 10 end\n");
			y++;
		}
		printf("Raycasting test 11\n");

		//PARTIE COLOR QUI MARCHE BIEN
		//int color;
		/*
		if (jeu->floor[mapX][mapY] == '1')
		{
			if (side == 0)
			{
				if (rayDirX < 0)
					color = RED; //N
				else
					color = YELLOW; //S
			}
			else
			{
				if (rayDirY < 0)
					color = BLUE; //W
				else
					color = PURPLE; //E
			}
		}
		else if (jeu->floor[mapX][mapY] == '2')
			color = YELLOW;
		else
			color = BLACK;
		draw_line_ver(win, x, drawStart, drawEnd, color);
		*/
		x++;

		printf("Raycasting test end of ray loop\n");

	}


	return(1);
}


