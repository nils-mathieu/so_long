/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_coins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:39:40 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 02:15:00 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_render_coins(t_fpos camera, t_game *game)
{
	size_t	i;
	t_upos	pos;

	i = 0;
	while (i < game->rem_coins)
	{
		pos = sl_pos_to_screen(camera, game->coins[i].pos);
		pos.x -= 10;
		pos.y -= 10;
		sl_put_image(
			game, pos, &game->images[SL_GIMG_COIN],
			(t_rect){0, 0, 20, 20});
		i++;
	}
}
