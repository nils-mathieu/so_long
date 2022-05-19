/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:39:20 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 14:00:52 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_render_enemies(t_fpos camera, t_game *game)
{
	size_t	i;
	t_upos	pos;

	i = 0;
	while (i < game->enemy_count)
	{
		pos = sl_pos_to_screen(camera, game->enemies[i].pos);
		pos.x -= 16;
		pos.y -= 16;
		sl_put_image(
			game, (t_rect){pos.x, pos.y, 32, 32},
			&game->images[SL_GIMG_ENEMY],
			(t_srect){0, 0, 32, 32, 0, 0});
		i++;
	}
}
