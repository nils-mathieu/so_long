/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_coins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:32:12 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 02:41:24 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_animate_coins(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->rem_coins)
	{
		if (game->coins[i].next_frame <= 0.0f)
		{
			game->coins[i].frame++;
			if (game->coins[i].frame == 8)
				game->coins[i].frame = 0;
			game->coins[i].next_frame = COINS_ANIM_SPEED;
		}
		else
			game->coins[i].next_frame -= game->delta_time;
		i++;
	}
}
