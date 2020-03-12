/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:47:40 by erlazo            #+#    #+#             */
/*   Updated: 2019/11/16 17:18:08 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstgen(char *s, char c)
{
	int		i;
	t_list	*list;
	char	**tab;

	i = 0;
	list = NULL;
	if (!(tab = ft_split(s, ft_fill_with(c, 1))))
		return (NULL);
	while (tab[i])
	{
		ft_lstadd_front(&list, ft_lstnew(tab[i]));
		++i;
	}
	return (list);
}
