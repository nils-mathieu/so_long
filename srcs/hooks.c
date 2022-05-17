/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:49:51 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/17 18:08:35 by nmathieu         ###   ########.fr       */
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

	game->movement_input = (t_fvec){0.0, 0.0};
	if (game->pressing_up)
		game->movement_input.y -= 1.0;
	if (game->pressing_left)
		game->movement_input.x -= 1.0;
	if (game->pressing_down)
		game->movement_input.y += 1.0;
	if (game->pressing_right)
		game->movement_input.x += 1.0;
	if (game->movement_input.x != 0.0 || game->movement_input.y != 0.0)
	{
		inv_len = 1.0 / sqrtf(
				game->movement_input.x * game->movement_input.x
				+ game->movement_input.y * game->movement_input.y);
		game->movement_input.x *= inv_len;
		game->movement_input.y *= inv_len;
	}
}

int	sl_key_press_hook(unsigned long keysym, t_game *game)
{
	if (keysym == UP_KEYSYM)
		game->pressing_up = true;
	else if (keysym == LEFT_KEYSYM)
		game->pressing_left = true;
	else if (keysym == DOWN_KEYSYM)
		game->pressing_down = true;
	else if (keysym == RIGHT_KEYSYM)
		game->pressing_right = true;
	recompute_movement_input(game);
	return (0);
}

int	sl_key_release_hook(unsigned long keysym, t_game *game)
{
	if (keysym == ESCAPE_KEYSYM)
		return (mlx_loop_end(game->mlx));
	else if (keysym == UP_KEYSYM)
		game->pressing_up = false;
	else if (keysym == LEFT_KEYSYM)
		game->pressing_left = false;
	else if (keysym == DOWN_KEYSYM)
		game->pressing_down = false;
	else if (keysym == RIGHT_KEYSYM)
		game->pressing_right = false;
	recompute_movement_input(game);
	return (0);
}

int	sl_loop_hook(t_game *game)
{
	game->delta_time = sl_delta_time(&game->frame_last_instant);
	sl_move_player(game);
	sl_render_game(game);
	return (0);
}
