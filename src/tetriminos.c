/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 12:27:31 by behaudeg          #+#    #+#             */
/*   Updated: 2019/06/28 12:27:33 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			count_tetris(char *s)
{
	int i;
	int nb_tetri;

	i = 0;
	nb_tetri = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == '\0'))
			nb_tetri++;
		i++;
	}
	return (nb_tetri);
}

t_tetri		*create_tetris(t_tetri *tetris, char **str)
{
	int		index;
	int 	i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	index = 0;
	tetris = ft_memalloc(sizeof(t_tetri) * (g_nb_tetris + 1));
	while (index < g_nb_tetris)
	{
		while (str[index][l] != '\0')
		{
			while (str[index][l] != '\n')
			{
				tetris[index].tetri[i][j] = str[index][l];
				j++;
				l++;
			}
			tetris[index].tetri[i][j] = '\0';
			j = 0;
			i++;
			l++;
		}
		index++;
		l = 0;
		i = 0;
		j = 0;
	}
	return (tetris);
} 

t_tetri        *create_coordd(t_tetri *test, int j, int k)
{
    int index;
    int i;

    i = -1;
    index = -1;
    while (++index < g_nb_tetris)
    {
        while (++i < 4)
        {
            while (++j < 4)
            {
                if (test[index].tetri[i][j] == '#')
                {
                    test[index].coord[k].x = j;
                    test[index].coord[k].y = i;
                    k++;
                }
            }
            j = -1;
        }
        i = -1;
        k = 0;
    }
    return (test);
}

t_tetri        *create_coord(t_tetri *test)
{
    int    j;
    int k;

    j = -1;
    k = 0;
    test = create_coordd(test,j, k);
    return (test);
}
