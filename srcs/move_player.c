/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:39:34 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/17 17:33:33 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

// Determines whether the player collides with the given wall.
inline static bool	collides(t_fpos wall, t_fpos pos)
{
	bool	up;
	bool	left;
	bool	right;
	bool	down;

	up = pos.y + PLAYER_COL_H * 0.5f < wall.y;
	left = pos.x + PLAYER_COL_W * 0.5f < wall.x;
	right = pos.x - PLAYER_COL_W * 0.5f > wall.x + 1.0f;
	down = pos.y - PLAYER_COL_H * 0.5f > wall.y + 1.0f;
	return (!up && !left && !right && !down);
}

static t_fvec	compute_disp(t_fvec vel, t_fpos wall, t_fpos p)
{
	t_fvec	disp;

	if (vel.x < 0.0f)
		disp.x = (wall.x + 1.0) - (p.x - PLAYER_COL_W * 0.5f);
	else
		disp.x = wall.x - (p.x + PLAYER_COL_W * 0.5f);
	if (vel.y < 0.0f)
		disp.y = (wall.y + 1.0) - (p.y - PLAYER_COL_H * 0.5f);
	else
		disp.y = wall.y - (p.y + PLAYER_COL_H * 0.5f);
	if (fabsf(disp.x) < fabsf(disp.y))
		disp.y = 0.0;
	else
		disp.x = 0.0;
	return (disp);
}

#include <stdio.h>
static void	bounce(t_game *g)
{
	t_fpos	wall;
	t_fvec	max_disp;
	t_fvec	disp;
	size_t	i;

	g->player_vel = sl_clamp_vec(g->player_vel, MAX_VELOCITY);
	g->player_pos.x += g->player_vel.x * g->delta_time;
	g->player_pos.y += g->player_vel.y * g->delta_time;
	i = 0;
	max_disp.x = 0.0;
	max_disp.y = 0.0;
	while (i < g->wall_count)
	{
		wall = (t_fpos){(float)g->walls[i].x, (float)g->walls[i].y};
		if (collides(wall, g->player_pos))
		{
			disp = compute_disp(g->player_vel, wall, g->player_pos);
			if (fabsf(disp.y) > max_disp.y)
				max_disp.y = disp.y;
			if (fabsf(disp.x) > max_disp.x)
				max_disp.x = disp.x;
		}
		i++;
	}
	g->player_pos.x += max_disp.x * PHYSICS_ROOM;
	g->player_pos.y += max_disp.y * PHYSICS_ROOM;
	if (fabsf(max_disp.x) < fabsf(max_disp.y) - 0.001)
	{
		g->player_vel.y = -g->player_vel.y;
		if (g->player_vel.y < 0.0)
			g->player_vel.y -= BOUNCE_AMOUNT;
		else
			g->player_vel.y += BOUNCE_AMOUNT;
	}
	else if (fabsf(max_disp.x) > fabsf(max_disp.y) + 0.001)
	{
		g->player_vel.x = -g->player_vel.x;
		if (g->player_vel.x < 0.0)
			g->player_vel.x -= BOUNCE_AMOUNT;
		else
			g->player_vel.x += BOUNCE_AMOUNT;
	}
}

void	sl_move_player(t_game *game)
{
	t_fvec	acc;

	acc.x = game->movement_input.x * PLAYER_ACCELERATION_FORCE;
	acc.y = game->movement_input.y * PLAYER_ACCELERATION_FORCE;
	game->player_vel.x += acc.x * game->delta_time;
	game->player_vel.y += acc.y * game->delta_time;
	bounce(game);
	game->player_vel.x *= PLAYER_DRAG_AMOUNT;
	game->player_vel.y *= PLAYER_DRAG_AMOUNT;
}
