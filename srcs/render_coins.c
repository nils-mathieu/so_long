/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_coins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:39:40 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/25 12:45:35 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_render_coins(t_game *game)
{
	size_t	i;
	t_upos	pos;

	i = 0;
	while (i < game->lvl.rem_coins)
	{
		pos = sl_pos_to_screen(game, game->lvl.coins[i].pos);
		pos.x -= 10;
		pos.y -= 10;
		sl_put_image(
			game, (t_rect){pos.x, pos.y, 20, 20}, &game->images[SL_GIMG_COIN],
			(t_srect){20 * game->lvl.coins[i].frame, 0, 20, 20, 0, 0});
		i++;
	}
}
