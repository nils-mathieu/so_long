# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 13:32:31 by nmathieu          #+#    #+#              #
#    Updated: 2022/05/13 14:24:04 by nmathieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CFLAGS		= -Wall -Wextra -Werror

SRCS_DIR	= srcs
OBJS_DIR	= objs

SRCS		=			\
	main.c

HEADERS		=

INCLUDES_DIR	= includes

# ============================================================================ #
#                                 Intermediates                                #
# ============================================================================ #

SRC_FILES = $(addprefix $(SRCS_DIR)/,$(SRCS))
OBJ_FILES = $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))
HEADER_FILES = $(addprefix $(INCLUDES_DIR)/,$(HEADERS))

ifdef DEBUG
	CFLAGS += -g3 -D DEBUG
else
	CFLAGS += -O3
endif

# ============================================================================ #
#                                   Functions                                  #
# ============================================================================ #

.PHONY: all
all: $(NAME)

.PHONY:
clean:
	rm -vf $(OBJ_FILES)

.PHONY: fclean
fclean:
	rm -vf $(OBJ_FILES) $(NAME)

.PHONY: re
re: fclean re

# ============================================================================ #
#                                    Recipes                                   #
# ============================================================================ #

$(NAME): $(OBJ_FILES)
	cc $(CLFAGS) $(OBJ_FILES) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER_FILES)
	@mkdir -p $@
	@rmdir $@
	cc $(CFLAGS) -c $< -o $@