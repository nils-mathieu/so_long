/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:34:28 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 15:38:36 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

inline static void	clamp_to_window(t_rect *dst, t_rect *src)
{
	(void)src;
	if (dst->x < WIDTH && dst->x + dst->width >= WIDTH)
		dst->width = WIDTH - dst->x;
	else if (dst->x >= WIDTH && dst->x + dst->width >= WIDTH)
		dst->width = 0;
	else if (dst->x >= WIDTH && dst->x + dst->width < WIDTH)
		dst->width = dst->x + dst->width;
	if (dst->y < HEIGHT && dst->y + dst->height >= HEIGHT)
		dst->height = HEIGHT - dst->y;
	else if (dst->y >= HEIGHT && dst->y + dst->height >= HEIGHT)
		dst->height = 0;
	else if (dst->y >= HEIGHT && dst->y + dst->height < HEIGHT)
		dst->height = dst->y + dst->height;
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

void	sl_put_image(t_game *game, t_rect dst, t_imgi *src_img, t_rect src)
{
	uint32_t	x;
	uint32_t	y;
	t_rgba		c;

	clamp_to_window(&dst, &src);
	y = 0;
	while (y < dst.height)
	{
		x = 0;
		while (x < dst.width)
		{
			c = *(t_rgba *)(
					src_img->addr
					+ src_img->line_len * (src.y + y % src.height)
					+ 4 * (src.x + x % src.width));
			if (c.a != 0)
				*(t_rgba *)(game->canvas.addr + game->canvas.line_len
						* (dst.y + y) + 4 * (dst.x + x)) = c;
			x++;
		}
		y++;
	}
}
