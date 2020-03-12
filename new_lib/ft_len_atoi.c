

#include "libft.h"

int		ft_len_atoi(char *str, int *len)
{
	int		a;
	int		neg;
	long	ret;

	a = 0;
	ret = 0;
	neg = 1;
	if (!*len)
		*len = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		++a;
	if (str[a] == 43 || str[a] == 45)
	{
		if (str[a] == 45)
			neg = -1;
		++a;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		ret = ret * 10 + (str[a] - 48);
		++a;
		++*len;
	}
	return (ret * neg);
}
