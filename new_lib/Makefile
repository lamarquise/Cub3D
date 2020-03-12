# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlazo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 13:59:02 by erlazo            #+#    #+#              #
#    Updated: 2019/11/21 17:15:00 by erlazo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

SRCS	=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strmapi.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \

SRCS_BONUS	=	ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstadd_front.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstadd_back.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstclear.c \
				ft_lstcut_next.c \
				ft_lstdel_cnt.c \
				ft_lstnl.c \
				ft_lstset.c \
				ft_lstprint.c \
				ft_lstrev.c \
				ft_lstgen.c \
				ft_print_elem.c \
				ft_strswap.c \
				ft_findchar.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strstr.c \
				ft_strcmp.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putnbrnl.c \
				ft_isspace.c \
				gnl.c \
				ft_scott_free.c \
				ft_pos_itoa.c \
				ft_free_strjoin.c \
				ft_fill_with.c \
				ft_len_atoi.c \
				ft_nlstnew.c \
				ft_nlstadd_back.c \
				ft_nlstdel_all.c \
				ft_nlstadd_front.c \
				ft_nlstdel_n_one.c \
				ft_read_nlst_n.c \
				ft_free_strtab.c \
				ft_print_strtab.c \


ODIR = obj/
OBJ_NAME = $(SRCS:.c=.o)
OBJ_NAME_BONUS = $(SRCS_BONUS:.c=.o)
OBJS = $(addprefix $(ODIR),$(OBJ_NAME))
OBJS_BONUS = $(addprefix $(ODIR),$(OBJ_NAME_BONUS))

#OBJS		=	$(SRCS:.c=.o)

#OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

#INCL		=	libft.h

all:		$(NAME)

$(ODIR)%.o: %.c
	mkdir -p $(ODIR)
	$(CC) -o $@ -c $< $(CFLAGS)
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

#%.o:		%.c
#	mkdir -p $(ODIR)
#	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME):	$(OBJS)
	ar rc $(NAME) $^
	ranlib $(NAME)
	echo "$(_GREEN)\r\33[2K\r$(NAME) created  😎$(_END)"

clean:
	rm -rf $(ODIR)
	echo "$(_RED).o Files Deleted  😱$(_END)"

fclean:		clean
	rm -rf $(NAME)
	rm -f bonus
	echo "$(_RED)Library Deleted  😱$(_END)"

re:			fclean all

bonus:		$(OBJS) $(OBJS_BONUS)
	ar rc $(NAME) $^
	ranlib $(NAME)
	touch bonus
	echo "$(_GREEN)\r\33[2K\rBonus $(NAME) created  😎$(_END)"
	

.PHONY: all clean fclean re

.SILENT:

##################
##    COLORS    ##
##################

_GREY=$ \033[30m
_RED=$ \033[31m
_GREEN=$ \033[32m
_YELLOW=$ \033[33m
_BLUE=$ \033[34m
_PURPLE=$ \033[35m
_CYAN=$ \033[36m
_WHITE=$ \033[37m
_END=$ \033[0m
