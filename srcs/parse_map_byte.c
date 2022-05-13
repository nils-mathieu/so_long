/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_byte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:07:19 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/14 01:16:57 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>

static bool	grow(t_map_parser *p)
{
	t_tile	*new;

	new = ft_alloc_array(p->cap + 4, 2 * sizeof(t_map_parser));
	if (!new)
		return (false);
	if (p->cap != 0)
	{
		ft_mem_copy(new, p->tiles, p->cap * sizeof(t_map_parser));
		free(p->tiles);
	}
	p->tiles = new;
	p->cap = (p->cap + 4) * 2;
	return (true);
}

static void	new_line(t_map_parser *p)
{
	if (p->height == 0)
		p->width = p->line_len;
	else if (p->width != p->line_len)
		p->is_rectangle = false;
	p->height++;
	p->line_len = 0;
}

static void	push_and_add(t_map_parser *p, t_tile tile, uint32_t *count)
{
	p->tiles[p->width * p->height + p->line_len++] = tile;
	(*count)++;
}

bool	sl_parse_byte(uint8_t byte, t_map_parser *p)
{
	if (byte == '\n')
		return (new_line(p), true);
	if (p->height * p->width + p->line_len == p->cap && !grow(p))
		return (false);
	if (byte == '0')
		p->tiles[p->width * p->height + p->line_len++] = SL_TILE_FLOOR;
	else if (byte == '1')
		p->tiles[p->width * p->height + p->line_len++] = SL_TILE_WALL;
	else if (byte == 'C')
		push_and_add(p, SL_TILE_COIN, &p->coins);
	else if (byte == 'E')
		push_and_add(p, SL_TILE_EXIT, &p->exits);
	else if (byte == 'P')
		push_and_add(p, SL_TILE_PLAYER, &p->players);
	else
	{
		p->contains_invalid_character = true;
		p->invalid_character = byte;
	}
	return (true);
}
