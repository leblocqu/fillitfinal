/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:43:42 by leblocqu          #+#    #+#             */
/*   Updated: 2019/05/09 18:40:59 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	j;
	char	*str;

	j = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	while (*s)
	{
		str[j] = (*f)(j, *s);
		j++;
		s++;
	}
	return (str);
}
