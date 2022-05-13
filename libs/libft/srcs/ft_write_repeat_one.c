/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_repeat_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:24:05 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/05 21:34:51 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

#define BUF_SIZE 64

bool	ft_write_repeat_one(int fd, uint8_t b, size_t n)
{
	uint8_t	buf[BUF_SIZE];
	ssize_t	count;

	if (n < BUF_SIZE)
	{
		ft_mem_set(buf, b, n);
		return (ft_write_all(fd, buf, n));
	}
	else
	{
		ft_mem_set(buf, b, BUF_SIZE);
		while (n >= BUF_SIZE)
		{
			count = write(fd, buf, BUF_SIZE);
			if (count < 0)
				return (false);
			n -= count;
		}
		return (ft_write_all(fd, buf, n));
	}
}
