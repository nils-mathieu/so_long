/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:20:48 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/26 15:20:00 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static void	print_gerr(t_gerr err)
{
	if (err == SL_GERR_MLX)
		ft_fmt_err("Failed to initialize the MiniLibX.\n");
	if (err == SL_GERR_IMAGE)
		ft_fmt_err("Unsupported image/X11 server.\n");
	if (err == SL_GERR_OOM)
		ft_fmt_err("The system is out of memory.\n");
	if (err == SL_GERR_RNG)
		ft_fmt_err("Cannot read '/dev/urandom'.\n");
}

int	main(int argc, const char *const *argv)
{
	t_gerr			gerr;
	t_map			*maps;
	size_t			map_count;

	if (argc < 2)
		return (ft_fmt_err("Usage: ./so_long <map_file.ber> ...\n"), 1);
	map_count = (size_t)argc - 1;
	maps = sl_load_maps(argv + 1, map_count);
	if (!maps)
		return (1);
	gerr = sl_game_start(maps, map_count);
	sl_free_maps(maps, argc - 1);
	if (gerr != SL_GERR_SUCCESS)
		return (print_gerr(gerr), 1);
	return (0);
}
