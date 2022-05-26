/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map->c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:04:15 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 19:41:13 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 4096

static bool	is_enclosed(t_map_parser *p)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < p->map->wall_count)
	{
		if (p->map->walls[i].x == 0
			|| p->map->walls[i].x == p->map->width - 1
			|| p->map->walls[i].y == 0
			|| p->map->walls[i].y == p->map->height - 1)
			count++;
		i++;
	}
	return (count == (p->map->width - 1) * 2 + (p->map->height - 1) * 2);
}

// Determines whether the provided parser references a valid map or not,
// checking whether it is properly enclosed on its way.
static bool	final_map_check(t_map_parser *p)
{
	if (p->is_rectangle && p->map->width != 0 && p->map->height != 0)
		p->is_enclosed = is_enclosed(p);
	return (
		p->is_enclosed && p->is_rectangle && p->map->exit_count >= 1
		&& p->map->coin_count != 0 && p->map->player_count >= 1
		&& !p->contains_invalid_character && p->map->width != 0
		&& p->map->height != 0);
}

static void	new_line(t_map_parser *p)
{
	if (p->map->height == 0)
		p->map->width = p->line_len;
	else if (p->map->width != p->line_len)
		p->is_rectangle = false;
	p->map->height++;
	p->line_len = 0;
}

void	sl_free_map_parser(t_map_parser *p)
{
	if (p->coins_cap != 0)
		free(p->map->coins);
	if (p->walls_cap != 0)
		free(p->map->walls);
	if (p->exits_cap != 0)
		free(p->map->exits);
	if (p->players_cap != 0)
		free(p->map->players);
}

t_perr	sl_parse_map(int fd, t_map_parser *p, t_map *map)
{
	uint8_t		buffer[BUF_SIZE];
	uint8_t		byte;
	t_reader	reader;
	t_rdres		res;

	ft_mem_set(p, 0x00, sizeof(t_map_parser));
	p->is_rectangle = true;
	p->map = map;
	reader = (t_reader){fd, (t_buffer){buffer, 0, BUF_SIZE}, 0};
	while (true)
	{
		res = ft_read_byte(&reader, &byte);
		if (res == FT_RDRES_ERROR)
			return (SL_PERR_CANT_READ);
		if (res == FT_RDRES_DONE)
			break ;
		if (!sl_parse_byte(byte, p))
			return (SL_PERR_OUT_OF_MEMORY);
	}
	if (p->line_len != 0)
		new_line(p);
	if (final_map_check(p))
		return (SL_PERR_SUCCESS);
	else
		return (SL_PERR_INVALID_MAP);
}
