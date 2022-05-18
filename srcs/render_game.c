/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:22:58 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 15:40:34 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

void	sl_render_game(t_game *game)
{
	t_fpos	camera;

	camera = sl_camera_pos(game);
	sl_put_image(game, (t_rect){0, 0, WIDTH, HEIGHT}, &game->images[SL_GIMG_BACKGROUND], (t_rect){0, 0, 512, 512});
	sl_render_coins(camera, game);
	sl_render_portal(camera, game);
	sl_render_player(camera, game);
	sl_render_walls(camera, game);
	mlx_put_image_to_window(game->mlx, game->win, game->canvas.image, 0, 0);
	mlx_do_sync(game->mlx);
}
