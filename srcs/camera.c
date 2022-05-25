/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:12:52 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/25 12:49:43 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	sl_update_camera(t_game *game)
{
	game->lvl.camera.x = sl_lerp(
			game->lvl.camera.x, game->lvl.player_pos.x, CAMERA_SPEED);
	game->lvl.camera.y = sl_lerp(
			game->lvl.camera.y, game->lvl.player_pos.y, CAMERA_SPEED);
}

t_upos	sl_pos_to_screen(t_game *game, t_fpos pos)
{
	pos.x -= game->lvl.camera.x;
	pos.y -= game->lvl.camera.y;
	pos.x *= PIXELS_PER_UNIT;
	pos.y *= PIXELS_PER_UNIT;
	return ((t_upos){
		(uint32_t)pos.x + WIDTH / 2,
		(uint32_t)pos.y + HEIGHT / 2
	});
}
