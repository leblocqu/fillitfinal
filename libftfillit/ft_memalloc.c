/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:33:26 by behaudeg          #+#    #+#             */
/*   Updated: 2019/04/12 11:33:43 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*buf;

	buf = NULL;
	if (!(buf = (void *)malloc(size)))
		return (NULL);
	ft_memset(buf, 0, size);
	return (buf);
}
