/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:52:34 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 16:45:00 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "__libft_internal.h"

bool	ft_fmt_write(t_writer writer, const char *format, ...)
{
	va_list	args;
	bool	ret;

	va_start(args, format);
	ret = ft_fmt_write_va(writer, format, args);
	va_end(args);
	return (ret);
}

bool	ft_fmt_write_va(t_writer writer, const char *format, va_list args)
{
	while (*format)
	{
		if (!__ft_fmt_parse_format(writer, &format, args))
			return (false);
	}
	return (true);
}
