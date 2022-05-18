/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:24:36 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 20:32:24 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	sl_render_move_count(t_game *g)
{
	char	buf[10];
	char	*cur;
	size_t	i;

	cur = ft_uint32_to_str(g->move_count, (t_str){"0123456789", 10}, buf + 10);
	i = 0;
	while (cur + i < buf + 10)
	{
		sl_put_image(
			g, (t_rect){10 + 17 * i, 10, 17, 27},
			&g->images[SL_GIMG_NUMBERS],
			(t_srect){17 * (cur[i] - '0'), 0, 17, 27, 0, 0});
		i++;
	}
}
