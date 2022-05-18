/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:14:16 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 17:58:34 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_render_player(t_fpos camera, t_game *g)
{
	t_upos	pos;

	pos = sl_pos_to_screen(camera, g->player_pos);
	pos.x -= 16;
	pos.y -= 16;
	sl_put_image(
		g, (t_rect){pos.x, pos.y, 32, 32},
		&g->images[SL_GIMG_PLAYER],
		(t_srect){32 * g->player_anim_frame, 32 * g->player_dir, 32, 32, 0, 0});
}
