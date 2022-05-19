# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 13:32:31 by nmathieu          #+#    #+#              #
#    Updated: 2022/05/19 13:39:11 by nmathieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
CFLAGS		:= -Wall -Wextra -Werror

SRCS_DIR	:= srcs
OBJS_DIR	:= objs

SRCS		:=				\
	main.c					\
	parse_map_byte.c		\
	parse_map.c				\
	print_map_error.c		\
	load_images.c			\
	start_game.c			\
	delta_time.c			\
	hooks.c					\
	move_player.c			\
	render_game.c			\
	put_image.c				\
	load_image.c			\
	math_utils.c			\
	collect_coins.c			\
	finish.c				\
	camera.c				\
	render_player.c			\
	render_coins.c			\
	render_portal.c			\
	render_walls.c			\
	animate_player.c		\
	init_utils.c			\
	animate_coins.c			\
	rng.c					\
	animate_exit.c			\
	init_walls.c			\
	upos_array.c			\
	render_background.c		\
	move_count.c			\
	render_move_count.c		\
	enemy_ai.c				\
	render_enemies.c

INCLUDES	:=				\
	.						\
	libs/minilibx			\
	libs/libft

LIBS		:=				\
	libs/libft/libft.a		\
	libs/minilibx/libmlx.a

HEADERS :=			\
	so_long.h

# ============================================================================ #
#                                 Intermediates                                #
# ============================================================================ #

SRC_FILES = $(addprefix $(SRCS_DIR)/,$(SRCS))
OBJ_FILES = $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

ifdef DEBUG
	CFLAGS += -g3 -D DEBUG
else
	CFLAGS += -O3
endif

INCLUDE_FLAGS = $(addprefix -I , $(INCLUDES))

# ============================================================================ #
#                                   Functions                                  #
# ============================================================================ #

.PHONY: all
all: $(NAME)

.PHONY:
clean:
	@make -C libs/minilibx clean
	@make -C libs/libft fclean
	@rm -vf $(OBJ_FILES)

.PHONY: fclean
fclean:
	@make -C libs/minilibx clean
	@make -C libs/libft fclean
	@rm -vf $(OBJ_FILES) $(NAME)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: CFLAGS += -D SL_BONUS
bonus: $(NAME)

# ============================================================================ #
#                                    Recipes                                   #
# ============================================================================ #

$(NAME): $(LIBS) $(OBJ_FILES)
	clang $(CFLAGS) $(OBJ_FILES) $(LIBS) -lXext -lX11 -lm -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	@mkdir -vp $(dir $@)
	clang $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

libs/minilibx/libmlx.a:
	make -C libs/minilibx do_configure

libs/libft/libft.a:
	make -C libs/libft libft.a
