/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 08:29:15 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 11:16:29 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	destroy_images(t_game *g)
{
	size_t	i;

	i = 0;
	while (i < IMAGE_COUNT)
		mlx_destroy_image(g->mlx, g->images[i++].image);
}

static t_gerr	init_game(t_game *g, t_map *map)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		return (SL_GERR_MLX);
	if (!sl_load_images(g->mlx, g->images))
		return (mlx_destroy_display(g->mlx), free(g->mlx), SL_GERR_IMAGE);
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "So Long");
	if (!g->win)
		return (
			destroy_images(g),
			mlx_destroy_display(g->mlx), free(g->mlx),
			SL_GERR_MLX);
	if (!sl_create_image(g->mlx, WIDTH, HEIGHT, &g->canvas))
		return (mlx_destroy_display(g->mlx), free(g->mlx), false);
	g->width = map->width;
	g->height = map->height;
	g->player_pos = (t_fpos){map->player.x, map->player.y};
	g->frame_last_instant = sl_get_current_timestamp();
	g->walls = map->walls;
	g->wall_count = map->wall_count;
	return (SL_GERR_SUCCESS);
}

static void	deinit_game(t_game *game)
{
	destroy_images(game);
	mlx_destroy_image(game->mlx, game->canvas.image);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

t_gerr	sl_game_start(t_map *map)
{
	t_game	game;
	t_gerr	err;

	ft_mem_set(&game, 0, sizeof(t_game));
	err = init_game(&game, map);
	if (err != SL_GERR_SUCCESS)
		return (err);
	mlx_hook(game.win, 17, 0, sl_destroy_hook, &game);
	mlx_hook(game.win, 2, 1 << 0, sl_key_press_hook, &game);
	mlx_hook(game.win, 3, 1 << 1, sl_key_release_hook, &game);
	mlx_loop_hook(game.mlx, sl_loop_hook, &game);
	mlx_loop(game.mlx);
	deinit_game(&game);
	return (SL_GERR_SUCCESS);
}
