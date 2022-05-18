/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:12:52 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 02:00:55 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	sl_update_camera(t_game *game)
{
	game->camera_pos.x = sl_lerp(
			game->camera_pos.x, game->player_pos.x, CAMERA_SPEED);
	game->camera_pos.y = sl_lerp(
			game->camera_pos.y, game->player_pos.y, CAMERA_SPEED);
}

t_fpos	sl_camera_pos(t_game *game)
{
	return (game->camera_pos);
}

t_upos	sl_pos_to_screen(t_fpos camera, t_fpos pos)
{
	pos.x -= camera.x;
	pos.y -= camera.y;
	pos.x *= PIXELS_PER_UNIT;
	pos.y *= PIXELS_PER_UNIT;
	return ((t_upos){
		(uint32_t)pos.x + WIDTH / 2,
		(uint32_t)pos.y + HEIGHT / 2
	});
}
