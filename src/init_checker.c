/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:26:16 by behaudeg          #+#    #+#             */
/*   Updated: 2019/06/20 14:26:19 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char			**init_checker(char *argv)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	**tmp;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	ret = 1;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		buf[ret] = '\0';
	g_nb_tetris = count_tetris(buf);
	if (g_nb_tetris > 26)
		return (NULL);
	if (!(tmp = (char**)malloc(sizeof(char *) * (g_nb_tetris + 1))))
		return (NULL);
	if (test_init(buf) == 0)
		return (NULL);
	tmp = fill_tab(tmp, buf);
	if (checker(tmp) == 0)
		return (NULL);
	return (tmp);
}

int		test_init(char *buf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (buf[x] != '\0')
	{
		if (buf[x] == '\n')
			y++;
		if (y == 4)
		{
			if (buf[x + 1] != '\n' && buf[x + 1] != '\0')
				return (0);
			if (buf[x + 1] == '\n')
				x++;
			y = 0;
		}
		x++;
	}
	return (1);
}
