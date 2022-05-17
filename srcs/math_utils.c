/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:35:24 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/17 18:08:26 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

float	sl_sqdist(t_fpos a, t_fpos b)
{
	t_fvec	diff;

	diff = (t_fvec){a.x - b.x, a.y - b.y};
	return (diff.x * diff.x + diff.y * diff.y);
}

t_fvec	sl_clamp_vec(t_fvec a, float m)
{
	float	len;

	len = (a.x * a.x) + (a.y * a.y);
	if (len > m * m)
	{
		len = m / sqrtf(len);
		a.x *= len;
		a.y *= len;
	}
	return (a);
}
