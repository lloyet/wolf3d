# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/09/20 01:31:31 by lloyet       #+#   ##    ##    #+#        #
#    Updated: 2019/02/17 23:29:04 by lloyet      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = WOLF

# COMPILER#

CC	= clang
CFLAGS = -Wall -Wextra -Werror -O3

# DIR

SRCDIR = ./src/
INCDIR = ./inc/
OBJDIR = ./obj/
LIBDIR = ./lib/

SRC =	main.c \
		misc.c \
		engine.c \
		framework.c \
		device.c \
		event.c \
		hook_key.c \
		hook_mouse.c \
		image.c \
		texture.c \
		wall.c \
		vector.c \
		angle.c \
		world.c \
		camera.c \
		entity.c \
		ray.c \
		ray_utils.c \
		parser.c \

OBJ	= $(addprefix $(OBJDIR), $(SRC:.c=.o))

# FT_LIBRARY#

FT = $(addprefix $(LIBDIR), libft)
LIBFT = $(addprefix $(FT), libft.a)
LIBINC = -I $(FT)
LIBLINK	= -L $(FT) -lft

# MINILIBX LIBRARY

ifeq ($(shell uname), Linux)
	MLX = $(addprefix $(LIBDIR), minilibx_linux)
	LIBMLX = $(addprefix $(MLX), libmlx.a)
	MLXINC = -I $(MLX)
	MLXLINK = -L $(MLX) -lmlx -lXext -lX11
endif
ifeq ($(shell uname), Darwin)
	MLX = $(addprefix $(LIBDIR), minilibx_macos)
	LIBMLX = $(addprefix $(MLX), libmlx.a)
	MLXINC = -I $(MLX)
	MLXLINK = -L $(MLX) -lmlx -framework OpenGL -framework AppKit
endif

.PHONY: all clean fclean re
all: $(OBJDIR) $(LIBFT) $(LIBMLX) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLXLINK) $(LIBLINK) -lm -lpthread -o $(NAME)
	@echo "[$(NAME)]: all done."

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(LIBINC) $(MLXINC) -I $(INCDIR) -c $< -o $@

$(OBJDIR):
	@mkdir -p $@

$(LIBFT):
	make -C $(FT)

$(LIBMLX):
	make -C $(MLX)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT)  clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
