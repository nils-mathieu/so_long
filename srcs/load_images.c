/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:32:03 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/15 19:07:33 by nmathieu         ###   ########.fr       */
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
