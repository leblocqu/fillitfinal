/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:30:07 by leblocqu          #+#    #+#             */
/*   Updated: 2019/09/03 14:30:09 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int racine;
	int sqrt;

	racine = 1;
	sqrt = 0;
	while (racine <= nb / 2)
	{
		sqrt = racine * racine;
		if (sqrt == nb)
		{
			return (racine);
		}
		racine = racine + 1;
	}
	return (0);
}