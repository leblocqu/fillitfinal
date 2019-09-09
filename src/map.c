/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:19:31 by behaudeg          #+#    #+#             */
/*   Updated: 2019/07/12 14:19:33 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**create_map(char **map, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = ft_memalloc((sizeof(char *)) * (size + 1));
	while (i < size)
	{
		map[i] = ft_memalloc((sizeof(char)) * (size + 1));
		i++;
	}
	i = 0;
	while (j < size)
	{
		while (i < size)
			map[j][i++] = '.';
		map[j][i] = '\0';
		i = 0;
		j++;
	}
	map[j] = NULL;
	return (map);
}

int			try_pos(char **map, t_point point, t_tetri t, int size)
{
	int i;
	int dx;
	int dy;

	i = 0;
	dx = point.x - t.coord[0].x;
	dy = point.y - t.coord[0].y;
	while (i < 4)
	{
		if ((t.coord[i].y) + dy >= size || (t.coord[i].x) + dx >= size)
			return (0);
		if (map[(t.coord[i].y) + dy][(t.coord[i].x) + dx] != '.')
			return (0);
		i++;
	}
	return (1);
}

char		**put_tetris(char **map, t_point point, t_tetri *t, int nb)
{
	int i;
	int dx;
	int dy;

	i = 0;
	dx = point.x - t[nb].coord[0].x;
	dy = point.y - t[nb].coord[0].y;
	while (i < 4)
	{
		map[(t[nb].coord[i].y) + dy][(t[nb].coord[i].x) + dx] = t[nb].lettre;
		i++;
	}
	return (map);
}

void		affiche_map(char **map, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
