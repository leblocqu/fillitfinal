/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:46:21 by behaudeg          #+#    #+#             */
/*   Updated: 2019/04/08 17:46:48 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	while (dest[x] != '\0' && x < n)
		x++;
	while (src[y] != '\0' && (x + y + 1) < n)
	{
		dest[x + y] = src[y];
		y++;
	}
	if (x != n)
		dest[x + y] = '\0';
	while (src[y] != '\0')
		y++;
	return (x + y);
}
