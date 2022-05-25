/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_coins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:32:12 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/25 12:46:10 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_animate_coins(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->lvl.rem_coins)
	{
		if (game->lvl.coins[i].next_frame <= 0.0f)
		{
			game->lvl.coins[i].frame++;
			if (game->lvl.coins[i].frame == 8)
				game->lvl.coins[i].frame = 0;
			game->lvl.coins[i].next_frame = COINS_ANIM_SPEED;
		}
		else
			game->lvl.coins[i].next_frame -= DELTA_TIME;
		i++;
	}
}
