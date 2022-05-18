/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:34:28 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 17:49:55 by nmathieu         ###   ########.fr       */
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
					+ src_img->line_len * (src.y + (src.uv_y + y) % src.height)
					+ 4 * (src.x + (src.uv_x + x) % src.width));
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
	t_rgba	r;

	r = (t_rgba){0xff, 0xff, 0xff, 0xff};
	if (b.r > UINT8_MAX - a->r)
		r.r = b.r + a->r;
	if (b.g > UINT8_MAX - a->g)
		r.g = b.g + a->g;
	if (b.r > UINT8_MAX - a->r)
		r.b = b.b + a->b;
	*a = r;
}

void	sl_add_image(t_game *game, t_rect dst, t_imgi *simg, t_srect src)
{
	int32_t	x;
	int32_t	y;
	t_rgba	c;

	// clamp_to_window(&dst, &src);
	y = 0;
	while (y < dst.height)
	{
		x = 0;
		while (x < dst.width)
		{
			c = *(t_rgba *)(
					simg->addr
					+ simg->line_len * (src.y + y % src.height)
					+ 4 * (src.x + x % src.width));
			if (c.a != 0)
				add_colors((t_rgba *)(game->canvas.addr + game->canvas.line_len
					* (dst.y + y) + 4 * (dst.x + x)), c);
			x++;
		}
		y++;
	}
}
