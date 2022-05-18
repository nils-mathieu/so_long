/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:32:26 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 02:00:33 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_update_player_dir(t_game *game)
{
	if (game->recoil_duration > 0.0f)
		return ;
	if (game->pressing_up)
	{
		if (game->pressing_left)
			game->player_dir = 7;
		else if (game->pressing_right)
			game->player_dir = 1;
		else
			game->player_dir = 0;
	}
	else if (game->pressing_down)
	{
		if (game->pressing_left)
			game->player_dir = 5;
		else if (game->pressing_right)
			game->player_dir = 3;
		else
			game->player_dir = 4;
	}
	else if (game->pressing_left)
		game->player_dir = 6;
	else if (game->pressing_right)
		game->player_dir = 2;
}

void	sl_animate_player(t_game *game)
{
	size_t	to_add;
	size_t	stops_at;

	if (game->pressing_down || game->pressing_up
		|| game->pressing_left || game->pressing_right)
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
	else
		game->next_player_anim_frame -= game->delta_time;
}
