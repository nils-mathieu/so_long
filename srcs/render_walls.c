/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:07:47 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 15:33:33 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_render_walls(t_fpos camera, t_game *game)
{
	size_t	i;
	t_upos	pos;

	i = 0;
	while (i < game->wall_count)
	{
		pos = sl_pos_to_screen(camera, game->walls[i].pos);
		pos.x -= 16;
		pos.y -= 16;
		sl_put_image(
			game, (t_rect){pos.x, pos.y, 32, 32},
			&game->images[SL_GIMG_WALL],
			(t_rect){32 * game->walls[i].tile, 0, 32, 32});
		i++;
	}
}
