/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:19:38 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 18:45:47 by nmathieu         ###   ########.fr       */
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

	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemies[i].vel.x * game->enemies[i].vel.x
			+ game->enemies[i].vel.y * game->enemies[i].vel.y
			>= ENEMY_DIRECTION_THESHOLD * ENEMY_DIRECTION_THESHOLD)
			anim = get_enemy_anim(game->enemies[i].vel);
		else
			anim = get_enemy_anim((t_fvec){
					game->player_pos.x - game->enemies[i].pos.x,
					game->player_pos.y - game->enemies[i].pos.y});
		if (anim != SIZE_MAX)
			game->enemies[i].dir = anim;
		i++;
	}
}
