/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:07:42 by behaudeg          #+#    #+#             */
/*   Updated: 2019/04/16 10:07:44 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (!s)
		return (NULL);
	if (!(res = ft_memalloc(len + 1)))
		return (NULL);
	while (i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
