# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 11:29:21 by nmathieu          #+#    #+#              #
#    Updated: 2022/05/13 23:59:29 by nmathieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =									\
	ft_int_abs.c						\
	ft_size_max.c						\
	ft_size_min.c						\
										\
	ft_str_len.c						\
	ft_str_nlen.c						\
	ft_str_cmp.c						\
	ft_str_find.c						\
	ft_str_starts_with.c				\
										\
	ft_str_to_uint32.c					\
	ft_str_to_int32.c					\
	ft_size_to_str.c					\
	ft_uint_to_str.c					\
	ft_uint32_to_str.c					\
										\
	ft_mem_find.c						\
	ft_mem_find_inf.c					\
	ft_mem_find2.c						\
	ft_mem_find2_inf.c					\
	ft_mem_copy.c						\
	ft_mem_set.c						\
										\
	ft_write_all.c						\
	ft_write_buffered.c					\
	ft_write_repeat.c					\
	ft_write_repeat_one.c				\
	ft_reader_refill.c					\
	ft_read_byte.c						\
										\
	__ft_fmt_parse_format.c				\
	__ft_fmt_handle_u32.c				\
	__ft_fmt_handle_i32.c				\
	__ft_fmt_handle_char.c				\
	ft_fmt_write.c						\
	ft_fmt.c							\
										\
	ft_alloc_array.c					\
										\
	ft_assert.c

SRCS_DIR = srcs
OBJS_DIR = objs

HEADER = libft.h

SRC_FILES = $(addprefix $(SRCS_DIR)/,$(SRCS))
OBJ_FILES = $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

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

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	mkdir -p $(dir $@)
	cc $(CFLAGS) -I. -c $< -o $@
