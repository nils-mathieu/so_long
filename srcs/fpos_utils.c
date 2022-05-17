/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpos_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:35:24 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/17 14:59:41 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

float	sl_sqdist(t_fpos a, t_fpos b)
{
	t_fvec	diff;

	diff = (t_fvec){a.x - b.x, a.y - b.y};
	return (diff.x * diff.x + diff.y * diff.y);
}
