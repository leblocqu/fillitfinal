/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:00:25 by behaudeg          #+#    #+#             */
/*   Updated: 2019/04/10 11:14:00 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = ft_strlen(src);
	if (!(dup = (char *)malloc(sizeof(dup) * (j + 1))))
		return (NULL);
	while (src[i])
	{
		dup[k] = src[i];
		i++;
		k++;
	}
	dup[k] = '\0';
	return (dup);
}
