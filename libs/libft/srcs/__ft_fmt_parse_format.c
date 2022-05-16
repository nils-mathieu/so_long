/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_fmt_parse_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:22:08 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 19:10:43 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__libft_internal.h"
#include <stdio.h>

#define FORMAT_HANDLER_COUNT 8

static inline t_fmt_handler	*fmt_handler(void)
{
	static t_fmt_handler	handlers[FORMAT_HANDLER_COUNT] = {
		(t_fmt_handler){(t_str){"u32", 3}, __ft_fmt_handle_u32},
		(t_fmt_handler){(t_str){"i32", 3}, __ft_fmt_handle_i32},
		(t_fmt_handler){(t_str){"i", 1}, __ft_fmt_handle_int},
		(t_fmt_handler){(t_str){"s?", 2}, __ft_fmt_handle_debug_string},
		(t_fmt_handler){(t_str){"s", 1}, __ft_fmt_handle_string},
		(t_fmt_handler){(t_str){"c?", 2}, __ft_fmt_handle_debug_char},
		(t_fmt_handler){(t_str){"c", 1}, __ft_fmt_handle_char},
		(t_fmt_handler){(t_str){"b", 1}, __ft_fmt_handle_bool},
	};

	return (handlers);
}

static bool	handle_format(t_writer w, const char **f, va_list args)
{
	size_t	i;

	i = 0;
	while (i < FORMAT_HANDLER_COUNT
		&& !ft_str_starts_with(*f, fmt_handler()[i].id.data))
		i++;
	if (i == FORMAT_HANDLER_COUNT)
		return (false);
	*f += fmt_handler()[i].id.len;
	if (**f != '}')
		return (false);
	(*f)++;
	return (fmt_handler()[i].format(w, args));
}

bool	__ft_fmt_parse_format(t_writer w, const char **f, va_list args)
{
	const char	*start;

	if (**f == '{')
	{
		(*f)++;
		if (**f == '{')
			return ((*f)++, w.write(w.self, "{", 1));
		return (handle_format(w, f, args));
	}
	start = *f;
	*f = ft_mem_find2_inf(*f, '\0', '{');
	return (w.write(w.self, (void *)start, *f - start));
}
