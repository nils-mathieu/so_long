/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_find2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:57:53 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/04 13:04:50 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const void	*ft_mem_find2(const void *p, uint8_t c0, uint8_t c1, size_t max)
{
	while (max)
	{
		if (*(uint8_t *)p == c0 || *(uint8_t *)p == c1)
			return (p);
		max--;
		p++;
	}
	return (NULL);
}
