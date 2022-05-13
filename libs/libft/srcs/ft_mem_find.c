/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:53:23 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/04 13:03:51 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const void	*ft_mem_find(const void *p, uint8_t b, size_t max)
{
	while (max)
	{
		if (*(uint8_t *)p == b)
			return (p);
		p++;
		max--;
	}
	return (NULL);
}
