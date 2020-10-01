

#include "libft.h"

char	*ft_fill_with(char this, size_t len)
{
	char    *ret;
	size_t  i;

	if (!this || len < 1)
		return (NULL);
	if (!(ret = ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		ret[i++] = this;
	ret[i] = '\0';
	return (ret);
}
