/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_starts_with.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:26:37 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 19:50:36 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_str_starts_with(const char *s, const char *needle)
{
	while (*needle)
	{
		if (*needle != *s)
			return (false);
		needle++;
		s++;
	}
	return (true);
}
