# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 13:32:31 by nmathieu          #+#    #+#              #
#    Updated: 2022/05/13 16:01:51 by nmathieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CFLAGS		= -Wall -Wextra -Werror

SRCS_DIR	= srcs
OBJS_DIR	= objs

SRCS		=				\
	main.c

INCLUDES	=				\
	.						\
	libs/minilibx			\
	libs/libft

LIBS		=				\
	libs/libft/libft.a		\
	libs/minilibx/libmlx.a

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
	make -C libs/minilibx clean
	make -C libs/libft fclean
	rm -vf $(OBJ_FILES)

.PHONY: fclean
fclean:
	make -C libs/minilibx clean
	make -C libs/libft fclean
	rm -vf $(OBJ_FILES) $(NAME)

.PHONY: re
re: fclean all

# ============================================================================ #
#                                    Recipes                                   #
# ============================================================================ #

$(NAME): $(OBJ_FILES) $(LIBS)
	cc $(CLFAGS) $(OBJ_FILES) $(LIBS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

libs/minilibx/libmlx.a:
	make -C libs/minilibx do_configure

libs/libft/libft.a:
	make -C libs/libft libft.a