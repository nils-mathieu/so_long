/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_INT.gen                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:34:52 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 22:12:06 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_str_to_ushort(const char *s, unsigned short *result)
{
	if (*s < '0' || '9' < *s)
		return (NULL);
	*result = 0;
	while ('0' <= *s && *s <= '9')
	{
		if (*result > USHRT_MAX / 10 - (*s - '0'))
			return (NULL);
		*result = *result * 10 + (*s - '0');
		s++;
	}
	return (s);
}

const char	*ft_str_to_short(const char *s, short *result)
{
	bool		neg;
	const char	*ret;

	neg = false;
	if (*s == '-')
		neg = (s++, true);
	else if (*s == '+')
		s++;
	ret = ft_str_to_ushort(s, (unsigned short *)result);
	if (!ret || *(unsigned short *)result > (unsigned short)SHRT_MIN)
		return (NULL);
	if (neg)
		*result = -*result;
	return (ret);
}
