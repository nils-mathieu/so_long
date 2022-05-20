/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:34:28 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/20 17:50:55 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static void	clamp_one_d(int32_t *x, int32_t *width, int32_t *src, int32_t bound)
{
	if (*x + *width < 0)
		*width = 0;
	else if (*x < 0 && *x + *width >= 0)
	{
		*width = *x + *width;
		*src -= *x;
		*x = 0;
	}
	else if (*x < bound && *x + *width >= bound)
		*width = bound - *x;
	else if (*x >= bound)
		*width = 0;
}

inline static int32_t	mod_pos(int32_t i, int32_t m)
{
	return ((uint32_t)i % (uint32_t)m);
}

void	sl_put_image(t_game *game, t_rect dst, t_imgi *src_img, t_srect src)
{
	int32_t	x;
	int32_t	y;
	t_rgba	c;

	clamp_one_d(&dst.x, &dst.width, &src.x, WIDTH);
	clamp_one_d(&dst.y, &dst.height, &src.y, HEIGHT);
	y = 0;
	while (y < dst.height)
	{
		x = 0;
		while (x < dst.width)
		{
			c = *(t_rgba *)(
					src_img->addr
					+ src_img->line_len
					* (src.y + mod_pos(src.uv_y + y, src.height))
					+ 4 * (src.x + mod_pos(src.uv_x + x, src.width)));
			if (c.a != 0)
				*(t_rgba *)(game->canvas.addr + game->canvas.line_len
						* (dst.y + y) + 4 * (dst.x + x)) = c;
			x++;
		}
		y++;
	}
}

inline static void	add_colors(t_rgba *a, t_rgba b)
{
	a->r = a->r / 2 + b.r / 2;
	a->g = a->g / 2 + b.g / 2;
	a->b = a->b / 2 + b.b / 2;
}

void	sl_add_image(t_game *game, t_rect dst, t_imgi *simg, t_srect src)
{
	int32_t	x;
	int32_t	y;
	t_rgba	c;

	clamp_one_d(&dst.x, &dst.width, &src.x, WIDTH);
	clamp_one_d(&dst.y, &dst.height, &src.y, HEIGHT);
	y = 0;
	while (y < dst.height)
	{
		x = 0;
		while (x < dst.width)
		{
			c = *(t_rgba *)(
					simg->addr
					+ simg->line_len
					* (src.y + mod_pos(src.uv_y + y, src.height))
					+ 4 * (src.x + mod_pos(src.uv_x + x, src.width)));
			if (c.a != 0)
				add_colors((t_rgba *)(game->canvas.addr + game->canvas.line_len
						* (dst.y + y) + 4 * (dst.x + x)), c);
			x++;
		}
		y++;
	}
}
