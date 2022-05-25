/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:42:28 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/25 12:51:21 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	paralax_bg(t_game *game, float amount)
{
	sl_add_image(
		game,
		(t_rect){0, 0, WIDTH, HEIGHT},
		&game->images[SL_GIMG_BACKGROUND],
		(t_srect){0, 0, 512, 512,
		game->lvl.camera.x * amount * PIXELS_PER_UNIT,
		game->lvl.camera.y * amount * PIXELS_PER_UNIT});
}

void	sl_render_background(t_game *game)
{
	sl_put_image(
		game,
		(t_rect){0, 0, WIDTH, HEIGHT},
		&game->images[SL_GIMG_BACKGROUND_LAYER_2],
		(t_srect){0, 0, 512, 512, game->lvl.camera.x * 0.02F * PIXELS_PER_UNIT,
		game->lvl.camera.y * 0.02f * PIXELS_PER_UNIT});
	paralax_bg(game, 0.1);
}
