/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:41:31 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 02:00:40 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	sl_finish(t_game *game)
{
	if (game->rem_coins != 0)
		return ;
	if (sl_sqdist(game->exit,
			game->player_pos) <= EXIT_COL_R * EXIT_COL_R)
	{
		mlx_loop_end(game->mlx);
	}
}
