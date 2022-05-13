/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint32_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:21:28 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/05 12:38:50 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uint32_to_str(uint32_t i, t_str base, char *buf_end)
{
	while (i)
	{
		buf_end--;
		*buf_end = base.data[i % base.len];
		i /= base.len;
	}
	return (buf_end);
}
