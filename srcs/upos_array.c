/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upos_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:50:41 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/19 18:30:06 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

inline static uint64_t	key(t_upos pos)
{
	return ((uint64_t)pos.x << 32 | (uint64_t)pos.y);
}

static void	swap(t_upos *a, t_upos *b)
{
	t_upos	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	sl_upos_array_sort(t_upos *arr, size_t n)
{
	size_t	l;
	size_t	r;

	if (n <= 1)
		return ;
	l = 0;
	r = n - 1;
	while (l < r)
	{
		if (key(arr[l]) < key(arr[l + 1]))
		{
			swap(&arr[l + 1], &arr[r]);
			r--;
		}
		else
		{
			swap(&arr[l + 1], &arr[l]);
			l++;
		}
	}
	sl_upos_array_sort(arr, l);
	sl_upos_array_sort(arr + l + 1, n - l - 1);
}

bool	sl_upos_array_contains(t_upos pos, t_upos *arr, size_t n)
{
	size_t		min;
	size_t		max;
	size_t		mid;
	uint64_t	k;
	uint64_t	t;

	if (n == 0)
		return (false);
	k = key(pos);
	min = 0;
	max = n - 1;
	while (min <= max)
	{
		mid = (min + max) / 2;
		t = key(arr[mid]);
		if (t == k)
			return (true);
		else if (k < t)
			max = mid - 1;
		else
			min = mid + 1;
	}
	return (false);
}
