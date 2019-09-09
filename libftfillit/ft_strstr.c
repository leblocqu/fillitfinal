/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:55:01 by leblocqu          #+#    #+#             */
/*   Updated: 2019/04/26 15:47:58 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	str = 0;
	if (aiguille[i] == '\0')
		return ((char *)meule_de_foin);
	while (meule_de_foin[i] != '\0')
	{
		if (meule_de_foin[i] == aiguille[0])
		{
			str = (char *)meule_de_foin + i;
			j = 0;
			while (meule_de_foin[i + j] == aiguille[j])
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
