# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlazo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 15:37:26 by erlazo            #+#    #+#              #
#    Updated: 2020/10/05 16:50:54 by ericlazo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	cub3d
CC		=	gcc

FILES	=	main.c \
			init_structures.c \
			file_parser.c \
			line_parser.c \
			floor_management.c \
			create_mlx_entities.c \
			texture_management.c \
			math.c \
			quit.c \
			game_engine.c \
			generate.c \
			keyhooks.c \
			player_commands.c \
			raycasting.c \
			minimap.c \
			not_bresenham.c \
			bresenham.c \
			draw_bresenham_line.c \
			toggle_buttons.c \
			mouse_commands.c \
			more_nlist.c \

OFILES	=	init_master.c \
			master.c \
			make_minimap_img.c \
			make_hud_img.c \
			draw_toolz.c \
			raycasting.c \

IFILES =	cub3d.h \
			bresenham.h \
			mymlx.h \
# can add mlx.h if doing dynamic lib...			

DIR_MLX = minilibx/
MLX = $(DIR_MLX)libmlx.a
MLX_INC = $(DIR_MLX)

# can easily be chaned to a local folder when submit
#DIR_LIBFT	=	~/Programming/42/libft/
DIR_LIBFT	=	../libft/
LIBFT_INC	=	$(DIR_LIBFT)
LIBFT_NAME	=	libft.a
LIBFT		=	$(DIR_LIBFT)$(LIBFT_NAME)

DIR_SRC =	src/
DIR_OBJ =	obj/
DIR_INC	=	include/
INC		=	$(DIR_INC)
OBJ_NAME = $(FILES:.c=.o)
SRCS = $(addprefix $(DIR_SRC),$(FILES))
OBJS = $(addprefix $(DIR_OBJ),$(OBJ_NAME))
INCS = $(addprefix $(DIR_INC),$(IFILES))


FRAME = -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror -I$(INC) -I$(LIBFT_INC) -I$(MLX_INC)
SAN = -g3 -fsanitize=address


all: $(NAME)

$(LIBFT): $(DIR_LIBFT)libft.h
	make -C $(DIR_LIBFT) $(LIB_NAME)
#	make -C $(DIR_LIBFT)	better ?

$(MLX):
	make
	echo "$(_CYAN)\r\33[2K\rMaking Mlx 🙄$(_END)"

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(FRAME)
	printf "$(_GREEN)\r\33[2K\r$(NAME) created  😎\n$(_END)"

$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(DIR_INC)
	mkdir -p $(DIR_OBJ)
	$(CC) -o $@ -c $< $(CFLAGS)
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

clean:
	make -C $(DIR_LIBFT) $@
	rm -rf $(DIR_OBJ)

oclean:
	rm -rf $(DIR_OBJ)

ofclean: oclean
	rm -f $(NAME)
	echo "$(_RED)$(NAME) Deleted  😱$(_END)"

fclean: oclean
	make -C $(DIR_LIBFT) $@
	rm -f $(NAME)
	echo "$(_RED)$(NAME) Deleted  😱$(_END)"

simple: ofclean all

re: fclean all

test: all
	gcc $(CFLAGS) -L. -lftprintf ./main.c -o test
	echo "$(_CYAN)Test ready  😬$(_END)"

testl: $(OBJS) $(LIBFT) $(MLX)
	$(CC) -o $@ $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(FRAME) -g
	echo "$(_CYAN)Valgrind Test ready  😬$(_END)"

tests: $(OBJS) $(LIBFT) $(MLX)
	$(CC) -o $@ $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(FRAME) $(SAN)
	echo "$(_CYAN)Fsanitize Test ready  😬$(_END)"

tclean: ofclean
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
