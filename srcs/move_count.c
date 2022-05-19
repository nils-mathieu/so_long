/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:03:07 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 20:30:14 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>
#include "libft.h"

void	sl_count_movements(t_game *game)
{
	if (game->no_player)
		return ;
	if (game->rem_dist > 0.0)
	{
		game->rem_dist -= sqrtf(game->player_vel.x * game->player_vel.x
				+ game->player_vel.y * game->player_vel.y) * game->delta_time;
		return ;
	}
	game->move_count++;
	game->rem_dist = 1.0f;
	ft_fmt("Movements: {u32}\n", game->move_count);
}
