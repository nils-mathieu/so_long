# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 11:29:21 by nmathieu          #+#    #+#              #
#    Updated: 2022/05/19 19:18:16 by nmathieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRCS :=									\
	ft_int_abs.c						\
	ft_size_max.c						\
	ft_size_min.c						\
										\
	ft_str_len.c						\
	ft_str_nlen.c						\
	ft_str_cmp.c						\
	ft_str_find.c						\
	ft_str_rfind.c						\
	ft_str_starts_with.c				\
										\
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
	__ft_fmt_handle_string.c			\
	__ft_fmt_handle_int.c				\
	__ft_fmt_handle_bool.c				\
	ft_fmt_write.c						\
	ft_fmt.c							\
	ft_dbg.c							\
										\
	ft_alloc_array.c					\
										\
	ft_assert.c

GEN :=									\
	gen_ft_str_to_int8.c				\
	gen_ft_str_to_int16.c				\
	gen_ft_str_to_int32.c				\
	gen_ft_str_to_int64.c				\
	gen_ft_str_to_int.c					\
	gen_ft_str_to_long.c				\
	gen_ft_str_to_llong.c				\
	gen_ft_str_to_short.c				\
	gen_ft_str_to_char.c

GENERATORS_DIR := generators
SRCS_DIR := srcs
OBJS_DIR := inter/objs
GEN_DIR := inter/gen

HEADER := libft.h __libft_internal.h

OBJ_FILES := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS) $(GEN))
GEN_FILES := $(addprefix $(GEN_DIR)/,$(GEN))

CFLAGS := -Wall -Wextra -Werror

ifdef DEBUG
	CFLAGS += -g3 -D DEBUG
else
	CFLAGS += -O3
endif

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	@rm -vf $(OBJ_FILES)
	@rm -vf $(GEN_FILES)

.PHONY: fclean
fclean: clean
	@rm -vf $(NAME)

.PHONY: re
re: fclean all

$(NAME): $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	@mkdir -vp $(dir $@)
	clang $(CFLAGS) -I. -c $< -o $@

$(OBJS_DIR)/%.o: $(GEN_DIR)/%.c $(HEADER)
	@mkdir -vp $(dir $@)
	clang $(CFLAGS) -I. -c $< -o $@

$(GEN_DIR)/gen_ft_str_to_int8.c: $(GENERATORS_DIR)/ft_str_to_INT.gen
	@echo "generating $@"
	@mkdir -vp $(dir $@)
	@sed									\
		-e "s/{INT}/int8/g"					\
		-e "s/{INT_T}/int8_t/g"				\
		-e "s/{UINT}/uint8/g"				\
		-e "s/{UINT_T}/uint8_t/g"			\
		-e "s/{INT_MIN}/INT8_MIN/g"			\
		-e "s/{UINT_MAX}/UINT8_MAX/g"		\
		${GENERATORS_DIR}/ft_str_to_INT.gen > $@

$(GEN_DIR)/gen_ft_str_to_int16.c: $(GENERATORS_DIR)/ft_str_to_INT.gen
	@echo "generating $@"
	@mkdir -vp $(dir $@)
	@sed										\
		-e "s/{INT}/int16/g"				\
		-e "s/{INT_T}/int16_t/g"			\
		-e "s/{UINT}/uint16/g"				\
		-e "s/{UINT_T}/uint16_t/g"			\
		-e "s/{INT_MIN}/INT16_MIN/g"		\
		-e "s/{UINT_MAX}/UINT16_MAX/g"		\
		${GENERATORS_DIR}/ft_str_to_INT.gen > $@

$(GEN_DIR)/gen_ft_str_to_int32.c: $(GENERATORS_DIR)/ft_str_to_INT.gen
	@echo "generating $@"
	@mkdir -vp $(dir $@)
	@sed									\
		-e "s/{INT}/int32/g"				\
		-e "s/{INT_T}/int32_t/g"			\
		-e "s/{UINT}/uint32/g"				\
		-e "s/{UINT_T}/uint32_t/g"			\
		-e "s/{INT_MIN}/INT32_MIN/g"		\
		-e "s/{UINT_MAX}/UINT32_MAX/g"		\
		${GENERATORS_DIR}/ft_str_to_INT.gen > $@

$(GEN_DIR)/gen_ft_str_to_int64.c: $(GENERATORS_DIR)/ft_str_to_INT.gen
	@echo "generating $@"
	@mkdir -vp $(dir $@)
	@sed									\
		-e "s/{INT}/int64/g"				\
		-e "s/{INT_T}/int64_t/g"			\
		-e "s/{UINT}/uint64/g"				\
		-e "s/{UINT_T}/uint64_t/g"			\
		-e "s/{INT_MIN}/INT64_MIN/g"		\
		-e "s/{UINT_MAX}/UINT64_MAX/g"		\
		${GENERATORS_DIR}/ft_str_to_INT.gen > $@

$(GEN_DIR)/gen_ft_str_to_char.c: $(GENERATORS_DIR)/ft_str_to_INT.gen
	@echo "generating $@"
	@mkdir -vp $(dir $@)
	@sed									\
		-e "s/{INT}/char/g"					\
		-e "s/{INT_T}/char/g"				\
		-e "s/{UINT}/uchar/g"				\
		-e "s/{UINT_T}/unsigned char/g"		\
		-e "s/{INT_MIN}/CHAR_MIN/g"			\
		-e "s/{UINT_MAX}/UCHAR_MAX/g"		\
		${GENERATORS_DIR}/ft_str_to_INT.gen > $@

$(GEN_DIR)/gen_ft_str_to_short.c: $(GENERATORS_DIR)/ft_str_to_INT.gen
	@echo "generating $@"
	@mkdir -vp $(dir $@)
	@sed									\
		-e "s/{INT}/short/g"				\
		-e "s/{INT_T}/short/g"				\
		-e "s/{UINT}/ushort/g"				\
		-e "s/{UINT_T}/unsigned short/g"	\
		-e "s/{INT_MIN}/SHRT_MIN/g"			\
		-e "s/{UINT_MAX}/USHRT_MAX/g"		\
		${GENERATORS_DIR}/ft_str_to_INT.gen > $@

$(GEN_DIR)/gen_ft_str_to_int.c: $(GENERATORS_DIR)/ft_str_to_INT.gen
	@echo "generating $@"
	@mkdir -vp $(dir $@)
	@sed									\
		-e "s/{INT}/int/g"					\
		-e "s/{INT_T}/int/g"				\
		-e "s/{UINT}/uint/g"				\
		-e "s/{UINT_T}/unsigned int/g"		\
		-e "s/{INT_MIN}/INT_MIN/g"			\
		-e "s/{UINT_MAX}/UINT_MAX/g"		\
		${GENERATORS_DIR}/ft_str_to_INT.gen > $@

$(GEN_DIR)/gen_ft_str_to_long.c: $(GENERATORS_DIR)/ft_str_to_INT.gen
	@echo "generating $@"
	@mkdir -vp $(dir $@)
	@sed									\
		-e "s/{INT}/long/g"					\
		-e "s/{INT_T}/long/g"				\
		-e "s/{UINT}/ulong/g"				\
		-e "s/{UINT_T}/unsigned long/g"		\
		-e "s/{INT_MIN}/LONG_MIN/g"			\
		-e "s/{UINT_MAX}/ULONG_MAX/g"		\
		${GENERATORS_DIR}/ft_str_to_INT.gen > $@

$(GEN_DIR)/gen_ft_str_to_llong.c: $(GENERATORS_DIR)/ft_str_to_INT.gen
	@echo "generating $@"
	@mkdir -vp $(dir $@)
	@sed										\
		-e "s/{INT}/llong/g"					\
		-e "s/{INT_T}/long long/g"				\
		-e "s/{UINT}/ullong/g"					\
		-e "s/{UINT_T}/unsigned long long/g"	\
		-e "s/{INT_MIN}/LLONG_MIN/g"			\
		-e "s/{UINT_MAX}/ULLONG_MAX/g"			\
		${GENERATORS_DIR}/ft_str_to_INT.gen > $@
