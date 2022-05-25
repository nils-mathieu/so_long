/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:49:51 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/25 12:33:34 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <math.h>

#define UP_KEYSYM 119
#define DOWN_KEYSYM 115
#define LEFT_KEYSYM 97
#define RIGHT_KEYSYM 100
#define ESCAPE_KEYSYM 65307

int	sl_destroy_hook(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

static void	recompute_movement_input(t_game *game)
{
	float	inv_len;

	game->lvl.movement_input = (t_fvec){0.0, 0.0};
	if (game->lvl.pressing_up)
		game->lvl.movement_input.y -= 1.0;
	if (game->lvl.pressing_left)
		game->lvl.movement_input.x -= 1.0;
	if (game->lvl.pressing_down)
		game->lvl.movement_input.y += 1.0;
	if (game->lvl.pressing_right)
		game->lvl.movement_input.x += 1.0;
	if (game->lvl.movement_input.x != 0.0 || game->lvl.movement_input.y != 0.0)
	{
		inv_len = 1.0 / sqrtf(
				game->lvl.movement_input.x * game->lvl.movement_input.x
				+ game->lvl.movement_input.y * game->lvl.movement_input.y);
		game->lvl.movement_input.x *= inv_len;
		game->lvl.movement_input.y *= inv_len;
	}
}

int	sl_key_press_hook(unsigned long keysym, t_game *game)
{
	if (keysym == UP_KEYSYM)
		game->lvl.pressing_up = true;
	else if (keysym == LEFT_KEYSYM)
		game->lvl.pressing_left = true;
	else if (keysym == DOWN_KEYSYM)
		game->lvl.pressing_down = true;
	else if (keysym == RIGHT_KEYSYM)
		game->lvl.pressing_right = true;
	recompute_movement_input(game);
	sl_update_player_dir(game);
	return (0);
}

int	sl_key_release_hook(unsigned long keysym, t_game *game)
{
	if (keysym == ESCAPE_KEYSYM)
		return (mlx_loop_end(game->mlx));
	else if (keysym == UP_KEYSYM)
		game->lvl.pressing_up = false;
	else if (keysym == LEFT_KEYSYM)
		game->lvl.pressing_left = false;
	else if (keysym == DOWN_KEYSYM)
		game->lvl.pressing_down = false;
	else if (keysym == RIGHT_KEYSYM)
		game->lvl.pressing_right = false;
	recompute_movement_input(game);
	sl_update_player_dir(game);
	return (0);
}

int	sl_loop_hook(t_game *game)
{
	sl_move_player(game);
	sl_update_enemies(game);
	sl_count_movements(game);
	sl_update_camera(game);
	sl_collect_coins(game);
	sl_finish(game);
	sl_animate_player(game);
	sl_animate_enemies(game);
	sl_animate_coins(game);
	sl_animate_exit(game);
	sl_animate_explosion(game);
	sl_animate_shield(game);
	sl_render_game(game);
	return (0);
}
