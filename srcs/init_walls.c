/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:26:24 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 15:17:53 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

inline static t_tscheme	*schemes(void)
{
	static t_tscheme	schemes[20] = {
		(t_tscheme){{{2, 1, 2, 0, 0, 0, 2, 1}}},
		(t_tscheme){{{2, 1, 2, 0, 0, 0, 0, 0}}},
		(t_tscheme){{{2, 1, 2, 1, 2, 0, 0, 0}}},
		(t_tscheme){{{0, 0, 2, 1, 2, 0, 0, 0}}},
		(t_tscheme){{{0, 0, 2, 1, 2, 1, 2, 0}}},
		(t_tscheme){{{0, 0, 0, 0, 2, 1, 2, 0}}},
		(t_tscheme){{{2, 0, 0, 0, 2, 1, 2, 1}}},
		(t_tscheme){{{2, 0, 0, 0, 0, 0, 2, 1}}},
		(t_tscheme){{{0, 0, 0, 0, 0, 0, 0, 0}}},
		(t_tscheme){{{2, 1, 2, 0, 2, 1, 2, 1}}},
		(t_tscheme){{{2, 1, 2, 0, 2, 1, 2, 0}}},
		(t_tscheme){{{2, 1, 2, 1, 2, 1, 2, 0}}},
		(t_tscheme){{{2, 1, 2, 1, 2, 0, 2, 1}}},
		(t_tscheme){{{2, 0, 2, 1, 2, 0, 2, 1}}},
		(t_tscheme){{{2, 0, 2, 1, 2, 1, 2, 1}}},
		(t_tscheme){{{0, 0, 0, 0, 1, 0, 0, 0}}},
		(t_tscheme){{{0, 0, 0, 0, 0, 0, 1, 0}}},
		(t_tscheme){{{1, 0, 0, 0, 0, 0, 0, 0}}},
		(t_tscheme){{{0, 0, 1, 0, 0, 0, 0, 0}}},
		(t_tscheme){{{2, 2, 2, 2, 2, 2, 2, 2}}},
	};

	return (schemes);
}

static t_tscheme	compute_schm(t_upos p, t_upos *w, size_t n)
{
	t_tscheme	res;

	res.top_left = sl_upos_array_contains((t_upos){p.x - 1, p.y - 1}, w, n);
	res.top = sl_upos_array_contains((t_upos){p.x, p.y - 1}, w, n);
	res.top_right = sl_upos_array_contains((t_upos){p.x + 1, p.y - 1}, w, n);
	res.right = sl_upos_array_contains((t_upos){p.x + 1, p.y}, w, n);
	res.bot_right = sl_upos_array_contains((t_upos){p.x + 1, p.y + 1}, w, n);
	res.bot = sl_upos_array_contains((t_upos){p.x, p.y + 1}, w, n);
	res.bot_left = sl_upos_array_contains((t_upos){p.x - 1, p.y + 1}, w, n);
	res.left = sl_upos_array_contains((t_upos){p.x - 1, p.y}, w, n);
	return (res);
}

static t_wall_tile	compute_tile(t_upos p, t_upos *walls, size_t n)
{
	size_t		t;
	size_t		i;
	bool		err_found;
	t_tscheme	scheme;

	t = 0;
	while (t < 20)
	{
		scheme = compute_schm(p, walls, n);
		i = 0;
		err_found = false;
		while (i < 8)
		{
			if (schemes()[t].arr[i] != SL_TSREQ_IGNORED
				&& scheme.arr[i] == schemes()[t].arr[i])
			{
				err_found = true;
				break;
			}
			i++;
		}
		if (!err_found)
			return (t);
		t++;
	}
	ft_assert(false, "a tile should've been selected by this point");
	return (SL_WALL_THIN);
}

t_wall	*sl_create_wall_array(t_upos *pos, size_t n)
{
	t_wall	*res;
	size_t	i;

	res = ft_alloc_array(n, sizeof(t_wall));
	if (!res)
		return (NULL);
	sl_upos_array_sort(pos, n);
	i = 0;
	while (i < n)
	{
		res[i].pos.x = (float)pos[i].x;
		res[i].pos.y = (float)pos[i].y;
		res[i].tile = compute_tile(pos[i], pos, n);
		i++;
	}
	return (res);
}
