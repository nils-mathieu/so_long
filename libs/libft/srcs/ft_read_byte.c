/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:34:12 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/14 00:22:44 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rdres	ft_read_byte(t_reader *reader, uint8_t *byte)
{
	t_rdres	res;

	if (reader->cur == reader->buf.init)
	{
		res = ft_reader_refill(reader);
		if (res <= 0)
			return (res);
	}
	*byte = ((uint8_t *)reader->buf.data)[reader->cur];
	reader->cur++;
	return (FT_RDRES_INCOMPLETE);
}
