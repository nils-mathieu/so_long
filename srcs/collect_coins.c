/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_coins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:26:36 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/17 18:52:02 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_collect_coins(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->rem_coins)
	{
		if (sl_sqdist(
			(t_fpos){(float)game->coins[i].x, (float)game->coins[i].y},
			game->player_pos) <= COIN_COL_R * COIN_COL_R)
		{
			game->coins[i] = game->coins[game->rem_coins - 1];
			game->rem_coins--;
		}
		else
			i++;
	}
}
