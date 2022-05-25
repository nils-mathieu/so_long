/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:03:07 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/25 12:52:42 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>
#include "libft.h"

void	sl_count_movements(t_game *game)
{
	if (game->lvl.no_player)
		return ;
	if (game->lvl.rem_dist > 0.0)
	{
		game->lvl.rem_dist -= sqrtf(game->lvl.player_vel.x
				* game->lvl.player_vel.x
				+ game->lvl.player_vel.y * game->lvl.player_vel.y)
				* DELTA_TIME;
		return ;
	}
	game->lvl.move_count++;
	game->lvl.rem_dist = 1.0f;
}
