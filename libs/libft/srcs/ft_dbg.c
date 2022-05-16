/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:49:52 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 16:52:15 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

#ifdef DEBUG

bool	ft_dbg(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	if (!ft_fmt_fd_va(STDERR_FILENO, format, args))
		return (va_end(args), false);
	va_end(args);
	return (true);
}

#else

bool	ft_dbg(const char *format, ...)
{
	(void)format;
	return (true);
}

#endif