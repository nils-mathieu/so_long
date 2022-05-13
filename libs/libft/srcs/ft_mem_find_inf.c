/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_find_inf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:55:45 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/04 13:04:37 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const void	*ft_mem_find_inf(const void *p, uint8_t b)
{
	while (true)
	{
		if (*(uint8_t *)p == b)
			return (p);
		p++;
	}
}
