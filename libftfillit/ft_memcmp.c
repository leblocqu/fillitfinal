/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:51:12 by behaudeg          #+#    #+#             */
/*   Updated: 2019/04/12 10:51:14 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (n > 0)
	{
		if (*a != *b)
		{
			return (*a - *b);
		}
		a++;
		b++;
		n--;
	}
	return (0);
}
