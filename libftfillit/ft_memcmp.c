/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:38:11 by leblocqu          #+#    #+#             */
/*   Updated: 2019/04/22 14:44:18 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str;
	unsigned char *str2;

	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n)
	{
		if (*str != *str2)
			return (*str - *str2);
		str++;
		str2++;
		n--;
	}
	return (0);
}
