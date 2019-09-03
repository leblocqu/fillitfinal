/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:22:51 by behaudeg          #+#    #+#             */
/*   Updated: 2019/04/25 17:22:52 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_c(const char *str, int i, char c)
{
	if (str[i] == c || str[i] == '\0')
		return (1);
	else
		return (0);
}

static int		count_words(const char *str, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (str[i] && is_c(str, i, c) == 0)
		len++;
	while (str[i + 1])
	{
		if (str[i + 1] && is_c(str, i, c) == 1
			&& is_c(str, i + 1, c) == 0)
			len++;
		i++;
	}
	return (len + 1);
}

static char		*ft_strdupp(const char *src, int j, char c)
{
	char	*dup;
	int		len;
	int		i;
	int		k;

	k = 0;
	len = 0;
	i = 0;
	while (src[len + j] && !(is_c(src, len + j, c)))
		len++;
	if (!(dup = (char *)malloc(sizeof(dup) * (len + 1))))
		return (NULL);
	while (src[i + j] && !(is_c(src, i + j, c)))
	{
		dup[k] = src[i + j];
		i++;
		k++;
	}
	dup[k] = '\0';
	return (dup);
}


char			**ft_strsplit(const char *s, char c)
{
	char	**res;
	int		k;
	int		i;
	int		j;

	i = -1;
	k = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char*) * (count_words(s, c)))))
		return (NULL);
	while (s[++i] != '\0')
	{
		if (s[0] && !(is_c(s, i, c)) && i == 0 && j == 0)
			res[k++] = ft_strdupp(s, j, c);
		if ((s[i] && is_c(s, i, c) && (!(is_c(s, i + 1, c)))))
		{
			j = i + 1;
			res[k] = ft_strdupp(s, j, c);
			k++;
		}
	}
	res[k] = 0;
	return (res);
}
