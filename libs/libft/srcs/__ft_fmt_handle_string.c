/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_fmt_handle_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:10:19 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 18:20:54 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__libft_internal.h"
#include "libft.h"

bool	__ft_fmt_handle_string(t_writer w, va_list args)
{
	const char	*s;

	s = va_arg(args, const char *);
	return (w.write(w.self, (void *)s, ft_str_len(s)));
}

static bool	debug_char(t_writer w, char c)
{
	if (c == '\n')
		return (w.write(w.self, "\\n", 2));
	else if (c == '\0')
		return (w.write(w.self, "\\0", 2));
	else if (c == '\t')
		return (w.write(w.self, "\\t", 2));
	else if (c == '\r')
		return (w.write(w.self, "\\r", 2));
	else if (c == '\v')
		return (w.write(w.self, "\\v", 2));
	else if (c == '\f')
		return (w.write(w.self, "\\f", 2));
	else if (c < ' ' || '~' < c)
		return (w.write(w.self, "\\?", 2));
	else
		return (w.write(w.self, &c, 1));
}

bool	__ft_fmt_handle_debug_string(t_writer w, va_list args)
{
	const char	*s;

	s = va_arg(args, const char *);
	while (*s)
	{
		if (!debug_char(w, *s))
			return (false);
		s++;
	}
	return (true);
}
