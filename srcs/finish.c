/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:41:31 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/17 18:52:43 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	sl_finish(t_game *game)
{
	if (game->rem_coins != 0)
		return ;
	if (sl_sqdist((t_fpos){(float)game->exit.x, (float)game->exit.y},
		game->player_pos) <= EXIT_COL_R * EXIT_COL_R)
	{
		mlx_loop_end(game->mlx);
	}
}
