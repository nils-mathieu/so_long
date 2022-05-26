/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:00:09 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/26 15:27:02 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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

static void	print_perr(t_perr err, t_map_parser *parser, const char *file)
{
	ft_fmt_err("{s?}: ", file);
	if (err == SL_PERR_CANT_READ)
		ft_fmt_err("An error occured whilst reading the file.\n");
	if (err == SL_PERR_OUT_OF_MEMORY)
		ft_fmt_err("The system is out of memory.\n");
	if (err == SL_PERR_INVALID_MAP)
		sl_print_map_error(parser);
}

static bool	load_map(const char *file, t_map *map)
{
	t_map_parser	p;
	t_perr			perr;
	int				fd;

	ft_dbg("Loading map `{s?}`...\n", file);
	if (!validate_map_path(file))
		return (ft_fmt_err("{s?}: Maps must be .ber files.\n", file), false);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_fmt_err("Cannot open '{s?}' for reading.\n", file), false);
	perr = sl_parse_map(fd, &p, map);
	close(fd);
	if (perr != SL_PERR_SUCCESS)
		return (print_perr(perr, &p, file), sl_free_map_parser(&p), false);
	return (true);
}

t_map	*sl_load_maps(const char *const *files, size_t len)
{
	t_map	*ret;
	size_t	i;

	ret = ft_alloc_array(len, sizeof(t_map));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (!load_map(files[i], &ret[i]))
		{
			while (i--)
			{
				free(ret[i].coins);
				free(ret[i].players);
				free(ret[i].exits);
				free(ret[i].walls);
			}
			return (free(ret), NULL);
		}
		i++;
	}
	return (ret);
}

void	sl_free_maps(t_map *maps, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(maps[i].coins);
		free(maps[i].players);
		free(maps[i].exits);
		free(maps[i].walls);
		i++;
	}
	free(maps);
}
