/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_repeat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:13:51 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/05 21:31:12 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_write_repeat(int fd, const void *data, size_t len, size_t n)
{
	uint8_t		container[64];
	t_buffer	buf;

	buf.data = container;
	buf.init = 0;
	buf.cap = 64;
	while (n)
	{
		ft_write_buffered(fd, &buf, data, len);
		n--;
	}
	return (ft_write_all(fd, buf.data, buf.init));
}
