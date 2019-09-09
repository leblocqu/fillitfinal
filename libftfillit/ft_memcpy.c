/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:07:48 by leblocqu          #+#    #+#             */
/*   Updated: 2019/04/17 13:46:26 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	i = 0;
	str = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (i < n)
	{
		str[i] = str2[i];
		i++;
	}
	dest = (void *)str;
	return (dest);
}
