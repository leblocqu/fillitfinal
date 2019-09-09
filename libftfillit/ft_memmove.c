/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:05:27 by leblocqu          #+#    #+#             */
/*   Updated: 2019/05/13 15:20:02 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*srcc;
	char	*dstc;
	size_t	i;

	i = -1;
	srcc = (char *)src;
	dstc = (char *)dest;
	if (srcc < dstc)
	{
		while ((int)(--n) >= 0)
			*(dstc + n) = *(srcc + n);
	}
	else
	{
		while (++i < n)
			*(dstc + i) = *(srcc + i);
	}
	return (dest);
}
