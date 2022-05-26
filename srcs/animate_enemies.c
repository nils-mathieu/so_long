/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:19:38 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/26 15:36:25 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ALPHA 0.4142

inline static void	get_bools(float x, float y, bool *up, bool *down)
{
	if (x < 0.0)
	{
		*up = y <= ALPHA * x;
		*down = y >= -ALPHA * x;
	}
	else
	{
		*up = y <= -ALPHA * x;
		*down = y >= ALPHA * x;
	}
}

static size_t	get_enemy_anim(t_fvec dir)
{
	bool	up;
	bool	left;
	bool	down;
	bool	right;

	get_bools(dir.x, dir.y, &up, &down);
	get_bools(dir.y, dir.x, &left, &right);
	return (sl_get_ship_anim(up, left, right, down));
}

void	sl_animate_enemies(t_game *game)
{
	size_t	i;
	size_t	anim;
	float	k;

	k = 1.0f;
	if (game->lvl.game_state != SL_GS_PLAYING)
		k = -1.0f;
	i = 0;
	while (i < game->lvl.enemy_count)
	{
		if (game->lvl.enemies[i].vel.x * game->lvl.enemies[i].vel.x
			+ game->lvl.enemies[i].vel.y * game->lvl.enemies[i].vel.y
			>= ENEMY_DIRECTION_THESHOLD * ENEMY_DIRECTION_THESHOLD)
			anim = get_enemy_anim(game->lvl.enemies[i].vel);
		else
			anim = get_enemy_anim((t_fvec){
					(game->lvl.player_pos.x - game->lvl.enemies[i].pos.x) * k,
					(game->lvl.player_pos.y - game->lvl.enemies[i].pos.y) * k});
		if (anim != SIZE_MAX)
			game->lvl.enemies[i].dir = anim;
		i++;
	}
}
