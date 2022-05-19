/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:15:49 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 19:40:49 by nmathieu         ###   ########.fr       */
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
	return (t_fpos){(float)pos.x, (float)pos.y};
}

bool	sl_init_game(t_game *g, t_map *map)
{
	g->width = map->width;
	g->height = map->height;
	g->player_pos = random_pos(g, map->players, map->player_count);
	g->camera_pos = g->player_pos;
	g->frame_last_instant = sl_get_current_timestamp();
	g->walls = sl_create_wall_array(map->walls, map->wall_count);
	if (!g->walls)
		return (false);
	g->wall_count = map->wall_count;
	g->coins = create_coin_array(g, map->coins, map->coin_count);
	if (!g->coins)
		return (free(g->walls), false);
	g->enemies = ft_alloc_array(map->coin_count, sizeof(t_enemy));
	if (!g->enemies)
		return (free(g->walls), free(g->coins), false);
	g->enemy_count = 0;
	g->rem_coins = map->coin_count;
	g->max_coins = map->coin_count;
	g->exit = random_pos(g, map->exits, map->exit_count);
	g->rem_dist = 1.0f;
	return (true);
}
