

#include "libft.h"

int		ft_str_isdigit(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		++str;
	}
	return (1);
}
