/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 08:29:15 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/14 09:46:22 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void	destroy_images(t_game *g)
{
	size_t	i;

	i = 0;
	while (i < IMAGE_COUNT)
		mlx_destroy_image(g->mlx, g->images[i++]);
}

static t_gerr	init_game(t_game *g, t_tile *tiles, uint32_t w, uint32_t h)
{
	(void)tiles;
	g->mlx = mlx_init();
	if (!g->mlx)
		return (SL_GERR_MLX);
	if (!sl_load_images(g->mlx, g->images))
		return (mlx_destroy_display(g->mlx), free(g->mlx), SL_GERR_IMAGE);
	g->win = mlx_new_window(g->mlx, 1280, 720, "So Long");
	if (!g->win)
		return (
			destroy_images(g),
			mlx_destroy_display(g->mlx), free(g->mlx),
			SL_GERR_MLX);
	g->width = w;
	g->height = h;
	g->sprites_cap = 0;
	g->sprites_len = 0;
	return (SL_GERR_SUCCESS);
}

static void	deinit_game(t_game *game)
{
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

t_gerr	sl_game_start(t_tile *tiles, uint32_t width, uint32_t height)
{
	t_game	game;
	t_gerr	err;

	err = init_game(&game, tiles, width, height);
	if (err != SL_GERR_SUCCESS)
		return (err);
	deinit_game(&game);
	return (SL_GERR_SUCCESS);
}
