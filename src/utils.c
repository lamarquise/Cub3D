/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:31:33 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/31 23:11:00 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_sstrlen(const char *s)
{
	size_t	a;

	a = 0;
	if (s)
	{
		while (s[a])
			++a;
	}
	return (a);
}

int		ft_sfindchar(char *str, char c)
{
	int		i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	unsigned int	a;
	char			*ret;

	a = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (a < len)
	{
		ret[a] = s[start + a];
		++a;
	}
	ret[a] = '\0';
	return (ret);
}

int		ft_ibzero(void *s, size_t n)
{
	unsigned int	a;
	unsigned char	*str;

	a = 0;
	str = s;
	while (a < n)
	{
		str[a] = '\0';
		++a;
	}
	return (1);
}

char	*ft_gstrjoin(char **s1, char *s2)
{
	int		a;
	char	*ret;
	int		c;

	ret = NULL;
	if ((!s1 || !*s1) && !s2)
		return (NULL);
	a = ft_sstrlen(*s1) + ft_sstrlen(s2) + 1;
	if (!(ret = (char*)malloc(sizeof(char) * a)))
		return (NULL);
	ft_ibzero(ret, a);
	a = 0;
	c = 0;
	while (*s1 && (*s1)[c])
	{
		ret[a++] = (*s1)[c];
		++c;
	}
	while (s2 && *s2)
	{
		ret[a++] = *s2;
		++s2;
	}
	ret[a] = '\0';
	return (ret);
}
