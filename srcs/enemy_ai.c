/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_ai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:13:45 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 14:06:36 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

void	sl_update_enemies(t_game *game)
{
	size_t	i;
	t_fvec	dir;
	float	dist;

	i = 0;
	while (i < game->enemy_count)
	{
		dir.x = game->player_pos.x - game->enemies[i].pos.x;
		dir.y = game->player_pos.y - game->enemies[i].pos.y;
		if (dir.x != 0.0f || dir.y != 0.0f)
		{
			dist = sqrtf(dir.x * dir.x + dir.y * dir.y);
			dir.x /= dist;
			dir.y /= dist;
		}
		game->enemies[i].vel.x += dir.x * ENEMY_ACC_FORCE * game->delta_time;
		game->enemies[i].vel.y += dir.y * ENEMY_ACC_FORCE * game->delta_time;
		game->enemies[i].pos.x += game->enemies[i].vel.x * game->delta_time;
		game->enemies[i].pos.y += game->enemies[i].vel.y * game->delta_time;
		game->enemies[i].pos.x *= ENEMY_DRAG_AMOUNT;
		game->enemies[i].pos.y *= ENEMY_DRAG_AMOUNT;
		i++;
	}
}
