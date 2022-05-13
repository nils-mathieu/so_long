/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:47:46 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 23:17:30 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	sl_print_map_error(t_map_parser *p)
{
	ft_fmt_err("Error\n");
	if (p->width == 0 || p->height == 0)
	{
		ft_fmt_err(" - the map cannot be empty (obviously)\n");
		return ;
	}
	else if (!p->is_rectangle)
		ft_fmt_err(" - the map has to be rectangle\n");
	else if (!p->is_enclosed)
		ft_fmt_err(" - the map must be enclosed\n");
	if (p->contains_invalid_character)
		ft_fmt_err(" - invalid character: '{c?}'\n", p->invalid_character);
	if (p->players == 0)
		ft_fmt_err(" - no player start position\n");
	else if (p->players > 1)
		ft_fmt_err(" - only one player is allowed\n");
	if (p->coins == 0)
		ft_fmt_err(" - no coins found on the map\n");
	if (p->exits == 0)
		ft_fmt_err(" - no exit found\n");
	else if (p->exits > 1)
		ft_fmt_err(" - only one exit is alowed\n");
}
