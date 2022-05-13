/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_fmt_handle_u32.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:30:43 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/14 00:01:53 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__libft_fmt.h"
#include "libft.h"

bool	__ft_fmt_handle_u32(t_writer w, va_list args)
{
	char	buf[10];
	char	*start;

	start = ft_uint32_to_str(
			va_arg(args, uint32_t),
			(t_str){"0123456789", 10}, buf + 10);
	return (w.write(w.self, start, 10 - (start - buf)));
}
