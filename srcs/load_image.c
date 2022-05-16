/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:06:36 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 19:14:30 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"

inline static bool	fill_addr(t_imgi *result)
{
	int	bpp;
	int	endian;

	result->addr = (uint8_t *)mlx_get_data_addr(
			result->image,
			&bpp,
			(int *)&result->line_len,
			&endian);
	ft_dbg("{i} bits per pixel | big endian: {b}\n", bpp, endian);
	return (result->addr && bpp == 32 && endian == 0);
}

bool	sl_create_image(t_mlx mlx, uint32_t w, uint32_t h, t_imgi *result)
{
	result->image = mlx_new_image(mlx, w, h);
	if (!result->image)
		return (false);
	ft_dbg("Creating image... ");
	return (fill_addr(result));
}

bool	sl_load_image(t_mlx mlx, const char *s, t_imgi *result)
{
	int	w;
	int	h;

	ft_dbg("Loading image '{s}'... ", s);
	result->image = mlx_xpm_file_to_image(mlx, (char *)s, &w, &h);
	if (!result->image)
		return (false);
	return (fill_addr(result));
}
