/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:07:47 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/17 23:25:03 by nmathieu         ###   ########.fr       */
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
		pos = sl_pos_to_screen(camera, game->walls[i]);
		pos.x -= 12;
		pos.y -= 12;
		sl_put_image(
			game, pos,
			&game->images[SL_GING_WALL],
			(t_rect){0, 0, 24, 24});
		i++;
	}
}
