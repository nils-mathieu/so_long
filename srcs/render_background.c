/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:42:28 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 17:50:05 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		sl_render_background(t_fpos camera, t_game *game)
{
	(void)camera;
	sl_put_image(
		game,
		(t_rect){0, 0, WIDTH, HEIGHT},
		&game->images[SL_GIMG_BACKGROUND],
		(t_srect){0, 0, 512, 512, 0, 0});
}
