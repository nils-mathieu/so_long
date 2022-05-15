# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 13:32:31 by nmathieu          #+#    #+#              #
#    Updated: 2022/05/16 00:28:21 by nmathieu         ###   ########.fr        #
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
	render.c				\
	put_image.c				\
	load_image.c

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

ifdef RELEASE
	CFLAGS += -O3 -flto
else
	CFLAGS += -g3 -D DEBUG
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
	cc $(CFLAGS) $(OBJ_FILES) $(LIBS) -lXext -lX11 -lm -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	@mkdir -vp $(dir $@)
	cc $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

libs/minilibx/libmlx.a:	
	make -C libs/minilibx do_configure

libs/libft/libft.a:
	make -C libs/libft libft.a