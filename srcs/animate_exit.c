/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 03:02:22 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/25 12:30:09 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_animate_exit(t_game *game)
{
	if (game->lvl.rem_coins != 0)
		return ;
	if (game->lvl.next_exit_anim_frame <= 0.0)
	{
		game->lvl.exit_anim_frame++;
		if (game->lvl.exit_anim_frame == 42)
			game->lvl.exit_anim_frame = 0;
		game->lvl.next_exit_anim_frame = EXIT_ANIM_SPEED;
	}
	else
		game->lvl.next_exit_anim_frame -= DELTA_TIME;
}
