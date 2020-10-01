

#include "libft.h"

char	*ft_free_strjoin(char **s1, char **s2)
{
	int		a;
	int		b;
	int		c;
	char	*ret;

	if (!*s1 && !*s2)
		return (NULL);
	a = ft_strlen(*s1) + ft_strlen(*s2) + 1;
	if (!(ret = ft_memalloc(sizeof(char) * a)))
		return (NULL);
	a = 0;
	b = 0;
	c = 0;
	while (*s1 && (*s1)[b])
		(ret)[a++] = (*s1)[b++];
	while (*s2 && (*s2)[c])
		(ret)[a++] = (*s2)[c++];
	if (s1 && *s1 )
		ft_scott_free(s1);
	if (s2 && *s2 )
		ft_scott_free(s2);
	return (ret);
}
