/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_fmt_handle_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:30:43 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 23:51:31 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__libft_fmt.h"
#include <stdio.h>

bool	__ft_fmt_handle_char(t_writer w, va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (w.write(w.self, &c, 1));
}

bool	__ft_fmt_handle_debug_char(t_writer w, va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
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
