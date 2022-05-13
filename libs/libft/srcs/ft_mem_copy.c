/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:20:52 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/05 21:23:08 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mem_copy(void *dst, const void *src, size_t n)
{
	while (n)
	{
		*(uint8_t *)dst = *(const uint8_t *)src;
		dst++;
		src++;
		n--;
	}
}
