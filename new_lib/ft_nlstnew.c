

#include "libft.h"

t_nlist		*ft_nlstnew(void *content, size_t index)
{
	t_nlist	*elem;

	if (!(elem = (t_nlist*)malloc(sizeof(t_nlist))))
		return (NULL);
	if (!content)
		elem->content = NULL;
	elem->content = content;
	elem->index = index;
	elem->next = NULL;
	return (elem);
}
