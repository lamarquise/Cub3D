/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_buttons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 02:50:29 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/04 04:24:20 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"


	// make this func less generic by adding contions where some buttons can
	// only be toggled on if bonus active ???
	// would need to send jeu and button, or bonus and button, either way
	// pretty annoying...
int		ft_toggle_on(int *button)
{
//	jeu->settings |= shift;

	*button = 1;
	return (1);
}

int		ft_toggle_off(int *button)
{
	// does seem to obliterate all other data
	// may need to do research on how better to use bitwise
//	jeu->settings &= shift;

	*button = 0;
	return (1);
}

