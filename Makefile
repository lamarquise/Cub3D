# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlazo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 15:37:26 by erlazo            #+#    #+#              #
#    Updated: 2020/03/03 21:06:25 by erlazo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d


CC = gcc

FILES =		main.c \
			parse_file.c \
			parse_line.c \
			master.c \
			master_init.c \
			create_mlx_entities.c \
			make_map.c \
			make_hud.c \
			keyhooks.c \
			math.c \
			quit.c \

IFILES =	cub3d.h \
# can add mlx.h if doing dynamic lib...			


MLXDIR = minilibx/
MLX = $(MLXDIR)libmlx.a
MLXINC = $(MLXDIR)

IDIR = include/
SDIR = src/
LIBFTDIR = new_lib/
LIBFT = $(LIBFTDIR)libft.a
LIBFTINC = $(LIBFTDIR)
FRAME = -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror -I$(IDIR) -I$(LIBFTINC) -I$(MLXINC)


SRCS = $(addprefix $(SDIR), $(FILES))
INCS = $(addprefix $(IDIR), $(IFILES))

ODIR = obj/
OBJ_NAME = $(FILES:.c=.o)
OBJS = $(addprefix $(ODIR),$(OBJ_NAME))


all: $(NAME)

$(LIBFT):
	make bonus -C $(LIBFTDIR) libft.a

$(MLX):
	make
	echo "$(_CYAN)\r\33[2K\rMaking Mlx 🙄$(_END)"

# we removed $(LIBFT) which i think makes it not dependant...
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(FRAME)
	printf "$(_GREEN)\r\33[2K\r$(NAME) created  😎\n$(_END)"

$(ODIR)%.o: $(SDIR)%.c $(IDIR)
	mkdir -p $(ODIR)
	$(CC) -o $@ -c $< $(CFLAGS)
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

clean:
	make -C $(LIBFTDIR) $@
	rm -rf $(ODIR)

oclean:
	rm -rf $(ODIR)

fclean: oclean
	make -C $(LIBFTDIR) $@
	rm -f $(NAME)
	echo "$(_RED)$(NAME) Deleted  😱$(_END)"

re: fclean all

test: all
	gcc $(CFLAGS) -L. -lftprintf ./main.c -o test
	echo "$(_CYAN)Test ready  😬$(_END)"

testl: all
	gcc $(CFLAGS) -L. -lftprintf ./main.c -o testl -g
	echo "$(_CYAN)Valgrind Test ready  😬$(_END)"

tests: all
	gcc $(CFLAGS) -L. -lftprintf ./main.c -o tests -g3 -fsanitize=address
	echo "$(_CYAN)Fsanitize Test ready  😬$(_END)"

tclean: fclean
	rm -rf testl.dSYM tests.dSYM test tests testl
	echo "$(_RED)Test files deleted  😱$(_END)"

.PHONY: all clean fclean re

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

.SILENT:
