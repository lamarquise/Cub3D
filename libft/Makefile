# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlazo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 13:59:02 by erlazo            #+#    #+#              #
#    Updated: 2020/10/28 20:53:59 by ericlazo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#maybe not do linked list folder with t list in it ? for now ?
# For now only Full libft, eventually have so can do only essencial

NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

#Essencial Functions
DIR_ESS	=	./essencial_funcs/

DIR_COMP	=	complex_funcs/
COMP	=	ft_strjoin.c \
			ft_fstrjoin.c \
			ft_split.c \
			gnl.c \

DIR_MEDI	=	medium_funcs/
MEDI	=	ft_atoi.c \
			ft_latoi.c \
			ft_itoa.c \
			ft_pos_itoa.c \
			ft_fill_with.c \
			ft_substr.c \
			ft_strdup.c \
			ft_fstrdup.c \
			ft_nstrdup.c \
			ft_memalloc.c \
			ft_free_strtab.c \
			ft_print_strtab.c \

DIR_SIMP	=	simple_funcs/
SIMP	=	ft_strlen.c \
			ft_fstrlen.c \
			ft_nstrlen.c \
			ft_bzero.c \
			ft_scott_free.c \
			ft_findchar.c \
			ft_strcmp.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_error_msg.c \

DIR_LLST	=	linked_list_funcs/
#in linked list funcs
DIR_TLST	=	lst_funcs/
TLST	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_print_elem.c \
			ft_lstprint.c \
			ft_lstgen.c \
			ft_lstrev.c \

#Other Functions
DIR_OTH	=	./other_funcs/

DIR_MEMF	=	mem_funcs/
MEMF	=	ft_calloc.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memdel.c \

DIR_STRF	=	str_funcs/
STRF	=	ft_strstr.c \
			ft_strnstr.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strlcpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strswap.c \
			ft_strclr.c \
			ft_strdel.c \
			ft_cstrjoin.c \
			ft_strtrim.c \

DIR_ISCH	=	is_funcs/
ISCH	=	ft_isalpha.c \
			ft_isdigit.c \
			ft_str_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isspace.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \

DIR_PUTF	=	put_funcs/
PUTF	=	ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putchar.c \
			ft_putendl.c \
			ft_putnbrnl.c \

DIR_NLST	=	nlist_funcs/
NLST	=	ft_nlstnew.c \
			ft_nlstadd_back.c \
			ft_nlstdel_all.c \
			ft_nlstadd_front.c \
			ft_nlstdel_n_one.c \
			ft_read_nlst_n.c \


# we don't need to put the $()s ?
ESS		=	COMP \
			MEDI \
			SIMP \
			TLST \

LLST	=	NLST \

OTH		=	MEMF \
			STRF \
			PUTF \
			ISCH \


COMP_SRC	=	$(addprefix $(DIR_COMP),$(COMP))
MEDI_SRC	=	$(addprefix $(DIR_MEDI),$(MEDI))
SIMP_SRC	=	$(addprefix $(DIR_SIMP),$(SIMP))
TLST_SRC	=	$(addprefix $(DIR_TLST),$(TLST))

LLST_SRC	=	$(addprefix $(DIR_LLST),$(TLST_SRC))

ESS_SRC		=	$(addprefix $(DIR_ESS),$(COMP_SRC)) \
				$(addprefix $(DIR_ESS),$(MEDI_SRC)) \
				$(addprefix $(DIR_ESS),$(SIMP_SRC)) \
				$(addprefix $(DIR_ESS),$(LLST_SRC)) \

MEMF_SRC	=	$(addprefix $(DIR_MEMF),$(MEMF))
STRF_SRC	=	$(addprefix $(DIR_STRF),$(STRF))
PUTF_SRC	=	$(addprefix $(DIR_PUTF),$(PUTF))
ISCH_SRC	=	$(addprefix $(DIR_ISCH),$(ISCH))

NLST_SRC	=	$(addprefix $(DIR_NLST),$(NLST))

OTH_SRC		=	$(addprefix $(DIR_OTH),$(MEMF_SRC)) \
				$(addprefix $(DIR_OTH),$(STRF_SRC)) \
				$(addprefix $(DIR_OTH),$(PUTF_SRC)) \
				$(addprefix $(DIR_OTH),$(ISCH_SRC)) \
				$(addprefix $(DIR_OTH),$(NLST_SRC)) \


DIR_OBJ		=	./obj/
ESS_OBJ		=	$(COMP:.c=.o) \
				$(MEDI:.c=.o) \
				$(SIMP:.c=.o) \
				$(TLST:.c=.o) \
				

OTH_OBJ		=	$(MEMF:.c=.o) \
				$(STRF:.c=.o) \
				$(PUTF:.c=.o) \
				$(ISCH:.c=.o) \
				$(NLST:.c=.o) \

ESS_OBJS	=	$(addprefix $(DIR_OBJ),$(ESS_OBJ))
OTH_OBJS	=	$(addprefix $(DIR_OBJ),$(OTH_OBJ))


INC		=	$(NAME:.a=.h)
DIR_INC	=	./
INCS	=	$(addprefix $(DIR_INC),$(INC))

FULL	=	hi

all: $(NAME)

#$(NAME): $(ESS_OBJS) $(INCS)
#	ar rc $(NAME) $(ESS_OBJS)
#	ranlib $(NAME)
#	printf "$(_GREEN)\r\33[2K\rEssencial $(NAME) created  😎\n$(_END)"

$(NAME): $(ESS_OBJS) $(OTH_OBJS) $(INCS)
	ar rc $(NAME) $(ESS_OBJS) $(OTH_OBJS)
	ranlib $(NAME)
	printf "$(_GREEN)\r\33[2K\rFull $(NAME) created  😎\n$(_END)"

$(DIR_OBJ)%.o: ./essencial_funcs/$(DIR_COMP)%.c $(INCS)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC)
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

$(DIR_OBJ)%.o: ./essencial_funcs/$(DIR_MEDI)%.c $(INCS)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC)
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

$(DIR_OBJ)%.o: ./essencial_funcs/$(DIR_SIMP)%.c $(INCS)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC)
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

$(DIR_OBJ)%.o: ./essencial_funcs/linked_list_funcs/$(DIR_TLST)%.c $(INCS)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC)
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

$(DIR_OBJ)%.o: ./other_funcs/$(DIR_MEMF)%.c $(INCS)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC)
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

$(DIR_OBJ)%.o: ./other_funcs/$(DIR_STRF)%.c $(INCS)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC)
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

$(DIR_OBJ)%.o: ./other_funcs/$(DIR_PUTF)%.c $(INCS)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC)
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

$(DIR_OBJ)%.o: ./other_funcs/$(DIR_ISCH)%.c $(INCS)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC)
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

$(DIR_OBJ)%.o: ./other_funcs/$(DIR_NLST)%.c $(INCS)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC)
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

clean:
	rm -rf $(DIR_OBJ)
	echo "$(_RED).o Files Deleted  😱$(_END)"

fclean: clean
	rm -rf $(NAME)
	echo "$(_RED)Library Deleted  😱$(_END)"

re:			fclean all

ess: $(NAME)

# Try using ifs to make so second one with same name doesn't relink...
#$(NAME2): $(ESS_OBJS) $(OTH_OBJS) $(INCS)
#	ar rc $(NAME2) $(ESS_OBJS) $(OTH_OBJS)
#	ranlib $(NAME2)
#	I hate the touch full thing but use it for now...
#	touch full
#	printf "$(_GREEN)\r\33[2K\rFull $(NAME2) created  😎\n$(_END)"
	
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
