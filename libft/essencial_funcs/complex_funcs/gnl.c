/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2020/10/28 13:38:00 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		gnl(char **l, char **s, int b_size, int fd)
{
	ssize_t	i;
	char	*p;
	char	b[b_size + 1];

	p = NULL;
	if ((i = ft_findchar(*s, '\n')) != -1)
	{
		if (!(*l = ft_substr(*s, 0, (size_t)i++))
			|| (!(p = ft_substr(*s, i, ft_strlen(*s) - (size_t)i))))
			return (-1);
		free(*s);
		*s = p;
		return (1);
	}
	ft_bzero(b, b_size + 1);
	if ((i = read(fd, b, b_size)) < 0
		|| (i > 0 && !(p = ft_strjoin(*s, b)))
		|| (*s[0] && ++i == 1 && !(p = ft_strjoin(*s, "\n"))))
		return (-1);
	free(*s);
	*s = p;
	return ((i > 0) ? gnl(l, s, b_size, fd) : 0);
}
