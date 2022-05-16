/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_fmt_handle_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:14:29 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 18:21:08 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "__libft_internal.h"

bool	__ft_fmt_handle_int(t_writer w, va_list args)
{
	char	buf[11];
	char	*start;
	bool	neg;
	int		i;

	i = va_arg(args, int);
	if (i == INT_MIN)
		return (w.write(w.self, "-2147483648", 11));
	neg = false;
	if (i < 0)
	{
		i = -i;
		neg = true;
	}
	start = ft_uint_to_str(i, (t_str){"0123456789", 10}, buf + 11);
	if (neg)
		*(--start) = '-';
	return (w.write(w.self, start, 11 - (start - buf)));
}
