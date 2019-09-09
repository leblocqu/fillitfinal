/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:22:37 by leblocqu          #+#    #+#             */
/*   Updated: 2019/04/26 15:58:32 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	str = (unsigned char *)src;
	str2 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		str2[i] = str[i];
		if (str[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
