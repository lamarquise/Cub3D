# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlazo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 15:37:26 by erlazo            #+#    #+#              #
#    Updated: 2020/10/29 11:19:29 by ericlazo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	Cub3D
CC		=	clang

FILES	=	main.c \
			init_structures.c \
			init_more_structures.c \
			file_parser.c \
			utils.c \
			line_parser.c \
			input_parser.c \
			level_parser.c \
			floor_management.c \
			texture_management.c \
			unpacking.c \
			create_mlx_entities.c \
			save.c \
			game_engine.c \
			generate.c \
			generate_minimap.c \
			minimap.c \
			keyhooks.c \
			display_to_screen.c \
			raycasting.c \
			rayshooting.c \
			floorcasting.c \
			spritecasting.c \
			sprite_order.c \
			sprite_management.c \
			sprite_behavior.c \
			player_rotation.c \
			player_movement.c \
			toggle_buttons.c \
			mouse_commands.c \
			not_bresenham.c \
			bresenham.c \
			draw_bresenham_line.c \
			math.c \
			more_nlist.c \
			free_sprites.c \
			free_lists.c \
			free_mlx.c \
			quit.c \

MFILES	=	prime_engine_mac.c \

LFILES	=	prime_engine_linux.c\

IFILES =	cub3d.h \
			bresenham.h \
			mymlx.h \
			key_linux.h \
			key_macos.h \

DIR_MLX_MAC = ./minilibx_mac/
MLX_MAC = $(DIR_MLX_MAC)libmlx.a
MLX_MAC_INC = $(DIR_MLX_MAC)

DIR_MLX_LINUX = ./minilibx_linux/
MLX_LINUX = $(DIR_MLX_LINUX)libmlx.a
MLX_LINUX_INC = $(DIR_MLX_LINUX)

DIR_LIBFT	=	./libft/
LIBFT_INC	=	$(DIR_LIBFT)
LIBFT_NAME	=	libft.a
LIBFT		=	$(DIR_LIBFT)$(LIBFT_NAME)

DIR_SRC =	src/
DIR_OBJ =	obj/
DIR_OBJ_MAC =	obj/
DIR_OBJ_LINUX =	obj/


DIR_INC	=	./include/
INC		=	$(DIR_INC)
OBJ_NAME = $(FILES:.c=.o)
MAC_OBJ_NAME = $(MFILES:.c=.o)
LINUX_OBJ_NAME = $(LFILES:.c=.o)

SRCS = $(addprefix $(DIR_SRC),$(FILES))
MAC_SRCS	= $(addprefix $(DIR_SRC),$(MFILES))
LINUX_SRCS	= $(addprefix $(DIR_SRC),$(LFILES))
OBJS = $(addprefix $(DIR_OBJ),$(OBJ_NAME))
MAC_OBJS = $(addprefix $(DIR_OBJ),$(MAC_OBJ_NAME))
LINUX_OBJS = $(addprefix $(DIR_OBJ),$(LINUX_OBJ_NAME))
INCS = $(addprefix $(DIR_INC),$(IFILES))

#celia has -02 -g for all of them...
FRAME = -framework OpenGL -framework AppKit
MAC_FLAGS	= -Wall -Wextra -Werror -I$(INC) -I$(LIBFT_INC) -I$(MLX_MAC_INC) $(FRAME)
LINUX_FLAGS	= -Wall -Wextra -Werror -O2 -g -I$(INC) -I$(LIBFT_INC) -I$(MLX_LINUX_INC)
#CFLAGS = -Wall -Wextra -Werror -I$(INC) -I$(LIBFT_INC) -I$(MLX_INC)
SAN = -g3 -fsanitize=address

#	clang -Wall -Wextra -Werror -O2 -g $(OBJS) $(LINUX_OBJS) ./libft/libft.a -lm -lXext -lX11 -lbsd ./minilibx_linux/libmlx.a -o Cub3D

#ltest: $(LIBFT) $(MLX)
#	clang -Wall -Wextra -Werror -O2 -g $(SRCS) $(LINUX_SRCS) ./libft/libft.a -I./include/ -I./minilibx_linux/ -I./libft/ -lm -lXext -lX11 -lbsd ./minilibx_linux/libmlx.a -o Cub3D


all: $(NAME)

$(LIBFT): 
	make -C $(DIR_LIBFT) $(LIB_NAME)

$(MLX):
	make
	echo "$(_CYAN)\r\33[2K\rMaking Mlx 🙄$(_END)"

$(MLX_MAC):
	make
	echo "$(_CYAN)\r\33[2K\rMaking Mlx 🙄$(_END)"

$(MLX_LINUX):
	make
	echo "$(_CYAN)\r\33[2K\rMaking Mlx 🙄$(_END)"

$(NAME): $(OBJS) $(LINUX_OBJS) $(LIBFT) $(MLX_LINUX)
	$(CC) -o $(NAME) $(LINUX_FLAGS) $(OBJS) $(LINUX_OBJS) $(LIBFT) $(MLX_LINUX)
	printf "$(_GREEN)\r\33[2K\r$(NAME) for Linux created  😎\n$(_END)"

mac: $(OBJS) $(MAC_OBJS) $(LIBFT) $(MLX_MAC)
	$(CC) -o $(NAME) $(MAC_FLAGS) $(OBJS) $(MAC_OBJS) $(LIBFT) $(MLX_MAC)
	printf "$(_GREEN)\r\33[2K\r$(NAME) for Mac created  😎\n$(_END)"

linux: $(OBJS) $(LINUX_OBJS) $(LIBFT) $(MLX_LINUX)
	$(CC) -o $(NAME) $(LINUX_FLAGS) $(OBJS) $(LINUX_OBJS) $(LIBFT) $(MLX_LINUX)
	printf "$(_GREEN)\r\33[2K\r$(NAME) for Linux created  😎\n$(_END)"

#$(DIR_OBJ_MAC)%.o: $(DIR_SRC)%.c $(DIR_INC)
#	mkdir -p $(DIR_OBJ)
#	$(CC) -o $@ -c $< $(MAC_FLAGS)
#	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

$(DIR_OBJ_LINUX)%.o: $(DIR_SRC)%.c $(DIR_INC)
	mkdir -p $(DIR_OBJ)
	$(CC) -o $@ -c $< $(LINUX_FLAGS)
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

#omac: 

#olinux:

bonus: $(NAME)

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

tests: $(OBJS) $(MAC_OBJS) $(LIBFT) $(MLX_MAC)
	$(CC) -o $@ $(MAC_FLAGS) $(OBJS) $(MAC_OBJS) $(LIBFT) $(MLX_MAC) $(SAN)
	echo "$(_CYAN)Fsanitize Test ready  😬$(_END)"

tclean: ofclean
	rm -rf testl.dSYM tests.dSYM test tests testl
	echo "$(_RED)Test files deleted  😱$(_END)"

.PHONY: all clean fclean re $(LIBFT)

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
