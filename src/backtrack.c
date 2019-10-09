/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:20:01 by behaudeg          #+#    #+#             */
/*   Updated: 2019/07/12 14:20:03 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetri		*create_letter(t_tetri *t)
{
	int		nb_t;
	char	l;

	nb_t = 0;
	l = 'A' - 1;
	while (nb_t < g_nb_tetris)
	{
		l++;
		t[nb_t].lettre = l;
		nb_t++;
	}
	return (t);
}

char		**delete(t_tetri t, char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == t.lettre)
				map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

t_point		test_pos(t_point point)
{
	if (point.x < g_size)
		point.x++;
	else
	{
		point.x = 0;
		point.y++;
	}
	return (point);
}

int			place(t_tetri *t, t_point point, char **map, int index)
{
	t_point point2;

	point2.x = 0;
	point2.y = 0;
	if (t[index].lettre != 0)
	{
		while (point.x * point.y < g_size * g_size)
		{
			if (try_pos(map, point, t[index], g_size) == 1)
			{
				map = put_tetris(map, point, t, index);
				if (place(t, point2, map, index + 1) == 1)
					return (1);
				map = delete(t[index], map);
			}
			point = test_pos(point);
		}
		point.x = 0;
		point.y = 0;
		return (0);
	}
	return (1);
}

void		solve(t_tetri *t, char **map)
{
	t_point point;
	int		index;

	point.x = 0;
	point.y = 0;
	index = 0;
	map = create_map(map, g_size);
	while (place(t, point, map, index) == 0)
	{
		g_size++;
		point.x = 0;
		point.y = 0;
		free_tab(map, g_size);
		map = create_map(map, g_size);
	}
	affiche_map(map, g_size);
	free_tab(map, g_size + 1);
}
