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

char		**init_checker(char *argv, char **str)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	ret = 1;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		buf[ret] = '\0';
	g_nb_tetris = count_tetris(buf);
	g_size = get_map_size();
	if (g_nb_tetris > 26)
		return (NULL);
	if (!(str = ft_memalloc(sizeof(char *) * (g_nb_tetris + 1))))
		return (NULL);
	if (test_init(buf) == 0)
		return (NULL);
	str = fill_tab(str, buf);
	if (checker(str) == 0)
		return (NULL);
	close(fd);
	return (str);
}

int			test_init(char *buf)
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
	if (buf[x - 1] == '.' || buf[x - 1] == '#')
		return (0);
	return (1);
}
