/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:27:59 by leblocqu          #+#    #+#             */
/*   Updated: 2019/05/13 15:32:59 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i + 1] != c && s[i + 1] != '\0')
				i++;
			res += 1;
		}
		i++;
	}
	return (res);
}

static char		*create_words(char const *s, char c, int i)
{
	int		len;
	int		j;
	char	*str;

	len = 0;
	j = i;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(str) * len + 1)))
		return (0);
	len = 0;
	while (s[j] != c && s[j] != '\0')
	{
		str[len] = s[j];
		len++;
		j++;
	}
	str[len] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		nb_words;
	int		i;
	int		j;

	nb_words = count_words(s, c);
	j = 0;
	i = 0;
	if (!(res = (char **)malloc(sizeof(res) * (nb_words + 1))) || !s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			res[j] = create_words(s, c, i);
			while (s[i] != c && s[i] != '\0')
				i++;
			j++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}
