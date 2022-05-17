/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:35:24 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 01:23:15 by nmathieu         ###   ########.fr       */
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

float	sl_lerp(float a, float b, float t)
{
	return (a + t * (b - a));
}
