/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_ai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:13:45 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/25 12:51:58 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

inline static t_fvec	sl_enemy_force(t_enemy *enemy, t_game *game)
{
	t_fvec	force;
	t_fvec	dir;
	float	sqlen;
	float	len;
	size_t	j;

	force = (t_fvec){0.0f, 0.0f};
	j = SIZE_MAX;
	while (++j < game->lvl.enemy_count)
	{
		dir.x = enemy->pos.x - game->lvl.enemies[j].pos.x;
		dir.y = enemy->pos.y - game->lvl.enemies[j].pos.y;
		sqlen = dir.x * dir.x + dir.y * dir.y;
		if (sqlen > 0.0 && sqlen <= ENEMY_REPULSION_THRESHOLD)
		{
			len = sqrtf(sqlen);
			dir.x /= len;
			dir.y /= len;
			force.x += dir.x * ENEMY_REPULSION_AMOUNT / (sqlen + 1.0);
			force.y += dir.y * ENEMY_REPULSION_AMOUNT / (sqlen + 1.0);
		}
	}
	return (force);
}

inline static void	move_enemy(t_enemy *enemy, t_fvec dir, t_fvec acc)
{
	acc.x += dir.x * ENEMY_ACC_FORCE;
	acc.y += dir.y * ENEMY_ACC_FORCE;
	enemy->vel.x += acc.x * DELTA_TIME;
	enemy->vel.y += acc.y * DELTA_TIME;
	enemy->pos.x += enemy->vel.x * DELTA_TIME;
	enemy->pos.y += enemy->vel.y * DELTA_TIME;
	enemy->vel.x *= ENEMY_DRAG_AMOUNT;
	enemy->vel.y *= ENEMY_DRAG_AMOUNT;
}

inline static void	update_enemy(t_game *game, t_enemy *enemy)
{
	t_fvec	dir;
	float	dist;
	float	sqlen;

	dir.x = game->lvl.player_pos.x - enemy->pos.x;
	dir.y = game->lvl.player_pos.y - enemy->pos.y;
	sqlen = dir.x * dir.x + dir.y * dir.y;
	if (!game->lvl.no_player && sqlen <= ENEMY_DAMAGE_RANGE * ENEMY_DAMAGE_RANGE)
	{
		game->lvl.no_player = true;
		game->lvl.explosion = true;
	}
	if (dir.x != 0.0f || dir.y != 0.0f)
	{
		dist = sqrtf(sqlen);
		dir.x /= dist;
		dir.y /= dist;
	}
	if (game->lvl.no_player)
	{
		dir.x = -dir.x;
		dir.y = -dir.y;
	}
	move_enemy(enemy, dir, sl_enemy_force(enemy, game));
}

void	sl_update_enemies(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->lvl.enemy_count)
	{
		update_enemy(game, &game->lvl.enemies[i]);
		i++;
	}
}
