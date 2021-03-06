/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:14:16 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/26 15:32:24 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_explosion(t_upos pos, t_game *g)
{
	pos.x -= 22;
	pos.y -= 22;
	sl_put_image(
		g, (t_rect){pos.x, pos.y, 90, 90},
		&g->images[SL_GIMG_EXPLOSION],
		(t_srect){90 * g->lvl.explosion_anim_frame, 0, 90, 90, 0, 0});
}

static void	render_shield(t_upos pos, t_game *g)
{
	pos.x -= 16;
	pos.y -= 16;
	sl_put_image(
		g, (t_rect){pos.x, pos.y, 64, 64},
		&g->images[SL_GIMG_SHIELD],
		(t_srect){64 * g->lvl.shield_anim_frame, 0, 64, 64, 0, 0});
}

void	sl_render_player(t_game *g)
{
	t_upos	pos;

	pos = sl_pos_to_screen(g, g->lvl.player_pos);
	if (g->lvl.explosion)
		render_explosion(pos, g);
	if (g->lvl.game_state != SL_GS_PLAYING)
		return ;
	pos.x -= 16;
	pos.y -= 16;
	sl_put_image(
		g, (t_rect){pos.x, pos.y, 32, 32},
		&g->images[SL_GIMG_PLAYER],
		(t_srect){32 * g->lvl.player_anim_frame, 32
			* g->lvl.player_dir, 32, 32, 0, 0});
	if (g->lvl.shield)
		render_shield(pos, g);
}
