

#include "libft.h"

int		ft_free_strtab(char **tab)
{
	int		a;

	a = 0;
	if (!tab || !*tab)
		return (0);
	while (tab[a])
	{
		ft_scott_free(&(tab[a]));
		++a;
	}
	return (1);
}
