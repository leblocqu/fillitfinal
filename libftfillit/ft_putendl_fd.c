/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:47:53 by behaudeg          #+#    #+#             */
/*   Updated: 2019/04/23 12:47:55 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char n;

	n = '\n';
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, &n, 1);
}
