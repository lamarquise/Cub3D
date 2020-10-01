

#include "libft.h"

	// make a print del at some point...

int		ft_print_nlst(t_nlist *lst)
{
	t_nlist	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp)
	{
		ft_putnbr(tmp->index);
		write(1, ": ", 2);
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}
	return (1);
}

