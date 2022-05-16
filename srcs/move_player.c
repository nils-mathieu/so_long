/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:39:34 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 17:53:26 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

// Determines whether the player collides with the given wall.
inline static bool	collides_with_wall(t_fpos wall, t_fpos pos)
{
	t_fpos	closest_point;

	closest_point.x = fmaxf(wall.x, fminf(pos.x + PLAYER_COL_X, wall.x + 1.0));
	closest_point.y = fmaxf(wall.y, fminf(pos.y + PLAYER_COL_Y, wall.y + 1.0));
	return (sl_sqdist(closest_point, pos) <= PLAYER_COL_R * PLAYER_COL_R);
}

static void	bounce(t_upos *walls, size_t n, t_fpos p, t_fvec *vel)
{
	return ;
	while (n)
	{
		if (collides_with_wall((t_fpos){(float)walls->x, (float)walls->y}, p))
		{
			if (vel->x > vel->y)
				vel->x = -vel->x * BOUNCE_AMOUNT;
			else
				vel->y = -vel->y * BOUNCE_AMOUNT;
		}
		n--;
		walls++;
	}
}

void	sl_move_player(t_game *game)
{
	t_fvec	acc;

	acc.x = game->movement_input.x * PLAYER_ACCELERATION_FORCE;
	acc.y = game->movement_input.y * PLAYER_ACCELERATION_FORCE;
	game->player_vel.x += acc.x * game->delta_time;
	game->player_vel.y += acc.y * game->delta_time;
	bounce(game->walls, game->wall_count, game->player_pos, &game->player_vel);
	game->player_pos.x += game->player_vel.x * game->delta_time;
	game->player_pos.y += game->player_vel.y * game->delta_time;
	game->player_vel.x *= PLAYER_DRAG_AMOUNT;
	game->player_vel.y *= PLAYER_DRAG_AMOUNT;
}
