/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:12:36 by erlazo            #+#    #+#             */
/*   Updated: 2019/11/15 17:46:11 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlen_trim(char *s1, char *set)
{
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1);
	j = 0;
	i = len - 1;
	while (s1[j] && ft_strchr(set, (int)s1[j]))
	{
		++j;
		--len;
	}
	while (i >= 0 && len > 0 && ft_strchr(set, (int)s1[i]))
	{
		--len;
		--i;
	}
	return (len);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*ret;

	if (!s1 || !set)
		return (NULL);
	len = strlen_trim((char*)s1, (char*)set);
	if (!(ret = (char*)malloc((sizeof(char) * len + 1))))
		return (NULL);
	while (*s1 && ft_strchr((char*)set, (int)*s1))
		++s1;
	i = 0;
	while (i < len)
		ret[i++] = *s1++;
	ret[i] = '\0';
	return (ret);
}
