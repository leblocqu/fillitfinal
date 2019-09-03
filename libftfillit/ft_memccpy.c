/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:02:43 by behaudeg          #+#    #+#             */
/*   Updated: 2019/04/11 16:18:32 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)src;
	b = (unsigned char *)dest;
	while (i < n)
	{
		b[i] = a[i];
		if (a[i] == (unsigned char)c)
			return ((void *)&dest[i + 1]);
		i++;
	}
	return (NULL);
}
