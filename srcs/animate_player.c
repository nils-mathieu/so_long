/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:32:26 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/20 16:57:44 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_update_player_dir(t_game *game)
{
	size_t	i;

	if (game->recoil_duration > 0.0f)
		return ;
	i = sl_get_ship_anim(
			game->pressing_up, game->pressing_left,
			game->pressing_right, game->pressing_down);
	if (i != SIZE_MAX)
		game->player_dir = i;
}

void	sl_animate_explosion(t_game *game)
{
	if (!game->explosion)
		return ;
	if (game->next_explosion_anim_frame <= 0.0)
	{
		game->explosion_anim_frame += 1;
		game->next_explosion_anim_frame = EXPLOSION_ANIM_SPEED;
		if (game->explosion_anim_frame == 5)
			game->explosion = false;
	}
	game->next_explosion_anim_frame -= DELTA_TIME;
}

#include <stdio.h>
void	sl_animate_shield(t_game *game)
{
	if (!game->shield)
		return ;
	if (game->next_shield_anim_frame <= 0.0)
	{
		game->shield_anim_frame -= 1;
		game->next_shield_anim_frame = SHIELD_ANIM_SPEED;
		if (game->shield_anim_frame == UINT32_MAX)
			game->shield = false;
	}
	game->next_shield_anim_frame -= DELTA_TIME;
}

void	sl_animate_player(t_game *game)
{
	size_t	to_add;
	size_t	stops_at;

	if (game->no_player)
		return ;
	if (game->pressing_down || game->pressing_up || game->pressing_left || game->pressing_right)
	{
		to_add = 1;
		stops_at = 7;
	}
	else
	{
		stops_at = 0;
		to_add = SIZE_MAX;
	}
	if (game->next_player_anim_frame <= 0.0)
	{
		if (game->player_anim_frame == stops_at)
			game->player_anim_frame = stops_at - to_add;
		else
			game->player_anim_frame += to_add;
		game->next_player_anim_frame = PLAYER_ANIM_SPEED;
	}
	game->next_player_anim_frame -= DELTA_TIME;
}
