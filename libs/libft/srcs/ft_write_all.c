/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:19:14 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/06 09:47:11 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

bool	ft_write_all(int fd, const void *data, size_t len)
{
	ssize_t	count;

	while (len)
	{
		count = write(fd, data, len);
		if (count < 0)
			return (false);
		len -= count;
		data += count;
	}
	return (true);
}
