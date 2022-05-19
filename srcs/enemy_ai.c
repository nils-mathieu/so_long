/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_ai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:13:45 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 17:09:15 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

#define ALPHA 0.4142

inline static t_fvec	sl_enemy_force(size_t i, t_game *game)
{
	t_fvec	force;
	t_fvec	dir;
	float	sqlen;
	float	len;
	size_t	j;

	force = (t_fvec){0.0f, 0.0f};
	j = 0;
	while (j < game->enemy_count)
	{
		if (j == i)
		{
			j++;
			continue ;
		}
		dir.x = game->enemies[i].pos.x - game->enemies[j].pos.x;
		dir.y = game->enemies[i].pos.y - game->enemies[j].pos.y;
		sqlen = dir.x * dir.x + dir.y * dir.y;
		if (sqlen > 0.0 && sqlen <= ENEMY_REPULSION_THRESHOLD)
		{
			len = sqrtf(sqlen);
			dir.x /= len;
			dir.y /= len;
			force.x += dir.x * ENEMY_REPULSION_AMOUNT / (sqlen + 1.0);
			force.y += dir.y * ENEMY_REPULSION_AMOUNT / (sqlen + 1.0);
		}
		j++;
	}
	return (force);
}

#include <stdio.h>
inline static void	animate(t_enemy *enemy, t_fvec dir)
{
	bool	up;
	bool	left;
	bool	down;
	bool	right;
	size_t	i;

	if (dir.x < 0.0)
	{
		up = dir.y <= ALPHA * dir.x;
		down = dir.y >= -ALPHA * dir.x;
	}
	else
	{
		up = dir.y <= -ALPHA * dir.x;
		down = dir.y >= ALPHA * dir.x;
	}
	if (dir.y < 0.0)
	{
		left = dir.x <= ALPHA * dir.y;
		right = dir.x >= -ALPHA * dir.y;
	}
	else
	{
		left = dir.x <= -ALPHA * dir.y;
		right = dir.x >= ALPHA * dir.y;
	}
	i = sl_get_ship_anim(up, left, right, down);
	if (i != SIZE_MAX)
		enemy->dir = i;
}

void	sl_update_enemies(t_game *game)
{
	size_t	i;
	t_fvec	dir;
	float	dist;
	t_fvec	acc;

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
		acc = sl_enemy_force(i, game);
		acc.x += dir.x * ENEMY_ACC_FORCE;
		acc.y += dir.y * ENEMY_ACC_FORCE;
		game->enemies[i].vel.x += acc.x * game->delta_time;
		game->enemies[i].vel.y += acc.y * game->delta_time;
		game->enemies[i].pos.x += game->enemies[i].vel.x * game->delta_time;
		game->enemies[i].pos.y += game->enemies[i].vel.y * game->delta_time;
		game->enemies[i].vel.x *= ENEMY_DRAG_AMOUNT;
		game->enemies[i].vel.y *= ENEMY_DRAG_AMOUNT;
		if (game->enemies[i].vel.x * game->enemies[i].vel.x
			+ game->enemies[i].vel.y * game->enemies[i].vel.y
			>= ENEMY_DIRECTION_THESHOLD * ENEMY_DIRECTION_THESHOLD)
			animate(&game->enemies[i], game->enemies[i].vel);
		else
			animate(&game->enemies[i], dir);
		i++;
	}
}
