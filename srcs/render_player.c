/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:14:16 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/17 22:15:31 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_render_player(t_fpos camera, t_game *game)
{
	t_upos	pos;

	pos = sl_pos_to_screen(camera, game->player_pos);
	pos.x -= 16;
	pos.y -= 16;
	sl_put_image(
		game, pos,
		&game->images[SL_GIMG_PLAYER], (t_rect){0, 0, 32, 32});
}
