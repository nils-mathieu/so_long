/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:22:58 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/17 16:33:20 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

void	sl_render_game(t_game *game)
{
	size_t	i;

	ft_mem_set(game->canvas.addr, 0, HEIGHT * game->canvas.line_len);
	sl_put_image(&game->canvas, (t_upos){(uint32_t)(game->player_pos.x * 24.0) - 12, (uint32_t)(game->player_pos.y * 24.0) - 12}, &game->images[SL_GIMG_PLAYER], (t_rect){0, 0, 32, 32});
	i = 0;
	while (i < game->wall_count)
	{
		i++;
		sl_put_image(&game->canvas, (t_upos){game->walls[i].x * 24, game->walls[i].y * 24}, &game->images[SL_GING_WALL], (t_rect){0,0,24,24});
	}
	mlx_put_image_to_window(game->mlx, game->win, game->canvas.image, 0, 0);
	char s[64];
	sprintf(s, "%.2f FPS", 1.0 / game->delta_time);
	mlx_string_put(game->mlx, game->win, 100, 100, 0xffffffff, s);
}
