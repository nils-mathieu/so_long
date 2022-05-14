/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:32:03 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/14 09:43:16 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static const char	**pathes(void)
{
	static const char	*pathes[IMAGE_COUNT] = {
		"imgs/player.xpm",
		"imgs/exit.xpm",
		"imgs/coin.xpm",
	};

	return (pathes);
}

bool	sl_load_images(t_mlx mlx, t_img *images)
{
	size_t				i;
	int					w;
	int					h;

	i = 0;
	while (i < IMAGE_COUNT)
	{
		images[i] = mlx_xpm_file_to_image(mlx, (char *)pathes()[i], &w, &h);
		if (!images[i])
		{
			while (i)
				mlx_destroy_image(mlx, images[--i]);
			return (false);
		}
		i++;
	}
	return (true);
}
