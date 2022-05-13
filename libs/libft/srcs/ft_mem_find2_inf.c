/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_find2_inf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:01:45 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/04 18:11:42 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const void	*ft_mem_find2_inf(const void *p, uint8_t b0, uint8_t b1)
{
	while (true)
	{
		if (*(uint8_t *)p == b0 || *(uint8_t *)p == b1)
			return (p);
		p++;
	}
}
