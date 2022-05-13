# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 11:29:21 by nmathieu          #+#    #+#              #
#    Updated: 2022/05/13 15:33:32 by nmathieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =								\
	ft_int_abs						\
	ft_size_max						\
	ft_size_min						\
									\
	ft_str_len						\
	ft_str_nlen						\
	ft_str_cmp						\
	ft_str_find						\
									\
	ft_str_to_uint32				\
	ft_str_to_int32					\
	ft_size_to_str					\
	ft_uint_to_str					\
									\
	ft_mem_find						\
	ft_mem_find_inf					\
	ft_mem_find2					\
	ft_mem_find2_inf				\
	ft_mem_copy						\
	ft_mem_set						\
									\
	ft_write_all					\
	ft_write_buffered				\
	ft_write_repeat					\
	ft_write_repeat_one				\
	ft_reader_refill				\
	ft_read_byte					\
									\
	ft_alloc_array					\
									\
	ft_assert

SRCS_DIR = srcs
OBJS_DIR = objs

HEADER = libft.h

SRC_FILES = $(patsubst %,$(SRCS_DIR)/%.c,$(SRCS))
OBJ_FILES = $(patsubst %,$(OBJS_DIR)/%.o,$(SRCS))

CFLAGS = -Wall -Wextra -Werror

ifdef DEBUG
	CFLAGS += -g3 -D DEBUG
else
	CFLAGS += -O3
endif

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -vf $(OBJ_FILES)

.PHONY: fclean
fclean: clean
	rm -vf $(NAME)

.PHONY: re
re: fclean all

$(NAME): $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER) | objs
	cc $(CFLAGS) -I. -c $< -o $@
