/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_byte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:07:19 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 14:00:04 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>

static bool	grow(t_upos **data, size_t *cap)
{
	t_upos	*new;

	new = ft_alloc_array(*cap + 2, 2 * sizeof(t_map_parser));
	if (!new)
		return (false);
	if (*cap != 0)
	{
		ft_mem_copy(new, *data, *cap * sizeof(t_map_parser));
		free(*data);
	}
	*data = new;
	*cap = (*cap + 2) * 2;
	return (true);
}

static void	new_line(t_map_parser *p)
{
	if (p->map.height == 0)
		p->map.width = p->line_len;
	else if (p->map.width != p->line_len)
		p->is_rectangle = false;
	p->map.height++;
	p->line_len = 0;
}

static bool	push_and_add(t_upos **data, size_t *cap, size_t *len, t_upos pos)
{
	if (*len == *cap && !grow(data, cap))
		return (false);
	(*data)[*len] = pos;
	(*len)++;
	return (true);
}

bool	sl_parse_byte(uint8_t byte, t_map_parser *p)
{
	if (byte == '\n')
		return (new_line(p), true);
	if (byte == '0')
		return (p->line_len++, true);
	else if (byte == '1')
		return (push_and_add(&p->map.walls, &p->walls_cap, &p->map.wall_count,
				(t_upos){p->line_len++, p->map.height}));
	else if (byte == 'C')
		return (push_and_add(&p->map.coins, &p->coins_cap, &p->map.coin_count,
				(t_upos){p->line_len++, p->map.height}));
	else if (byte == 'E')
		return (p->map.exit = (t_upos){p->line_len++, p->map.height},
				p->exits++, true);
	else if (byte == 'P')
		return (p->map.player = (t_upos){p->line_len++, p->map.height},
				p->players++, true);
	else if (byte == 'X')
		return (push_and_add(&p->map.enemies, &p->enemies_cap,
			&p->map.enemies_count, (t_upos){p->line_len++, p->map.height}));
	p->contains_invalid_character = true;
	p->invalid_character = byte;
	p->line_len++;
	return (true);
}
