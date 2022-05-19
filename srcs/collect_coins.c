/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_coins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:26:36 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 17:37:44 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

static t_fpos	random_point_outside(t_game *game)
{
	t_fpos	result;
	float	radius;
	float	alpha;

	result = game->player_pos;
	radius = sqrtf((float)(WIDTH * WIDTH) * 0.25f
		+ (float)(HEIGHT * HEIGHT) * 0.25f) / PIXELS_PER_UNIT;
	alpha = 6.28 * (float)(uint8_t)sl_random(game) / 255.0f;
	result.x += cosf(alpha) * (radius + 2.0);
	result.y += sinf(alpha) * (radius + 2.0);
	return (result);
}

void	sl_collect_coins(t_game *g)
{
	size_t	i;
	float sqdist;

	i = 0;
	while (i < g->rem_coins)
	{
		sqdist = sl_sqdist(g->coins[i].pos, g->player_pos);
		if (sqdist <= COIN_COL_R * COIN_COL_R)
		{
			g->coins[i].pos.x = sl_lerp(g->coins[i].pos.x, g->player_pos.x, COIN_SPEED);
			g->coins[i].pos.y = sl_lerp(g->coins[i].pos.y, g->player_pos.y, COIN_SPEED);
		}
		if (sqdist <= COIN_DISP_R * COIN_DISP_R)
		{
			g->coins[i] = g->coins[g->rem_coins - 1];
			g->rem_coins--;
			g->enemies[g->enemy_count].anim_frame = sl_random(g) % 3;
			g->enemies[g->enemy_count].next_anim_frame
				= (float)(uint8_t)sl_random(g) / 255.0f;
			g->enemies[g->enemy_count].dir = 0;
			g->enemies[g->enemy_count].pos = random_point_outside(g);
			g->enemies[g->enemy_count].vel = (t_fvec){0.0f, 0.0f};
			g->enemy_count++;
			continue ;
		}
		i++;
	}
}
