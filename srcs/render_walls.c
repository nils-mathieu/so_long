/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:07:47 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/25 12:47:49 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_render_walls(t_game *game)
{
	size_t	i;
	t_upos	pos;

	i = 0;
	while (i < game->lvl.wall_count)
	{
		pos = sl_pos_to_screen(game, game->lvl.walls[i].pos);
		pos.x -= 16;
		pos.y -= 16;
		sl_put_image(
			game, (t_rect){pos.x, pos.y, 32, 32},
			&game->images[SL_GIMG_WALL],
			(t_srect){32 * game->lvl.walls[i].tile, 0, 32, 32, 0, 0});
		i++;
	}
}
