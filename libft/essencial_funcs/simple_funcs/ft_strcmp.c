/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:53:14 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/09 22:35:35 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while ((char)*s1 && (char)*s2 && (char)*s1 == (char)*s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
