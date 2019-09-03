/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:29:39 by behaudeg          #+#    #+#             */
/*   Updated: 2019/04/10 16:32:40 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	int		j;
	char	*pt;

	i = 0;
	pt = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < len)
	{
		if (s1[i] == s2[0])
		{
			pt = (char *)s1 + i;
			j = 0;
			while (s1[i + j] == s2[j] && i + j < len)
			{
				if (s2[j + 1] == '\0')
					return (pt);
				j++;
			}
			pt = 0;
		}
		i++;
	}
	return (NULL);
}
