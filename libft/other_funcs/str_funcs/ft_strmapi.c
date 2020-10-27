/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:25:49 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/16 02:04:42 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		a;
	char	*ret;

	a = 0;
	if (!f)
		return (NULL);
	if (!s)
		return (NULL);
	while (s[a])
		++a;
	if (!(ret = (char*)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	a = 0;
	while (s[a])
	{
		ret[a] = f(a, s[a]);
		++a;
	}
	ret[a] = '\0';
	return (ret);
}
