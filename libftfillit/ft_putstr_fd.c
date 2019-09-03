/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:47:35 by behaudeg          #+#    #+#             */
/*   Updated: 2019/04/23 12:47:37 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char	*c;
	int		i;

	c = (char *)s;
	i = 0;
	if (c == NULL)
		return ;
	while (c[i] != '\0')
	{
		ft_putchar_fd(c[i], fd);
		i++;
	}
}
