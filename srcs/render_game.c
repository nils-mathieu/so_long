/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:22:58 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 19:19:20 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

void	sl_render_game(t_game *game)
{
	// size_t	i;

	ft_mem_set(game->canvas.addr, 0, HEIGHT * game->canvas.line_len);
	sl_put_image(&game->canvas, (t_upos){(uint32_t)(game->player_pos.x * 48.0), (uint32_t)(game->player_pos.y * 48.0)}, &game->images[SL_GIMG_PLAYER], (t_rect){0, 0, 32, 32});
	// i = 0;
	// while (i < game->wall_count)
	// {
	// 	i++;
	// 	sl_put_image(&game->canvas, (t_upos){game->walls[i].x * 48, game->walls[i].y * 48}, &game->images[SL_GING_WALL], (t_rect){0,0,48,48});
	// }
	mlx_put_image_to_window(game->mlx, game->win, game->canvas.image, 0, 0);
}
