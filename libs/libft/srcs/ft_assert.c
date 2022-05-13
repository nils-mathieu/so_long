/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:28:35 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 10:47:45 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

#ifdef DEBUG

void	ft_assert(bool condition, const char *msg)
{
	if (condition)
		return ;
	ft_write_all(STDERR_FILENO, msg, ft_str_len(msg));
	ft_write_all(STDERR_FILENO, "\n", 1);
	abort();
}

#else

void	ft_assert(bool condition, const char *msg)
{
	(void)condition;
	(void)msg;
}

#endif
