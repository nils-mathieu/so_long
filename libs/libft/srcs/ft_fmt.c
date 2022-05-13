/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:43:33 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 20:18:07 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static bool	fd_write(void *self, void *data, size_t count)
{
	return (ft_write_all(*(int *)self, data, count));
}

static inline bool	ft_fmt_fd_va(int fd, const char *format, va_list args)
{
	return (ft_fmt_write_va((t_writer){&fd, fd_write}, format, args));
}

bool	ft_fmt_fd(int fd, const char *format, ...)
{
	bool	ret;
	va_list	args;

	(void)fd;
	ret = false;
	va_start(args, format);
	ret = ft_fmt_fd_va(fd, format, args);
	va_end(args);
	return (ret);
}

bool	ft_fmt(const char *format, ...)
{
	bool	ret;
	va_list	args;

	va_start(args, format);
	ret = ft_fmt_fd_va(STDOUT_FILENO, format, args);
	va_end(args);
	return (ret);
}

bool	ft_fmt_err(const char *format, ...)
{
	bool	ret;
	va_list	args;

	va_start(args, format);
	ret = ft_fmt_fd_va(STDERR_FILENO, format, args);
	va_end(args);
	return (ret);
}
