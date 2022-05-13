/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_refill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:28:40 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 15:40:31 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

t_rdres	ft_reader_refill(t_reader *reader)
{
	ssize_t	count;

	count = read(reader->fd, reader->buf.data, reader->buf.cap);
	if (count < 0)
		return (FT_RDRES_ERROR);
	reader->cur = 0;
	reader->buf.init = (size_t)count;
	if (count == 0)
		return (FT_RDRES_DONE);
	else
		return (FT_RDRES_INCOMPLETE);
}
