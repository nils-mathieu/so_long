/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:39:34 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/20 17:50:39 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

static t_fvec	compute_disp_for(t_fvec vel, t_fpos wall, t_fpos p)
{
	t_fvec	disp;

	if (vel.x < 0.0f)
		disp.x = (wall.x + 0.5f) - (p.x - PLAYER_COL_W * 0.5f);
	else
		disp.x = wall.x - 0.5f - (p.x + PLAYER_COL_W * 0.5f);
	if (vel.y < 0.0f)
		disp.y = (wall.y + 0.5f) - (p.y - PLAYER_COL_H * 0.5f);
	else
		disp.y = wall.y - 0.5f - (p.y + PLAYER_COL_H * 0.5f);
	if (fabsf(disp.x) < fabsf(disp.y))
		disp.y = 0.0;
	else
		disp.x = 0.0;
	return (disp);
}

static t_fvec	compute_disp(t_fvec vel, t_wall *walls, size_t n, t_fpos p)
{
	t_fvec	max_disp;
	t_fvec	disp;
	size_t	i;

	max_disp.x = 0.0;
	max_disp.y = 0.0;
	i = 0;
	while (i < n)
	{
		if (
			p.y + PLAYER_COL_H * 0.5f >= walls[i].pos.y - 0.5f
			&& p.x + PLAYER_COL_W * 0.5f >= walls[i].pos.x - 0.5f
			&& p.x - PLAYER_COL_W * 0.5f <= walls[i].pos.x + 0.5f
			&& p.y - PLAYER_COL_H * 0.5f <= walls[i].pos.y + 0.5f)
		{
			disp = compute_disp_for(vel, walls[i].pos, p);
			if (fabsf(disp.y) > max_disp.y)
				max_disp.y = disp.y;
			if (fabsf(disp.x) > max_disp.x)
				max_disp.x = disp.x;
		}
		i++;
	}
	return (max_disp);
}

static void	bounce_event(t_game *game)
{
	game->recoil_duration = RECOIL_DURATION;
	game->shield = true;
	game->shield_anim_frame = 5;
	game->next_shield_anim_frame = SHIELD_ANIM_SPEED;
}

static void	bounce(t_game *g)
{
	t_fvec	disp;

	g->player_pos.x += g->player_vel.x * DELTA_TIME;
	g->player_pos.y += g->player_vel.y * DELTA_TIME;
	disp = compute_disp(g->player_vel, g->walls, g->wall_count, g->player_pos);
	g->player_pos.x += disp.x * PHYSICS_ROOM;
	g->player_pos.y += disp.y * PHYSICS_ROOM;
	if (fabsf(disp.x) < fabsf(disp.y) - 0.001)
	{
		if (g->player_vel.y < 0.0)
			g->player_vel.y = BOUNCE_AMOUNT;
		else
			g->player_vel.y = -BOUNCE_AMOUNT;
		bounce_event(g);
	}
	else if (fabsf(disp.x) > fabsf(disp.y) + 0.001)
	{
		if (g->player_vel.x < 0.0)
			g->player_vel.x = BOUNCE_AMOUNT;
		else
			g->player_vel.x = -BOUNCE_AMOUNT;
		bounce_event(g);
	}
}

void	sl_move_player(t_game *game)
{
	t_fvec	acc;

	if (game->no_player)
		return ;
	if (game->recoil_duration <= 0.0f)
	{
		acc.x = game->movement_input.x * PLAYER_ACCELERATION_FORCE;
		acc.y = game->movement_input.y * PLAYER_ACCELERATION_FORCE;
	}
	else
	{
		game->recoil_duration -= DELTA_TIME;
		acc = (t_fvec){0.0f, 0.0f};
	}
	game->player_vel.x += acc.x * DELTA_TIME;
	game->player_vel.y += acc.y * DELTA_TIME;
	bounce(game);
	game->player_vel.x *= PLAYER_DRAG_AMOUNT;
	game->player_vel.y *= PLAYER_DRAG_AMOUNT;
}
