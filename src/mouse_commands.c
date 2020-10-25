/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:02:15 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/26 00:17:03 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


	// Essencially useless now...
int		ft_capture_mouse_pos(int x, int y, t_game *jeu)
{
	printf("capture mouse pos\n");

	jeu->mouse.x = x;
	jeu->mouse.y = y;
	return (1);
}

	// change rot speed or make so mouse x dif needs to be greater and
	// only update if calls rot ?...

int		ft_mouse_move(int x, int y, t_game *jeu)
{
	(void)y;

	// calc the dif btw this and og, then take that and apply to rot
	if (!jeu->set->bonus)
		return (1);

//	printf("mouse x: %d, y: %d\n", x, y);

	if (x - jeu->mouse.x < 0)
		ft_rot_left(jeu);
	else if (x - jeu->mouse.x > 0)
		ft_rot_right(jeu);

	// should i put this before the rot call ???
	jeu->mouse.x = x;

	return (1);
}

// can also be triggered by up button
int		ft_shoot_something(t_game *jeu)
{
	int		nhit;
	int		i;
	t_vect_i    map;
	t_vect_d    delta_dist;
	t_vect_d    side_dist;
	t_vect_i    step;
	
	map.x = (int)jeu->me->pos.x;
	map.y = (int)jeu->me->pos.y;
	delta_dist = ft_calc_delta_dist(jeu->me->dir);

	step.x = (jeu->me->dir.x < 0) ? -1 : 1;
	step.y = (jeu->me->dir.y < 0) ? -1 : 1;
	side_dist.x = (jeu->me->dir.x < 0) ? (jeu->me->pos.x - map.x) \
			* delta_dist.x : (map.x + 1.0 - jeu->me->pos.x) * delta_dist.x;
	side_dist.y = (jeu->me->dir.y < 0) ? (jeu->me->pos.y - map.y) \
			* delta_dist.y : (map.y + 1.0 - jeu->me->pos.y) * delta_dist.y;
	nhit = 1;
	while (nhit && ((char**)jeu->lev->floor)[map.y][map.x] != '1')
	{
		ft_dda(&map, &step, &side_dist, &delta_dist);
		i = 0;
		while (nhit && i < jeu->lev->n_spris)
		{
//			printf("map x: %d, y: %d\n", map.x, map.y);
			if (jeu->lev->spris_tab[i].tex && map.x == (int)jeu->lev->spris_tab[i].pos.x \
				&& map.y == (int)jeu->lev->spris_tab[i].pos.y)
			{
				// if in cell then check more precicely where in cell
				// cuz they might move
	
				printf("we hit a thing\n");
				nhit = 0;
				jeu->lev->spris_tab[i].anim_color = 220;
				jeu->lev->spris_tab[i].life -= 50;


		// new func
				if (jeu->lev->spris_tab[i].life == 0)
				{
					printf("spris_tab[%d]\n", i);

					if (!ft_sprite_dies(jeu, i))
						return (ft_error_msg("failed to kill sprite\n", 0));
				//	jeu->lev->spris_tab[i].tex = NULL;
				}
				// the thing we hit, we add a value that will be added
				// to it's color, and every redraw that value decreaces
				// until it's 0
			}
			++i;
		}
	}
	return (1);
}

int		ft_mouse_press(int button, int x, int y, t_game *jeu)
{
	// essencially we want to shoot a ray from the player forward...
	// each map cell we check if there is something in it...
	// if hit something, we turn it red

//	(void)button;
	(void)x;
	(void)y;

	if (button == M_CLK_L && !ft_shoot_something(jeu))
		return (ft_error_msg("failed to shoot something\n", 0));

	return (1);
}


	// move to sprite movement

int		ft_sprite_dies(t_game *jeu, int index)
{
//	t_nlist	*tmp;
	int		i;

	// could make creation of spris tab a func that is reused here and in floor manage

//	printf("sprite dies test 1\n");

	if (index == jeu->lev->key_index)
	{
		jeu->me->key = 1;
		jeu->lev->key_index = -1;
	}

	// now this frees the instance of the sprite and sets tex in it to null, not free tex
	if (!ft_nlstdel_n_sprite(&jeu->lev->spris_list, index))
		return (ft_error_msg("failed to del dead sprite\n", 0));


	// could use ft_free_tsprite_tab

//	printf("sprite dies test 2\n");
		// could also be a seperate func that would be very useful
	// don't actually free the textures or imgs cuz they exist seperately
	i = 0;
	while (i < jeu->lev->n_spris)
	{
		jeu->lev->spris_tab[i].tex = NULL;
//		lev->spris_tab[i] = NULL;
//		free(lev->spris_tab[i].tex);	// free or NULL ?
//		free(lev->spris_tab[i]);		// free or NULL ?
		++i;
	}

//	printf("sprite dies test 3\n");

//	free(lev->spris_tab);
	jeu->lev->spris_tab = NULL;

	--jeu->lev->n_spris;

		// this is a sep func
	if (jeu->lev->n_spris && !ft_create_spris_tab(jeu->lev))
		return (ft_error_msg("failed to create new spris tab\n", 0));
//	printf("sprite dies test 4\n");
	return (1);
}






