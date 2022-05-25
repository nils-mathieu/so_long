/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:15:49 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/25 12:51:02 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>

static t_coin	*create_coin_array(t_game *game, t_upos *pos, size_t n)
{
	t_coin	*res;

	res = ft_alloc_array(n, sizeof(t_coin));
	if (!res)
		return (NULL);
	while (n)
	{
		n--;
		res[n].pos.x = (float)pos[n].x;
		res[n].pos.y = (float)pos[n].y;
		res[n].frame = sl_random(game) % 8;
		res[n].next_frame = COINS_ANIM_SPEED
			* (float)(uint8_t)sl_random(game) / 255.0f;
	}
	return (res);
}

inline static t_fpos	random_pos(t_game *game, t_upos *array, size_t n)
{
	t_upos	pos;

	pos = array[sl_random(game) % n];
	return ((t_fpos){(float)pos.x, (float)pos.y});
}

bool	sl_init_level(t_game *g, t_map *map)
{
	ft_mem_set(&g->lvl, 0x00, sizeof(t_level));
	g->lvl.player_pos = random_pos(g, map->players, map->player_count);
	g->lvl.camera = g->lvl.player_pos;
	g->lvl.walls = sl_create_wall_array(map->walls, map->wall_count);
	if (!g->lvl.walls)
		return (false);
	g->lvl.wall_count = map->wall_count;
	g->lvl.coins = create_coin_array(g, map->coins, map->coin_count);
	if (!g->lvl.coins)
		return (free(g->lvl.walls), false);
	g->lvl.enemies = ft_alloc_array(map->coin_count, sizeof(t_enemy));
	if (!g->lvl.enemies)
		return (free(g->lvl.walls), free(g->lvl.coins), false);
	g->lvl.enemy_count = 0;
	g->lvl.rem_coins = map->coin_count;
	g->lvl.max_coins = map->coin_count;
	g->lvl.exit = random_pos(g, map->exits, map->exit_count);
	g->lvl.rem_dist = 1.0f;
	return (true);
}

void	sl_deinit_level(t_level *level)
{
	free(level->walls);
	free(level->coins);
	free(level->enemies);
}
