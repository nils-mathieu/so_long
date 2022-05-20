/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:24:36 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/20 17:04:32 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static size_t	render_number(t_game *g, uint32_t num, t_upos pos)
{
	char	buf[10];
	char	*cur;
	size_t	i;

	cur = ft_uint32_to_str(num, (t_str){"0123456789", 10}, buf + 10);
	i = 0;
	while (cur + i < buf + 10)
	{
		sl_put_image(
			g, (t_rect){pos.x + 17 * i, pos.y, 17, 27},
			&g->images[SL_GIMG_NUMBERS],
			(t_srect){17 * (cur[i] - '0'), 0, 17, 27, 0, 0});
		i++;
	}
	return (i);
}

void	sl_render_move_count(t_game *g)
{
	size_t	count;

	render_number(g, g->move_count, (t_upos){10, 10});
	count = 0;
	count += render_number(g, g->enemy_count, (t_upos){10, 50});
	sl_put_image(
		g, (t_rect){10 + 17 * count++, 50, 17, 27},
		&g->images[SL_GIMG_NUMBERS],
		(t_srect){17 * 10, 0, 17, 27, 0, 0});
	render_number(g, g->enemy_count + g->rem_coins,
		(t_upos){10 + 17 * count, 50});
}
