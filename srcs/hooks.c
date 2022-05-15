/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:49:51 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/15 19:06:10 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

#define UP_KEYSYM 119
#define DOWN_KEYSYM 119
#define LEFT_KEYSYM 97
#define RIGHT_KEYSYM 100
#define ESCAPE_KEYSYM 65307

int	sl_destroy_hook(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	sl_key_press_hook(unsigned long keysym, t_game *game)
{
	(void)keysym;
	(void)game;
	return (0);
}

int	sl_key_release_hook(unsigned long keysym, t_game *game)
{
	if (keysym == ESCAPE_KEYSYM)
		return (mlx_loop_end(game->mlx));
	return (0);
}
