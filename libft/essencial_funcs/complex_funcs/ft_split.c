/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:20:01 by erlazo            #+#    #+#             */
/*   Updated: 2020/09/14 13:38:22 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_set(char *set)
{
	int	i;
	int	j;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		j = i + 1;
		while (set[j])
		{
			if (set[i] == set[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

static int		ws(char *s, char *set)
{
	int		a;
	int		words;

	a = 0;
	words = 0;
	if (!s)
		return (1);
	while (s[a])
	{
		if ((ft_findchar(set, s[a])) < 0 \
			&& ((ft_findchar(set, s[a + 1])) >= 0 \
			|| s[a + 1] == '\0'))
			++words;
		++a;
	}
	return (words + 1);
}

static int		wl(char *s, int start, char *set)
{
	int		a;

	a = 0;
	if (!s)
		return (1);
	while (s[start + a] && (ft_findchar(set, s[start + a])) == -1)
		++a;
	return (a + 1);
}

char			**ft_split(char const *s, char *set)
{
	int		a;
	int		b;
	int		d;
	char	**ret;

	if (!s || !ft_check_set(set))
		return (NULL);
	a = 0;
	b = 0;
	if (!(ret = (char**)malloc(sizeof(char*) * ws((char*)s, set))))
		return (NULL);
	while ((char)s[a])
	{
		if ((char)s[a] && (ft_findchar(set, (char)s[a])) >= 0)
			++a;
		else
		{
			d = 0;
			if (!(ret[b] = ft_memalloc(sizeof(char) * wl((char*)s, a, set))))
				return (NULL);
			while ((char)s[a] && (ft_findchar(set, (char)s[a])) == -1)
				ret[b][d++] = s[a++];
			ret[b++][d] = '\0';
		}
	}
	ret[b] = 0;
	return (ret);
}
