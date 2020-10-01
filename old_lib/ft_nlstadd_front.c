

#include "libft.h"

int		ft_nlstadd_front(t_nlist **lst, t_nlist *new)
{
	if (!lst || !new)
		return (0);
	new->next = *lst;
	*lst = new;
	new->index = 0;
	while (*lst)
	{
		++(*lst)->index;
		(*lst) = (*lst)->next;
	}
	return (1);
}
