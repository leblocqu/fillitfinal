/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:55:37 by behaudeg          #+#    #+#             */
/*   Updated: 2019/04/11 13:15:19 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *cpy;

	cpy = (char *)b;
	while (len > 0)
	{
		*cpy++ = (unsigned char)c;
		len--;
	}
	return (b);
}
