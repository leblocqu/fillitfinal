/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:46:48 by leblocqu          #+#    #+#             */
/*   Updated: 2019/05/09 19:06:29 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *src;

	src = NULL;
	if (size)
	{
		if (!(src = malloc(size)))
			return (NULL);
		return (ft_memset(src, 0, size));
	}
	return (NULL);
}
