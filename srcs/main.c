/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:20:48 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 19:31:18 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

// Verifies that `s` finishes has extension `.ber`.
static bool	validate_map_path(const char *s)
{
	size_t		len;
	const char	*base_name;

	base_name = ft_str_rfind(s, '/');
	if (!base_name)
		base_name = s;
	else
		base_name++;
	len = ft_str_len(base_name);
	return (
		len > 4
		&& base_name[len - 4] == '.'
		&& base_name[len - 3] == 'b'
		&& base_name[len - 2] == 'e'
		&& base_name[len - 1] == 'r'
	);
}

static void	print_perr(t_perr err, t_map_parser *parser)
{
	if (err == SL_PERR_CANT_READ)
		ft_fmt_err("Read Error\n");
	if (err == SL_PERR_OUT_OF_MEMORY)
		ft_fmt_err("Out Of Memory\n");
	if (err == SL_PERR_INVALID_MAP)
		sl_print_map_error(parser);
}

static void	print_gerr(t_gerr err)
{
	if (err == SL_GERR_MLX)
		ft_fmt_err("MiniLibX Error\n");
	if (err == SL_GERR_IMAGE)
		ft_fmt_err("Unsupported image/X11 server\n");
	if (err == SL_GERR_OOM)
		ft_fmt_err("Out Of Memory\n");
	if (err == SL_GERR_RNG)
		ft_fmt_err("Can't read /dev/urandom\n");
}

int	main(int argc, char **argv)
{
	t_map_parser	p;
	t_perr			perr;
	int				fd;
	t_gerr			gerr;

	if (argc != 2)
		return (ft_fmt_err("Usage: ./so_long <map_file>\n"), 1);
	if (!validate_map_path(argv[1]))
		return (ft_fmt_err("Maps must be .ber files\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_fmt_err("Open Error\n"), 1);
	perr = sl_parse_map(fd, &p);
	close(fd);
	if (perr != SL_PERR_SUCCESS)
		return (print_perr(perr, &p), sl_free_map_parser(&p), 1);
	gerr = sl_game_start(&p.map);
	sl_free_map_parser(&p);
	if (gerr != SL_GERR_SUCCESS)
		return (print_gerr(gerr), 1);
	return (0);
}
