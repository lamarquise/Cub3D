/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_buttons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 02:50:29 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/27 23:07:18 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_toggle_on(int *button)
{
	*button = 1;
	return (1);
}

int		ft_toggle_off(int *button)
{
	*button = 0;
	return (1);
}
