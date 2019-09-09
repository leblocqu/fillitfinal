/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:21:04 by leblocqu          #+#    #+#             */
/*   Updated: 2019/05/09 18:43:00 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	j;

	j = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	while (*s)
	{
		str[j] = (*f)(*s);
		j++;
		s++;
	}
	return (str);
}
