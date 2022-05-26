/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:41:31 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/26 15:32:10 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	sl_finish(t_game *game)
{
	if (game->lvl.rem_coins != 0)
		return ;
	if (sl_sqdist(game->lvl.exit,
			game->lvl.player_pos) <= EXIT_COL_R * EXIT_COL_R)
	{
		game->lvl.game_state = SL_GS_WON;
	}
}
