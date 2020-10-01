

#include "libft.h"

int		ft_print_strtab(char **tab)
{
	int		a;
//	char	**tmp;

	if (!tab)
		return (0);
//	tmpi
	a = 0;
	while (tab[a])
	{
		write(1, tab[a], ft_strlen(tab[a]));
		write(1, "\n", 1);
		++a;
	}
	return (1);
}
