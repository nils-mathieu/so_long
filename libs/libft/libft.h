/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:38:00 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 16:49:05 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>

// ========================================================================== //
//                                   Math                                     //
// ========================================================================== //

// Returns the absolute value of `i`.
//
// If `i` is `INT_MIN`, it is itself returned.
int			ft_int_abs(int i);

// Returns the max of `a` and `b`.
size_t		ft_size_max(size_t a, size_t b);

// Returns the min of `a` and `b`.
size_t		ft_size_min(size_t a, size_t b);

// ========================================================================== //
//                                 Strings                                    //
// ========================================================================== //

// A string that knows its length.
//
// Note that the `data` pointer may or may not be null termiated.
typedef struct s_str
{
	const char	*data;
	size_t		len;
}	t_str;

// Returns the length of the provided string (not including the terminating null
// character.
size_t		ft_str_len(const char *s);

// Returns the length of the provided string (not including the terminating null
// character).
//
// Only up to `n` characters are checked. The return value of this function is
// min(len(s), n).
size_t		ft_str_nlen(const char *s, size_t n);

/// Compares `a` and `b`.
//
// If `a` comes befores `b`, a negative value is returned. If it comes after, a
// positive value is returned. If they are equal, `0` is returned.
int			ft_str_cmp(const char *a, const char *b);

// Returns a pointer to the first character `c` within `s`. If the character
// is not in `s`, `NULL` is returned.
const char	*ft_str_find(const char *s, char c);

// Determines whether `needle` can be found at the start of `s`.
bool		ft_str_starts_with(const char *s, const char *needle);

// ========================================================================== //
//                                   Format                                   //
// ========================================================================== //

// Converts the begining of the provided string into an `uint32_t`.
//
// On success, this function returns a pointer to the first character that
// wasn't parsed. On overflow, `NULL` is returned and `result` is left
// unspecified.
const char	*ft_str_to_uint32(const char *s, uint32_t *result);

// Converts the begining of the provided string into an `int32_t`.
//
// This function accepts a leading `+` or `-` to indicate the sign of the
// output number.
//
// On success, this function returns a pointer to the first character that
// wasn't parsed. On overflow, `NULL` is returned and `result` is left
// unspecified.
const char	*ft_str_to_int32(const char *s, int32_t *result);

// Writes `i` in the provided base. The number is written from the end of the
// `buf_end` pointer. A pointer to the first character is returned.
char		*ft_uint32_to_str(uint32_t i, t_str base, char *buf_end);

// Writes `i` in the provided base. The number is written from the end of the
// `buf_end` pointer. A pointer to the first character is returned.
char		*ft_size_to_str(size_t i, t_str base, char *buf_end);

// Writes `i` in the provided base. The number is written from the end of the
// `buf_end` pointer. A pointer to the first character is returned.
char		*ft_uint_to_str(unsigned int i, t_str base, char *buf_end);

// ========================================================================== //
//                                 Memory                                     //
// ========================================================================== //

// Returns a pointer to the first byte `b` within `p`. If the byte is not in
// `p`, `NULL` is returned.
const void	*ft_mem_find(const void *p, uint8_t b, size_t max);

// Returns a pointer to the first byte `b` within `p`.
const void	*ft_mem_find_inf(const void *p, uint8_t b);

// Returns a pointer to the first byte `b0` or `b1` within `p`. If none of those
// bytes are found in `p`, `NULL` is returned.
const void	*ft_mem_find2(const void *p, uint8_t c0, uint8_t c1, size_t max);

// Returns a pointer to the first byte `b0` or `b1` within `p`.
const void	*ft_mem_find2_inf(const void *p, uint8_t b0, uint8_t b1);

// Copies `n` bytes from `src` to `dst`. Areas must not overlap.
void		ft_mem_copy(void *dst, const void *src, size_t n);

// Fills `dst` with the provided `byte`.
void		ft_mem_set(void *dst, uint8_t byte, size_t n);

// ========================================================================== //
//                               Input/Output                                 //
// ========================================================================== //

// A partially uninitialized buffer.
typedef struct s_buffer
{
	void	*data;
	size_t	init;
	size_t	cap;
}	t_buffer;

// Writes `data` to the provided file descriptor. Returns whether no error
// occured.
bool		ft_write_all(int fd, const void *data, size_t to_write);

// Writes bytes into `buf`, writting everything to the provided file descriptor
// once it is full.
//
// Returns whether the operation is successful.
bool		ft_write_buffered(int fd, t_buffer *buf, const void *p, size_t n);

// Writes `n` times the bytes pointed by `data` to the provided file
// descriptor.
//
// Returns whether the operation was successful.
bool		ft_write_repeat(int fd, const void *data, size_t len, size_t n);

// Writes the provided byte `n` times. Returns whether the operation is
// successful.
bool		ft_write_repeat_one(int fd, uint8_t b, size_t n);

// The result type of most read operations.
//
// `FT_RDRES_INCOMPLETE` - The operation is a success but there is still more
// data to be flushed.
//
// `FT_RDRSLT_DONE` - There is no more data to flush.
//
// `FT_RDRSLT_READ_ERROR` - An error occured whislt reading.
typedef enum e_read_result
{
	FT_RDRES_INCOMPLETE = 1,
	FT_RDRES_DONE = 0,
	FT_RDRES_ERROR = -1,
}	t_rdres;

// A buffered reader.
typedef struct s_reader
{
	int			fd;
	t_buffer	buf;
	size_t		cur;
}	t_reader;

// Refills the internal buffer of a `reader` regardless of its current state.
t_rdres		ft_reader_refill(t_reader *reader);

// Reads a single byte from the provided `reader_t` instance.
t_rdres		ft_read_byte(t_reader *reader, uint8_t *byte);

// ========================================================================== //
//                                   Format                                   //
// ========================================================================== //

// A function that may be used to write the first `count` bytes referenced
// by `to_write`.
typedef bool	(*t_writer_fn)(void *self, void *to_write, size_t count);

// Describes a way to write data somewhere.
typedef struct s_writer
{
	void		*self;
	t_writer_fn	write;
}	t_writer;

// Formats the provided string and writes it using the provided `t_writer`
// instance.
bool		ft_fmt_write_va(t_writer writer, const char *format, va_list args);

// Formats the provided string and writes it using the provided `t_writer`
// instance.
bool		ft_fmt_write(t_writer writer, const char *format, ...);

// Formats the provided string and writes it to the provided file descriptor.
bool		ft_fmt_fd(int fd, const char *format, ...);

// Formats the provided string and writes it to provided file descriptor.
bool		ft_fmt_fd_va(int fd, const char *format, va_list args);

// Formats the provided string and writes to the standard output.
bool		ft_fmt(const char *format, ...);

// Formats the provided string and writes to the standard error.
bool		ft_fmt_err(const char *format, ...);

/// Writes something on the standard error (only on `DEBUG` builds).
bool		ft_dbg(const char *format, ...);

// ========================================================================== //
//                                Allocations                                 //
// ========================================================================== //

/// Allocates `count * size` bytes. This function fails on overflow.
void		*ft_alloc_array(size_t count, size_t size);

// ========================================================================== //
// 								     Debug                                    //
// ========================================================================== //

// Makes an assertion. Aborts the process if it is false.
void		ft_assert(bool	assertion, const char *msg, ...);

#endif
