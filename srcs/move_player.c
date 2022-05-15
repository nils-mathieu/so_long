/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:39:34 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 00:33:35 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_move_player(t_game *game)
{
	t_fvec	acc;

	acc.x = game->movement_input.x * PLAYER_ACCELERATION_FORCE;
	acc.y = game->movement_input.y * PLAYER_ACCELERATION_FORCE;
	game->player_vel.x += acc.x * game->delta_time;
	game->player_vel.y += acc.y * game->delta_time;
	game->player_pos.x += game->player_vel.x * game->delta_time;
	game->player_pos.y += game->player_vel.y * game->delta_time;
	game->player_vel.x -= game->player_vel.x * PLAYER_DRAG_AMOUNT;
	game->player_vel.y -= game->player_vel.y * PLAYER_DRAG_AMOUNT;
}
