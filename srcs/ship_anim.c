/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:57:38 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 18:04:43 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	sl_get_ship_anim(bool up, bool left, bool right, bool down)
{
	if (up)
	{
		if (left)
			return (7);
		else if (right)
			return (1);
		else
			return (0);
	}
	else if (down)
	{
		if (left)
			return (5);
		else if (right)
			return (3);
		else
			return (4);
	}
	else if (left)
		return (6);
	else if (right)
		return (2);
	else
		return (SIZE_MAX);
}
