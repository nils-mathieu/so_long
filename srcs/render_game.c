/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:22:58 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 13:49:38 by nmathieu         ###   ########.fr       */
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
	ft_mem_set(game->canvas.addr, 0x00, game->canvas.line_len * HEIGHT);
	sl_render_background(camera, game);
	sl_render_coins(camera, game);
	sl_render_portal(camera, game);
	sl_render_enemies(camera, game);
	sl_render_player(camera, game);
	sl_render_walls(camera, game);
	sl_render_move_count(game);
	mlx_put_image_to_window(game->mlx, game->win, game->canvas.image, 0, 0);
	mlx_do_sync(game->mlx);
}
