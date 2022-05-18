/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 03:02:22 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 13:21:51 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_animate_exit(t_game *game)
{
	if (game->rem_coins != 0)
		return ;
	if (game->next_exit_anim_frame <= 0.0)
	{
		game->exit_anim_frame++;
		if (game->exit_anim_frame == 42)
			game->exit_anim_frame = 0;
		game->next_exit_anim_frame = EXIT_ANIM_SPEED;
	}
	else
		game->next_exit_anim_frame -= game->delta_time;
}
