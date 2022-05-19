/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:46:58 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 18:31:11 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static inline uint64_t	rotl(const uint64_t x, int k)
{
	return ((x << k) | (x >> (64 - k)));
}

// xoroshiro128+

uint64_t	sl_random(t_game *game)
{
	uint64_t	s0;
	uint64_t	s1;
	uint64_t	result;

	s0 = game->rng_state[0];
	s1 = game->rng_state[1];
	result = s0 + s1;
	s1 ^= s0;
	game->rng_state[0] = rotl(s0, 24) ^ s1 ^ (s1 << 16);
	game->rng_state[1] = rotl(s1, 37);
	return (result);
}
