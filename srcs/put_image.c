/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:34:28 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 01:04:22 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

inline static void	clamp(t_upos *dst, t_rect *src)
{
	if (dst->x < WIDTH && dst->x + src->width >= WIDTH)
		src->width = WIDTH - dst->x;
	else if (dst->x >= WIDTH && dst->x + src->width >= WIDTH)
		src->width = 0;
	else if (dst->x >= WIDTH && dst->x + src->width < WIDTH)
		src->width = dst->x + src->width;
	if (dst->y < HEIGHT && dst->y + src->height >= HEIGHT)
		src->height = HEIGHT - dst->y;
	else if (dst->y >= HEIGHT && dst->y + src->height >= HEIGHT)
		src->height = 0;
	else if (dst->y >= HEIGHT && dst->y + src->height < HEIGHT)
		src->height = dst->y + src->height;
	if (dst->x >= WIDTH)
	{
		src->x = -dst->x;
		dst->x = 0;
	}
	if (dst->y >= HEIGHT)
	{
		src->y = -dst->y;
		dst->y = 0;
	}
}

void	sl_put_image(t_game *game, t_upos dst, t_imgi *src_img, t_rect src)
{
	uint32_t	x;
	uint32_t	y;
	t_rgba		c;

	clamp(&dst, &src);
	y = 0;
	while (y < src.height)
	{
		x = 0;
		while (x < src.width)
		{
			c = *(t_rgba *)(src_img->addr + src_img->line_len * (src.y + y)
					+ 4 * (src.x + x));
			if (c.a != 0)
				*(t_rgba *)(game->canvas.addr + game->canvas.line_len
						* (dst.y + y) + 4 * (dst.x + x)) = c;
			x++;
		}
		y++;
	}
}
