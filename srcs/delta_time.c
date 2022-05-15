/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:41:19 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/15 18:43:45 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#ifdef SL_BONUS

float	sl_delta_time(t_instant *prev)
{
	t_instant	now;
	float		delta;

	clock_gettime(1, &now);
	delta = (float)(
			(double)(now.tv_sec - prev->tv_sec)
			+ (double)(now.tv_nsec - prev->tv_nsec) / 1e9);
	*prev = now;
	return (delta);
}

#else

float	sl_delta_time(t_instant *prev)
{
	(void)prev;
	return (0.16);
}

#endif