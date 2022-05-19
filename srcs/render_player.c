/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:14:16 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 22:22:40 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_render_player(t_fpos camera, t_game *g)
{
	t_upos	player_pos;
	t_upos	pos;

	player_pos = sl_pos_to_screen(camera, g->player_pos);
	if (g->explosion)
	{
		pos = player_pos;
		pos.x -= 22;
		pos.y -= 22;
		sl_put_image(
			g, (t_rect){pos.x, pos.y, 90, 90},
			&g->images[SL_GIMG_EXPLOSION],
			(t_srect){90 * g->explosion_anim_frame, 0, 90, 90, 0, 0});
	}
	if (g->no_player)
		return ;
	pos = player_pos;
	pos.x -= 16;
	pos.y -= 16;
	sl_put_image(
		g, (t_rect){pos.x, pos.y, 32, 32},
		&g->images[SL_GIMG_PLAYER],
		(t_srect){32 * g->player_anim_frame, 32 * g->player_dir, 32, 32, 0, 0});
}
