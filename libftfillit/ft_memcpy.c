/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:14:47 by behaudeg          #+#    #+#             */
/*   Updated: 2019/04/11 15:49:22 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char *)src;
	b = (unsigned char *)dest;
	while (n > 0)
	{
		*b++ = *a++;
		n--;
	}
	return (dest);
}
