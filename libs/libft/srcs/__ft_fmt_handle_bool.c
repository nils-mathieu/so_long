/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_fmt_handle_bool.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:25:20 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/16 19:11:39 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "__libft_internal.h"

bool	__ft_fmt_handle_bool(t_writer w, va_list args)
{
	bool	b;

	b = (bool)va_arg(args, int);
	if (b)
		return (w.write(w.self, "true", 4));
	else
		return (w.write(w.self, "false", 5));
}
