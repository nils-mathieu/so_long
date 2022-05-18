/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_portal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:46:26 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 17:58:05 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_render_portal(t_fpos camera, t_game *game)
{
	t_upos	pos;

	if (game->rem_coins != 0)
		return ;
	pos = sl_pos_to_screen(camera, game->exit);
	pos.x -= 50;
	pos.y -= 50;
	sl_put_image(
		game, (t_rect){pos.x, pos.y, 100, 100},
		&game->images[SL_GIMG_EXIT],
		(t_srect){game->exit_anim_frame * 100, 0, 100, 100, 0, 0});
}
