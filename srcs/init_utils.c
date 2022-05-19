/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:15:49 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 14:00:42 by nmathieu         ###   ########.fr       */
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
		res[n].next_frame = COINS_ANIM_SPEED *
			(float)(uint8_t)sl_random(game) / 255.0f;
	}
	return (res);
}

static t_enemy	*create_enemy_array(t_game *game, t_upos *pos, size_t n)
{
	t_enemy	*res;

	(void)game;
	res = ft_alloc_array(n, sizeof(t_enemy));
	if (!res)
		return (NULL);
	while (n)
	{
		n--;
		res[n].pos.x = (float)pos[n].x;
		res[n].pos.y = (float)pos[n].y;
		res[n].vel = (t_fvec){0.0f, 0.0f};
	}
	return (res);
}

bool	sl_init_game(t_game *g, t_map *map)
{
	g->width = map->width;
	g->height = map->height;
	g->player_pos = (t_fpos){(float)map->player.x, (float)map->player.y};
	g->camera_pos = g->player_pos;
	g->frame_last_instant = sl_get_current_timestamp();
	g->walls = sl_create_wall_array(map->walls, map->wall_count);
	if (!g->walls)
		return (false);
	g->wall_count = map->wall_count;
	g->coins = create_coin_array(g, map->coins, map->coin_count);
	if (!g->coins)
		return (free(g->walls), false);
	g->enemies = create_enemy_array(g, map->enemies, map->enemies_count);
	if (!g->enemies)
		return (free(g->walls), free(g->coins), false);
	g->enemy_count = map->enemies_count;
	g->rem_coins = map->coin_count;
	g->max_coins = map->coin_count;
	g->exit = (t_fpos){(float)map->exit.x, (float)map->exit.y};
	g->rem_dist = 1.0f;
	return (true);
}
