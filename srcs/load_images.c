/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:32:03 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/15 23:21:14 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static const char	**pathes(void)
{
	static const char	*pathes[IMAGE_COUNT] = {
		"assets/spaceship.xpm",
		"assets/portal.xpm",
		"assets/spacecoin.xpm",
	};

	return (pathes);
}

bool	sl_load_images(t_mlx mlx, t_imgi *images)
{
	size_t	i;

	i = 0;
	while (i < IMAGE_COUNT)
	{
		if (!sl_load_image(mlx, (char *)pathes()[i], &images[i]))
		{
			while (i)
				mlx_destroy_image(mlx, images[--i].image);
			return (false);
		}
		i++;
	}
	return (true);
}