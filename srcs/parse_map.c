/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:04:15 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/14 01:04:12 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 4096

static bool	is_enclosed(t_map_parser *p)
{
	size_t	i;

	i = 0;
	while (i < p->width)
	{
		if (p->tiles[i] != SL_TILE_WALL)
			return (false);
		if (p->tiles[(p->height - 1) * p->width + i] != SL_TILE_WALL)
			return (false);
		i++;
	}
	i = 0;
	while (i < p->height)
	{
		if (p->tiles[i * p->width] != SL_TILE_WALL)
			return (false);
		if (p->tiles[p->width - 1 + i * p->width] != SL_TILE_WALL)
			return (false);
		i++;
	}
	return (true);
}

// Determines whether the provided parser references a valid map or not,
// checking whether it is properly enclosed on its way.
static bool	final_map_check(t_map_parser *p)
{
	if (p->is_rectangle && p->width != 0 && p->height != 0)
		p->is_enclosed = is_enclosed(p);
	return (
		p->is_enclosed && p->is_rectangle && p->players == 1
		&& p->coins != 0 && p->exits == 1 && !p->contains_invalid_character
		&& p->width != 0 && p->height != 0);
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

void	sl_free_map_parser(t_map_parser *p)
{
	if (p->cap != 0)
		free(p->tiles);
}

t_perr	sl_parse_map(int fd, t_map_parser *p)
{
	uint8_t		buffer[BUF_SIZE];
	uint8_t		byte;
	t_reader	reader;
	t_rdres		res;

	*p = (t_map_parser){0, 0, 0, true, false, false, 0, 0, 0, 0, 0, NULL};
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
