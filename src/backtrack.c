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

static char		**delete(t_tetri t, char **map)
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

int		place(t_tetri *t, t_point point, int size, char **map, int index)
{
	t_point point2;

	point2.x = 0;
	point2.y = 0;
	if (t[index].lettre != 0)
	{
		while (point.x * point.y < size * size)
		{
			if (try_pos(map, point, t[index], size) == 1)
			{
				map = put_tetriminos(map, point, t, index);
				// affiche_map(map, size);
				// usleep(1);
				// printf("\n");
				if (place(t, point2, size, map, index + 1) == 1)
					return (1);
				map = delete(t[index], map);
				// affiche_map(map, size);
				// usleep(1);
				// printf("\n");
			}
			if (point.x < size)
				point.x++;
			else
			{
				point.x = 0;
				point.y++;
			}
		}
		point.x = 0;
		point.y = 0;
		return (0);
	}
	return (1);
}


void		solve(t_tetri *t, int size, char **map)
{
	t_point point;
	int		index;

	point.x = 0;
	point.y = 0;
	index = 0;
	map = create_map(size);
	while (place(t, point, size, map, index) == 0)
	{
		size++;
		point.x = 0;
		point.y = 0;
		map = create_map(size);
	}
	affiche_map(map, size);
}
