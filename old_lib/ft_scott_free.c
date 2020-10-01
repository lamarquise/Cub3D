

#include "libft.h"

int		ft_scott_free(char **str)
{
	ft_bzero(*str, ft_strlen(*str));
	free(*str);
	*str = NULL;
	return (-1);
}
