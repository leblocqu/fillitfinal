/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:23:27 by leblocqu          #+#    #+#             */
/*   Updated: 2019/05/13 15:32:30 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			len_n(long n)
{
	int		taille;

	taille = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		taille++;
	}
	while (n > 0)
	{
		n = n / 10;
		taille++;
	}
	return (taille);
}

char				*ft_itoa(int n)
{
	int		taille;
	char	*str;
	int		compt;
	long	nb;

	compt = 0;
	nb = n;
	taille = len_n(nb);
	if (!(str = (char *)malloc(sizeof(char) * taille + 1)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nb *= -1;
		compt = 1;
	}
	str[taille] = '\0';
	while (taille > compt)
	{
		str[taille - 1] = (nb % 10) + '0';
		taille--;
		nb = nb / 10;
	}
	return (str);
}
