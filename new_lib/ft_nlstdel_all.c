

#include "libft.h"

int		ft_nlstdel_all(t_nlist **lst)
{
	t_nlist	*tmp;

	if (!lst)
		return (0);
	if (!*lst)
		return (1);
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	lst = NULL;		// necessary ???
	return (1);
}
