/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:05:41 by erlazo            #+#    #+#             */
/*   Updated: 2019/11/21 17:13:15 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>	// REMOVE !!!!!!

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_nlist
{
	size_t			index;
	void			*content;
	struct s_nlist	*next;
}				t_nlist;

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char *set);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void*));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*),
				void (*del)(void*));
int				ft_lstsize(t_list *lst);
void			ft_print_elem(t_list *elem);
void			ft_lstprint(t_list *lst);
t_list			*ft_lstgen(char *s, char c);
int				ft_isspace(char c);
void			ft_strswap(char **s1, char **s2);
void			ft_lstrev(t_list **lst);
int				ft_findchar(char *str, char c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
void			*ft_calloc(size_t count, size_t size);
void			ft_lstdel_cnt(void *content);
void			ft_putnbrnl(int nb);
int				ft_lstnl(t_list **list, const void *content);
void			ft_lstdel_cnt(void *content);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstcut_next(t_list **lst);
t_list			*ft_lstset(void *content, size_t len);
int				gnl(char **l, char **s, int b_size, int fd);
int				ft_len_atoi(char *str, int *len);
char			*ft_fill_with(char this, size_t len);
int				ft_scott_free(char **str);
char			*ft_free_strjoin(char **s1, char **s2);
char			*ft_pos_itoa(unsigned long long n);
t_nlist			*ft_nlstnew(void* content, size_t index);
int				ft_nlstadd_back(t_nlist **lst, t_nlist *new);
int				ft_nlstadd_front(t_nlist **lst, t_nlist *new);
int				ft_nlstdel_all(t_nlist **lst);
int				ft_nlstdel_n_one(t_nlist **lst, size_t n);
char			*ft_read_nlst_n(t_nlist *lst, size_t i);

int				ft_free_strtab(char **tab);
int				ft_print_strtab(char **tab);


#endif
