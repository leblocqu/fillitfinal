/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:07:02 by behaudeg          #+#    #+#             */
/*   Updated: 2019/04/12 14:07:05 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*fresh;

	i = 0;
	if (!(fresh = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		fresh[i] = '\0';
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
