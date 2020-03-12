

#include "libft.h"

char	*ft_pos_itoa(unsigned long long n)
{
	unsigned long long	nb;
	char				*ret;
	int					len;

	nb = n;
	len = 1;
	while (nb >= 10)
	{
		nb /= 10;
		++len;
	}
	if (!(ret = ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len--] = '\0';
	nb = n;
	while (len >= 0)
	{
		ret[len] = nb % 10 + 48;
		nb /= 10;
		--len;
	}
	return (ret);
}
