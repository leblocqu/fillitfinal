/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:54:54 by leblocqu          #+#    #+#             */
/*   Updated: 2019/04/11 15:14:52 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (*s == c)
			return ((char *)s);
		s++;
		len--;
	}
	return (NULL);
}
