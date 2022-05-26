/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:47:46 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/26 14:58:02 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	sl_print_map_error(t_map_parser *p)
{
	ft_fmt_err("Error\n");
	if (p->map->width == 0 || p->map->height == 0)
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
	if (p->map->player_count == 0)
		ft_fmt_err(" - no player start position\n");
	if (p->map->coin_count == 0)
		ft_fmt_err(" - no coins found on the map\n");
	if (p->map->exit_count == 0)
		ft_fmt_err(" - no exit found\n");
}
