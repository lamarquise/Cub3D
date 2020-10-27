/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:21:47 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 19:00:17 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

			// _contents except i do actually free it
int		ft_free_tinput_contents(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (!jeu->file)
		return (1);
	if (jeu->file->no && !ft_free_ttexture_contents(jeu, jeu->file->no))
		return (ft_error_msg("failed to free NO ttex in file\n", 0));
	free(jeu->file->no);
	jeu->file->no = NULL;	// i think that's right	
	if (jeu->file->so && !ft_free_ttexture_contents(jeu, jeu->file->so))
		return (ft_error_msg("failed to free SO ttex in file\n", 0));
	free(jeu->file->so);
	jeu->file->so = NULL;
	if (jeu->file->ea && !ft_free_ttexture_contents(jeu, jeu->file->ea))
		return (ft_error_msg("failed to free EA ttex in file\n", 0));
	free(jeu->file->ea);
	jeu->file->ea = NULL;
	if (jeu->file->we && !ft_free_ttexture_contents(jeu, jeu->file->we))
		return (ft_error_msg("failed to free WE ttex in file\n", 0));
	free(jeu->file->we);
	jeu->file->we = NULL;

	if (jeu->file->spri_type_texs && !ft_free_texture_list(jeu, \
		&jeu->file->spri_type_texs))
		return (ft_error_msg("failed to free spri tex list in file\n", 0));
	// already null ?

	if (jeu->file->floor && !ft_free_ttexture_contents(jeu, jeu->file->floor))
		return (ft_error_msg("failed to free floor ttex in file\n", 0));
	free(jeu->file->floor);
	jeu->file->floor = NULL;
	if (jeu->file->ceiling && !ft_free_ttexture_contents(jeu, jeu->file->ceiling))
		return (ft_error_msg("failed to free Ceiling ttex in file\n", 0));
	free(jeu->file->ceiling);
	jeu->file->ceiling = NULL;

//	free(jeu->file);	// can't be freed
	jeu->file = NULL;

	return (1);
}

int		ft_free_tlevel_contents(t_level *lev)
{
	if (!lev)
		return (1);	// 1 ?	// or 0 cuz we are supposed to have checked before if exists
	if (lev->floor && !ft_free_strtab(lev->floor))
		return (ft_error_msg("failed to free floor in lev\n", 0));
	lev->floor = NULL;
	
	if (lev->spris_tab && !ft_free_tsprite_tab(lev->spris_tab, lev->n_spris))
		return (ft_error_msg("failed to free spris tab and spris instances in lev\n", 0));
		// does freeing the tab destroy the sprite intsances ?
		// could just nlstdel all the spri list after that...
	lev->spris_tab = NULL;

	if (lev->spris_list && !ft_nlstdel_all(&lev->spris_list))
		return (ft_error_msg("failed to del spris list in lev\n", 0));	
	lev->spris_list = NULL;

	return (1);
}

		// rename to quit ???
//int		ft_free_tgame(t_game *jeu)
int			ft_quit(t_game *jeu)
{
	if (!jeu)
		return (0);	// 1 ? 0 ?

	if (jeu->file && !ft_free_tinput_contents(jeu))
		return (ft_error_msg("failed to free file in jeu\n", 0));
	jeu->file = NULL;	// useful ?

	if (jeu->level_list && !ft_free_level_list(&jeu->level_list))
		return (ft_error_msg("failed to free level list in jeu\n", 0));
//	jeu->level_list = NULL; // unnecessary i believe, happens in func
	
	if (jeu->lev)
	{
//		free(jeu->lev);	// free or NULL ? cuz lev would be freed by level list free...
		jeu->lev = NULL;
	}
	if (jeu->me)
		jeu->me = NULL;
	if (jeu->set)
		jeu->set = NULL;

	if (jeu->yah && !ft_free_timge(jeu, jeu->yah))
		return (ft_error_msg("failed to free yah in jeu\n", 0));
	jeu->yah = NULL;
	if (jeu->crosshair && !ft_free_timge(jeu, jeu->crosshair))
		return (ft_error_msg("failed to free crosshair in jeu\n", 0));
	jeu->crosshair = NULL;
	if (jeu->minimap && !ft_free_timge(jeu, jeu->minimap))
		return (ft_error_msg("failed to free minimap in jeu\n", 0));
	jeu->minimap = NULL;
	if (jeu->fpv && !ft_free_timge(jeu, jeu->fpv))
		return (ft_error_msg("failed to free fpv in jeu\n", 0));
	jeu->fpv = NULL;

	// other sprite in minimap imges

	// free the non pointer vars ???

	if (jeu->win && !ft_free_twind(jeu))
		return (ft_error_msg("failed to free win in jeu\n", 0));
		// has to be freed last
	if (jeu->mlx && !ft_free_tlmlx(jeu))
		return (ft_error_msg("failed to free mlx in jeu\n", 0));


//	free(jeu);	// never malloced
	exit(0);

	return (1);
}






