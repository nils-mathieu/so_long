/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __libft_fmt.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:13:41 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 23:26:28 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_FMT_H
# define __LIBFT_FMT_H

# include "libft.h"

typedef bool	(*t_handle_format_fn)(t_writer w, va_list args);

typedef struct s_format_handler
{
	t_str				id;
	t_handle_format_fn	format;
}	t_fmt_handler;

bool	__ft_fmt_parse_format(t_writer w, const char **f, va_list args);

bool	__ft_fmt_handle_u32(t_writer w, va_list args);
bool	__ft_fmt_handle_i32(t_writer w, va_list args);
bool	__ft_fmt_handle_char(t_writer w, va_list args);
bool	__ft_fmt_handle_debug_char(t_writer w, va_list args);

#endif