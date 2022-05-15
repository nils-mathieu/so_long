/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:20:48 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/15 16:44:43 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_map_parser	p;
	t_perr			perr;
	int				fd;
	t_gerr			gerr;

	if (argc != 2)
		return (ft_fmt_err("Usage: ./so_long <map_file>\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_fmt_err("Open Error\n"), 1);
	perr = sl_parse_map(fd, &p);
	close(fd);
	if (perr == SL_PERR_CANT_READ)
		return (sl_free_map_parser(&p), ft_fmt_err("Read Error\n"), 1);
	if (perr == SL_PERR_OUT_OF_MEMORY)
		return (sl_free_map_parser(&p), ft_fmt_err("Out Of Memory\n"), 1);
	if (perr == SL_PERR_INVALID_MAP)
		return (sl_print_map_error(&p), sl_free_map_parser(&p), 1);
	gerr = sl_game_start(p.tiles, p.width, p.height);
	sl_free_map_parser(&p);
	if (gerr == SL_GERR_MLX)
		return (ft_fmt_err("MiniLibX Error\n"), 1);
	if (gerr == SL_GERR_IMAGE)
		return (ft_fmt_err("Image Load Error\n"), 1);
	return (0);
}
