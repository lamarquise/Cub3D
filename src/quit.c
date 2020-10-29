/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:21:47 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/29 09:44:43 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_finish_free_input(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (jeu->file->no && !ft_free_ttexture_contents(jeu, jeu->file->no))
		return (ft_error_msg("failed to free NO ttex in file\n", 0));
	free(jeu->file->no);
	jeu->file->no = NULL;
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
	return (1);
}

int		ft_free_tinput_contents(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (!jeu->file)
		return (1);
	if (!ft_finish_free_input(jeu))
		return (0);
	if (jeu->file->spri_type_texs && !ft_free_texture_list(jeu, \
		&jeu->file->spri_type_texs))
		return (ft_error_msg("failed to free spri tex list in file\n", 0));
	if (jeu->file->floor && !ft_free_ttexture_contents(jeu, jeu->file->floor))
		return (ft_error_msg("failed to free floor ttex in file\n", 0));
	free(jeu->file->floor);
	jeu->file->floor = NULL;
	if (jeu->file->ceiling && !ft_free_ttexture_contents(jeu, \
		jeu->file->ceiling))
		return (ft_error_msg("failed to free Ceiling ttex in file\n", 0));
	free(jeu->file->ceiling);
	jeu->file->ceiling = NULL;
	jeu->file = NULL;
	return (1);
}

int		ft_free_tlevel_contents(t_level *lev)
{
	if (!lev)
		return (1);
	if (lev->floor && !ft_free_strtab(lev->floor))
		return (ft_error_msg("failed to free floor in lev\n", 0));
	lev->floor = NULL;
	if (lev->spris_tab && !ft_free_tsprite_tab(lev->spris_tab, lev->n_spris))
		return (ft_error_msg("failed to free spris tab in lev\n", 0));
	lev->spris_tab = NULL;
	if (lev->spris_list && !ft_free_sprites_list(&lev->spris_list))
		return (ft_error_msg("failed to del spris list in lev\n", 0));
	lev->spris_list = NULL;
	return (1);
}

int		ft_finish_quit(t_game *jeu)
{
	if (!jeu)
		return (0);
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
	if (jeu->win && !ft_free_twind(jeu))
		return (ft_error_msg("failed to free win in jeu\n", 0));
	if (jeu->mlx && !ft_free_tlmlx(jeu))
		return (ft_error_msg("failed to free mlx in jeu\n", 0));
	return (1);
}

int		ft_quit(t_game *jeu)
{
	if (!jeu)
		return (0);
	if (jeu->file && !ft_free_tinput_contents(jeu))
		return (ft_error_msg("failed to free file in jeu\n", 0));
	if (jeu->level_list && !ft_free_level_list(&jeu->level_list))
		return (ft_error_msg("failed to free level list in jeu\n", 0));
	if (jeu->lev)
		jeu->lev = NULL;
	if (jeu->me)
		jeu->me = NULL;
	if (jeu->set)
		jeu->set = NULL;
	if (!ft_finish_quit(jeu))
		return (0);
	exit(0);
	return (1);
}
