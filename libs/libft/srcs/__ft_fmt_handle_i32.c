/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_fmt_handle_i32.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:25:39 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 16:44:45 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__libft_internal.h"
#include "libft.h"

bool	__ft_fmt_handle_i32(t_writer w, va_list args)
{
	char	buf[11];
	char	*start;
	bool	neg;
	int32_t	i;

	i = va_arg(args, uint32_t);
	if (i == INT_MIN)
		return (w.write(w.self, "-2147483648", 11));
	neg = false;
	if (i < 0)
	{
		i = -i;
		neg = true;
	}
	start = ft_uint32_to_str(i, (t_str){"0123456789", 10}, buf + 11);
	if (neg)
		*(--start) = '-';
	return (w.write(w.self, start, 11 - (start - buf)));
}
