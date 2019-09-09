/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:26:55 by leblocqu          #+#    #+#             */
/*   Updated: 2019/04/26 16:00:31 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meule_de_foin, const char *aiguille, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = 0;
	if (aiguille[i] == '\0')
		return ((char *)meule_de_foin);
	while (meule_de_foin[i] != '\0' && i < n)
	{
		if (meule_de_foin[i] == aiguille[0])
		{
			str = (char *)meule_de_foin + i;
			j = 0;
			while (meule_de_foin[i + j] == aiguille[j] && i + j < n)
			{
				if (aiguille[j + 1] == '\0')
					return (str);
				j++;
			}
			str = 0;
		}
		i++;
	}
	return (NULL);
}
