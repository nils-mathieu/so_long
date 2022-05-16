/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:28:35 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 16:45:07 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef DEBUG

static bool	fd_write(void *self, void *data, size_t count)
{
	(void)self;
	return (ft_write_all(STDERR_FILENO, data, count));
}

void	ft_assert(bool condition, const char *msg, ...)
{
	va_list	args;

	if (condition)
		return ;
	va_start(args, msg);
	ft_fmt_write_va((t_writer){NULL, fd_write}, msg, args);
	ft_write_all(STDERR_FILENO, "\n", 1);
	va_end(args);
	abort();
}

#else

void	ft_assert(bool condition, const char *msg, ...)
{
	(void)condition;
	(void)msg;
}

#endif
