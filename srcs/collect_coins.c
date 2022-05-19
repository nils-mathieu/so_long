/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_coins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:26:36 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 17:29:02 by nmathieu         ###   ########.fr       */
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

void	sl_collect_coins(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->rem_coins)
	{
		if (sl_sqdist(game->coins[i].pos,
				game->player_pos) <= COIN_COL_R * COIN_COL_R)
		{
			game->coins[i] = game->coins[game->rem_coins - 1];
			game->rem_coins--;
			game->enemies[game->enemy_count].anim_frame = sl_random(game) % 3;
			game->enemies[game->enemy_count].next_anim_frame
				= (float)(uint8_t)sl_random(game) / 255.0f;
			game->enemies[game->enemy_count].dir = 0;
			game->enemies[game->enemy_count].pos = random_point_outside(game);
			game->enemies[game->enemy_count].vel = (t_fvec){0.0f, 0.0f};
			game->enemy_count++;
		}
		else
			i++;
	}
}
