/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:32:26 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/25 12:50:02 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_update_player_dir(t_game *game)
{
	size_t	i;

	if (game->lvl.recoil_duration > 0.0f)
		return ;
	i = sl_get_ship_anim(
			game->lvl.pressing_up, game->lvl.pressing_left,
			game->lvl.pressing_right, game->lvl.pressing_down);
	if (i != SIZE_MAX)
		game->lvl.player_dir = i;
}

void	sl_animate_explosion(t_game *game)
{
	if (!game->lvl.explosion)
		return ;
	if (game->lvl.next_explosion_anim_frame <= 0.0)
	{
		game->lvl.explosion_anim_frame += 1;
		game->lvl.next_explosion_anim_frame = EXPLOSION_ANIM_SPEED;
		if (game->lvl.explosion_anim_frame == 5)
			game->lvl.explosion = false;
	}
	game->lvl.next_explosion_anim_frame -= DELTA_TIME;
}

void	sl_animate_shield(t_game *game)
{
	if (!game->lvl.shield)
		return ;
	if (game->lvl.next_shield_anim_frame <= 0.0)
	{
		game->lvl.shield_anim_frame -= 1;
		game->lvl.next_shield_anim_frame = SHIELD_ANIM_SPEED;
		if (game->lvl.shield_anim_frame == UINT32_MAX)
			game->lvl.shield = false;
	}
	game->lvl.next_shield_anim_frame -= DELTA_TIME;
}

void	sl_animate_player(t_game *game)
{
	size_t	to_add;
	size_t	stops_at;

	if (game->lvl.no_player)
		return ;
	if (game->lvl.pressing_down || game->lvl.pressing_up
		|| game->lvl.pressing_left || game->lvl.pressing_right)
	{
		to_add = 1;
		stops_at = 7;
	}
	else
	{
		stops_at = 0;
		to_add = SIZE_MAX;
	}
	if (game->lvl.next_player_anim_frame <= 0.0)
	{
		if (game->lvl.player_anim_frame == stops_at)
			game->lvl.player_anim_frame = stops_at - to_add;
		else
			game->lvl.player_anim_frame += to_add;
		game->lvl.next_player_anim_frame = PLAYER_ANIM_SPEED;
	}
	game->lvl.next_player_anim_frame -= DELTA_TIME;
}
