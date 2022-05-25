/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:22:58 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/25 12:48:56 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

void	sl_render_game(t_game *game)
{
	ft_mem_set(game->canvas.addr, 0x00, game->canvas.line_len * HEIGHT);
	sl_render_background(game);
	sl_render_coins(game);
	sl_render_portal(game);
	sl_render_walls(game);
	sl_render_enemies(game);
	sl_render_player(game);
	sl_render_move_count(game);
	mlx_put_image_to_window(game->mlx, game->win, game->canvas.image, 0, 0);
}
