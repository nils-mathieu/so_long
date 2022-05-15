/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:34:28 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 00:16:32 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	sl_put_image(t_imgi *dst_img, t_upos dst, t_imgi *src_img, t_rect src)
{
	size_t	x;
	size_t	y;
	t_rgba	c;

	y = 0;
	while (y < src.height)
	{
		x = 0;
		while (x < src.width)
		{
			c = *(t_rgba *)(src_img->addr + src_img->line_len * (src.y + y)
					+ 4 * (src.x + x));
			if (c.a != 0)
				*(t_rgba *)(dst_img->addr + dst_img->line_len
						* (dst.y + y) + 4 * (dst.x + x)) = c;
			x++;
		}
		y++;
	}
}
