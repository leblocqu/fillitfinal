/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:40:26 by leblocqu          #+#    #+#             */
/*   Updated: 2019/04/08 13:54:57 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	size_t	i;
	char	*dup;

	length = ft_strlen(s);
	if (!(dup = (char *)malloc(sizeof(*s) * (length + 1))))
		return (0);
	i = 0;
	while (i < length)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
