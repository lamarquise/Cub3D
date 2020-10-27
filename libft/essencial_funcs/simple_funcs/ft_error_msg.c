/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:11:03 by ericlazo          #+#    #+#             */
/*   Updated: 2020/09/23 15:08:26 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_error_msg(char *str, int ret)
{
	if (!str)
		return (ret);
	ft_putstr(str);
	return (ret);
}
