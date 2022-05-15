/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:22:58 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 01:01:31 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

void	sl_render_game(t_game *game)
{
	ft_mem_set(game->canvas.addr, 0, HEIGHT * game->canvas.line_len);
	sl_put_image(&game->canvas, (t_upos){(uint32_t)(game->player_pos.x / 32.0), (uint32_t)(game->player_pos.y / 32.0)}, &game->images[SL_GIMG_PLAYER], (t_rect){0, 0, 32, 32});
	mlx_put_image_to_window(game->mlx, game->win, game->canvas.image, 0, 0);
}
