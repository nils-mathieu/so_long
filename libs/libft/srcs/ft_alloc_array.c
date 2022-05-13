/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:19:40 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/07 10:21:22 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_alloc_array(size_t count, size_t size)
{
	size_t	result;

	result = count * size;
	if (size != 0 && result / size != count)
		return (NULL);
	return (malloc(result));
}
