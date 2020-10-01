

#include "libft.h"

char	*ft_read_nlst_n(t_nlist *lst, size_t i)
{
	t_nlist	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp)
	{
		if (i == tmp->index)
			return ((char*)tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}
