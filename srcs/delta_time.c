/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:41:19 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/17 17:39:11 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

#ifdef SL_BONUS

uint64_t	sl_get_current_timestamp(void)
{
	struct timespec	instant;

	clock_gettime(1, &instant);
	return ((uint64_t)instant.tv_sec * 1000000000
		+ (uint64_t)instant.tv_nsec);
}

float	sl_delta_time(uint64_t *prev)
{
	uint64_t	delta;
	uint64_t	now;

	delta = 0;
	while (delta < TARGET_DELTA)
	{
		now = sl_get_current_timestamp();
		delta = now - *prev;
	}
	*prev = now;
	return ((float)((double)TARGET_DELTA / 1e9));
}

#else

uint64_t	sl_get_current_timestamp(void)
{
	return (0);
}


float	sl_delta_time(uint64_t *prev)
{
	(void)prev;
	return ((float)((double)TARGET_DELTA / 1e9));
}

#endif