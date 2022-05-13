/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_buffered.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:55:15 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/05 21:30:30 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

bool	ft_write_buffered(int fd, t_buffer *buf, const void *p, size_t n)
{
	if (n > buf->cap - buf->init)
	{
		if (!ft_write_all(fd, buf->data, buf->init))
			return (false);
		return (ft_write_all(fd, p, n));
	}
	else
	{
		ft_mem_copy(buf->data + buf->init, p, n);
		buf->init += n;
		return (true);
	}
}
