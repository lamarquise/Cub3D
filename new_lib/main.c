

#include "libft.h"
#include <stdio.h>
#include <string.h>

void    *ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dst, const void *src, size_t n);
void    *ft_memccpy(void *dst, const void *src, int c, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t len);
void    *ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char    *ft_strdup(const char *s1);
char    *ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char    *ft_strcat(char *s1, const char *s2);
char    *ft_strncat(char *s1, const char *s2, size_t n);
size_t  ft_strlcat(char *dst, const char *src, size_t size);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
char    *ft_strstr(const char *haystack, const char *needle);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
int     ft_strcmp(const char *s1, const char *s2);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_atoi(const char *str);
int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
int     ft_toupper(int c);
int     ft_tolower(int c);
void	*ft_memalloc(size_t size);
void    ft_memdel(void **ap);
char    *ft_strnew(size_t size);
void	ft_strdel(char **as);
void    ft_strclr(char *s);
void    ft_striter(char *s, void (*f)(char *));
void    ft_striteri(char *s, void (*f)(unsigned int, char *));
char    *ft_strmap(char const *s, char (*f)(char));
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
int     ft_strequ(char const *s1, char const *s2);
int     ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s);
char    **ft_strsplit(char const *s, char c);
char    *ft_itoa(int n);
void    ft_putchar(char c);
void    ft_putstr(char const *s);
void    ft_putendl(char const *s);
void    ft_putnbr(int n);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char const *s, int fd);
void    ft_putendl_fd(char const *s, int fd);
void    ft_putnbr_fd(int n, int fd);
t_list  *ft_lstnew(void const *content, size_t content_size);
void    ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void    ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void    ft_lstadd(t_list **alst, t_list *new);
void    ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list  *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));


// My Bonus

void    	ft_print_elem(t_list *elem);
void    	ft_lstprint(t_list *lst);
t_list      *ft_lstgen(char *s, char c);
int     	ft_isspace(char c);
void		ft_strswap(char **s1, char **s2);
void		ft_lstrev(t_list **lst);

char    ft_upper(char c);

t_list	*list_upper(t_list *elem)
{
	t_list	*new;

	new = NULL;
	ft_memcpy(new, elem, sizeof(elem));
	return (new);
}

void	print_node(t_list *node)
{
	printf("%s\n", (char*)node->content);
}

void	print_content(void *content)
{
	printf("%s\n", content);
}

char	ft_upper(char c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}



int		main(int ac, char **av)
{
//	unsigned char	*tmp1;
//	unsigned char	*tmp2;
	
	void			*space;
	int				a;
//	int				b;
	char			*tmp;
	char			**ret;
	char			c;
	int				i;

	char			**tab;
	t_list			*list;
	t_list			*list2;

	if (atoi(av[1]) == 0 && ac == 6)				// ft_memset
	{
		printf("Memset: %s\n", memset(av[2], atoi(av[4]), atoi(av[5])));
		printf("OG: %s\n", av[3]);											// av[2] and av[3] must be identical for test to work
		printf("New: %s\n", ft_memset(av[3], atoi(av[4]), atoi(av[5])));
	}
	else if (atoi(av[1]) == -1 && ac == 7)			// ft_memccpy
	{
		printf("Memccpy: %s\n", memccpy(av[2], av[4], av[5][0], atoi(av[6])));
		printf("OG: %s\n", av[3]);
		printf("New: %s\n", ft_memccpy(av[3], av[4], av[5][0], atoi(av[6])));
	}
	else if (atoi(av[1]) == 1 && ac == 5)			// ft_bzero
	{
		bzero(av[2], atoi(av[4]));
		printf("Bzero: %s\n", av[2]);
		printf("OG: %s\n", av[3]);
		ft_bzero(av[3], atoi(av[4]));
		printf("New: %s\n", av[3]);
	}
	else if (atoi(av[1]) == 2 && ac == 6)			// ft_memcpy
	{
		printf("Memcpy: %s\n", memcpy(av[2], av[4], atoi(av[5])));
		printf("OG: %s\n", av[3]);
		printf("New: %s\n", ft_memcpy(av[3], av[4], atoi(av[5])));
	}
	else if (atoi(av[1]) == 3 && ac == 6)			// ft_memmove
	{
		printf("Memcpy: %s\n", memmove(av[2], av[4], atoi(av[5])));
		printf("OG: %s\n", av[3]);
		printf("New: %s\n", ft_memmove(av[3], av[4], atoi(av[5])));
	}
	else if (atoi(av[1]) == 4 && ac == 6)			// ft_memchr
	{
		printf("Memchr: %s\n", memchr(av[2], atoi(av[4]), atoi(av[5])));
		printf("OG: %s\n", av[3]);
		printf("New: %s\n", ft_memchr(av[3], atoi(av[4]), atoi(av[5])));
	}
	else if (atoi(av[1]) == 5 && ac == 5)			// ft_memcmp
	{
		printf("Memcmp: %i\n", memcmp(av[2], av[3], atoi(av[4])));
		printf("Mine: %i\n", ft_memcmp(av[2], av[3], atoi(av[4])));
	}
	else if (atoi(av[1]) == 6 && ac == 3)			// ft_strlen
	{
		printf("Len: %zu\n", ft_strlen(av[2]));
	}
	else if (atoi(av[1]) == 7 && ac == 3)			// ft_strdup
	{
		printf("OG: %s\n", av[2]);
		printf("New: %s\n", ft_strdup(av[2]));
	}
	else if (atoi(av[1]) == 8 && ac == 3)			// ft_strcpy
	{
		printf("OG: %s\n", av[2]);
		tmp = malloc(sizeof(char) * (ft_strlen(av[2]) + 1));
		printf("New: %s\n", ft_strcpy(tmp, av[2]));
	}
	else if (atoi(av[1]) == 9 && ac == 4)			// ft_strncpy
	{
		printf("OG: %s\n", av[2]);
		tmp = malloc(sizeof(char) * (atoi(av[3]) + 1));
		printf("New: %s\n", ft_strncpy(tmp, av[2], atoi(av[3])));
	}
	else if (atoi(av[1]) == 10 && ac == 4)			// ft_strcat
	{
		tmp = malloc(sizeof(char) * (ft_strlen(av[2]) + ft_strlen(av[3]) + 1));
		tmp = av[2];
		printf("Result: %s\n", ft_strcat(tmp, av[3]));
	}
	else if (atoi(av[1]) == 11 && ac == 5)			// ft_strncat
	{
		tmp = malloc(sizeof(char) * (ft_strlen(av[2]) + atoi(av[4]) + 1));
		tmp = av[2];
//		printf("strncat: %s\n", strncat(
		printf("Result: %s\n", ft_strncat(tmp, av[3], atoi(av[4])));
	}
	else if (atoi(av[1]) == 12 && ac == 5)			//ft_strlcat
	{
		tmp = malloc(sizeof(char) * (ft_strlen(av[2]) + atoi(av[4]) + 1));
		tmp = av[2];
		printf("Result: %zu\n", ft_strlcat(tmp, av[3], atoi(av[4])));
	}
	else if (atoi(av[1]) == 13 && ac == 4)			// ft_strchr
	{
		printf("Result: %s\n", ft_strchr(av[2], atoi(av[3])));
	}
	else if (atoi(av[1]) == 14 && ac == 4)			//ft_strrchr
	{
		printf("Result: %s\n", ft_strrchr(av[2], atoi(av[3])));
	}
	else if (atoi(av[1]) == 15 && ac == 4)			// ft_strstr
	{
		printf("Result: %s\n", ft_strstr(av[2], av[3]));
	}
	else if (atoi(av[1]) == 16 && ac == 5)			// ft_strnstr
	{
		printf("Result: %s\n", ft_strnstr(av[2], av[3], atoi(av[4])));
	}
	else if (atoi(av[1]) == 17 && ac == 4)			// ft_strcmp
	{
		printf("Result: %i\n", ft_strcmp(av[2], av[3]));
	}
	else if (atoi(av[1]) == 18 && ac == 5)			// ft_strncmp
	{
		printf("Result: %i\n", ft_strncmp(av[2], av[3], atoi(av[4])));
	}
	else if (atoi(av[1]) == 19 && ac == 3)			// ft_atoi
	{
		printf("Result: %i\n", ft_atoi(av[2]));
	}
	else if (atoi(av[1]) == 20 && ac == 3)			// ft_isalpha
	{
		c = av[2][0];
		printf("Result: %i\n", ft_isalpha((unsigned char)c));
	}
	else if (atoi(av[1]) == 21 && ac == 3)			// ft_isdigit
	{
		c = av[2][0];
		printf("Result: %i\n", ft_isdigit((unsigned char)c));
	}
	else if (atoi(av[1]) == 22 && ac == 3)			// ft_isalnum
	{
		c = av[2][0];
		printf("Result: %i\n", ft_isalnum((unsigned char)c));
	}
	else if (atoi(av[1]) == 23 && ac == 3)			// ft_isascii
	{
		c = av[2][0];
		printf("Result: %i\n", ft_isascii((unsigned char)c));
	}
	else if (atoi(av[1]) == 24 && ac == 3)          // ft_isprint
	{
		c = av[2][0];
		printf("Result: %i\n", ft_isprint((unsigned char)c));
	}
	else if (atoi(av[1]) == 25 && ac == 3)			// ft_toupper
	{
		c = av[2][0];
		printf("Result: %c\n", (char)ft_toupper((unsigned char)c));
	}
	else if (atoi(av[1]) == 26 && ac == 3)          // ft_tolower
	{
		c = av[2][0];
		printf("Result: %c\n", (char)ft_tolower((unsigned char)c));
	}

	// PART 2
	
	else if (atoi(av[1]) == 27 && ac == 3)          // ft_memalloc
	{
		a = 0;
		space = ft_memalloc(atoi(av[2]));
		printf("%s\n", (char*)space);
	}
	else if (atoi(av[1]) == 28 && ac == 3)          // ft_memdel
	{
		space = (char*)malloc(sizeof(char) * 5);
		space = "hi th\0";
		printf("OG: %s\n", space);
//		ft_memdel(&space);												// testing needs some work...
//		printf("Result: %s\n", space);
	}
	else if (atoi(av[1]) == 29 && ac == 3)          // ft_strnew
	{
		printf("Result: %s\n", ft_strnew(ft_atoi(av[2])));
	}
	else if (atoi(av[1]) == 30 && ac == 3)          // ft_strdel
	{
		tmp = av[2];
		printf("OG: %s\n", tmp);
		ft_strdel(&tmp);
		printf("Result: %s\n", tmp);
	}
	else if (atoi(av[1]) == 31 && ac == 3)          // ft_strclr
	{
		tmp = av[2];
		printf("OG: %s\n", tmp);
		ft_strclr(tmp);
		printf("Result: %s\n", tmp);
	}
	else if (atoi(av[1]) == 32 && ac == 3)          // ft_striter
	{
		tmp = av[2];
		ft_striter(tmp, (void*)&ft_putstr);									//needs some work.
		printf("Result: %s\n", tmp);
	}
	else if (atoi(av[1]) == 33 && ac == 3)          // ft_striteri
	{
//		ft_striteri(av[2], (void*)&			//couldn't think of a function to use...
	}
	else if (atoi(av[1]) == 333 && ac == 3)			// ft_striteri
	{
		
	}
	else if (atoi(av[1]) == 34 && ac == 3)          // ft_strmap
	{
		printf("Result: %s\n", ft_strmap(av[2], &ft_upper));
	}
	else if (atoi(av[1]) == 35 && ac == 3)          // ft_strmapi
	{
		// once again same problem...
	}
	else if (atoi(av[1]) == 36 && ac == 4)          // ft_strequ
	{
		printf("Result: %i\n", ft_strequ(av[2], av[3]));
	}
	else if (atoi(av[1]) == 37 && ac == 5)          // ft_strnequ
	{
		printf("Result: %i\n", ft_strnequ(av[2], av[3], ft_atoi(av[4])));
	}
	else if (atoi(av[1]) == 38 && ac == 5)          // ft_strsub
	{
		printf("Result: %s\n", ft_strsub(av[2], atoi(av[3]), atoi(av[4])));
	}
	else if (atoi(av[1]) == 39 && ac == 4)          // ft_strjoin
	{
		printf("Result: %s\n", ft_strjoin(av[2], av[3]));
	}
	else if (atoi(av[1]) == 40 && ac == 4)          // ft_strtrim
	{
		printf("Result: %s\n", ft_strtrim(av[2], av[3]));
	}
	else if (atoi(av[1]) == 41 && ac == 4)          // ft_strsplit
	{
		a = 0;
		ret = ft_strsplit(av[2], av[3][0]);
		while (ret[a])
		{
			printf("%s\n", ret[a]);
			++a;
		}
	}
	else if (atoi(av[1]) == 42 && ac == 3)          // ft_itoa
	{
		printf("Result: %s\n", ft_itoa(atoi(av[2])));
	}
	else if (atoi(av[1]) == 43 && ac == 3)          // ft_putchar
	{
		ft_putchar(av[2][0]);
	}
	else if (atoi(av[1]) == 44 && ac == 3)          // ft_putstr
		ft_putstr(av[2]);
	else if (atoi(av[1]) == 45 && ac == 3)          // ft_putendl
	{
		ft_putendl(av[2]);
	}
	else if (atoi(av[1]) == 46 && ac == 3)          // ft_putnbr
	{
		ft_putnbr(atoi(av[2]));
	}
	else if (atoi(av[1]) == 47 && ac == 3)          // ft_putchar_fd
	{
		ft_putchar_fd(av[2][0], 1);
	}
	else if (atoi(av[1]) == 48 && ac == 3)          // ft_putstr_fd
	{
		ft_putstr_fd(av[2], 1);
	}
	else if (atoi(av[1]) == 49 && ac == 3)          // ft_putendl_fd
	{
		ft_putendl_fd(av[2], 1);
	}
	else if (atoi(av[1]) == 50 && ac == 3)          // ft_putnbr_fd
	{
		ft_putnbr_fd(atoi(av[2]), 1);
	}


		// BONUS PART

	else if (atoi(av[1]) == 51 && ac == 3)			//ft_lstnew
	{
/*		i = 0;
		list = NULL;
		tab = ft_strsplit(av[2], 32);
		while (tab[i])
*/		
		list = ft_lstnew(av[2], ft_strlen(av[2]));
		print_node(list);
	}
	else if (atoi(av[1]) == 52 && ac == 3)          //ft_lstdelone
	{
		i = 0;
		list = NULL;
		list2 = NULL;
		tab = ft_strsplit(av[2], av[3][0]);
		while (tab[i])																//not sure how to test this one
		{
			ft_lstadd(&list, ft_lstnew(tab[i], ft_strlen(tab[i])));
			++i;
		}

		list2 = list;
		while (list2)
		{
			print_node(list2);
			list2 = list2->next;
		}
	}
	else if (atoi(av[1]) == 53 && ac == 3)          //ft_lstdel
	{
																					//or this one...
	}
	else if (atoi(av[1]) == 54 && ac == 4)          //ft_lstadd
	{
		i = 0;
		list = NULL;
		list2 = NULL;
		tab = ft_strsplit(av[2], av[3][0]);
		while (tab[i])
		{
			ft_lstadd(&list, ft_lstnew(tab[i], ft_strlen(tab[i])));
			++i;
		}
		list2 = list;
		i = 0;
		while (list2)
		{
			print_node(list2);
			list2 = list2->next;
		}									//ok so lessons learned: in lstadd, do not have a condition if there is no "new" elem, fucks everything up
	}
	else if (atoi(av[1]) == 55 && ac == 4)          //ft_lstiter
	{
		i = 0;
		list = NULL;
		tab = ft_strsplit(av[2], av[3][0]);
		while (tab[i])
		{
			ft_lstadd(&list, ft_lstnew(tab[i], ft_strlen(tab[i])));
			++i;
		}
		list2 = list;
		ft_lstiter(list2, &print_node);
	}
	else if (atoi(av[1]) == 56 && ac == 4)          //ft_lstmap
	{
		i = 0;
		list = NULL;
		tab = ft_strsplit(av[2], av[3][0]);
		while (tab[i])													// doesn't quite work
		{
			ft_lstadd(&list, ft_lstnew(tab[i], ft_strlen(tab[i])));
			++i;
		}
		list2 = ft_lstmap(list, &list_upper);
		ft_lstiter(list2, &print_node);
	}

	
	// My Bonuses
	

	else if (atoi(av[1]) == 57 && ac == 4)          //ft_lstgen and the others
	{
		ft_lstprint(ft_lstgen(av[2], av[3][0]));
	}
	else if (atoi(av[1]) == 58 && ac == 4)          // last list one
	{
		list = NULL;
		list = ft_lstgen(av[2], av[3][0]);
		ft_lstrev(&list);
		ft_lstprint(list);
	}
	return (0);
}









