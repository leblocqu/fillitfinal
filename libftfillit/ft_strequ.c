/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:01:17 by leblocqu          #+#    #+#             */
/*   Updated: 2019/05/09 18:22:03 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t i;
	size_t j;
	size_t k;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	if (i != j)
		return (0);
	while (k < i)
	{
		if (s1[k] != s2[k])
			return (0);
		k++;
	}
	return (1);
}
