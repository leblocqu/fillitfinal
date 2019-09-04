/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 11:01:48 by behaudeg          #+#    #+#             */
/*   Updated: 2019/06/28 11:05:56 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char					**fill_tab(char **tab, char *buf)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < count_tetris(buf))
	{
		tab[j] = (char*)malloc(sizeof(char) * 20 + 1);
		if (tab[j] == NULL)
			return (NULL);
		while (k < 20)
		{
			tab[j][k] = buf[i];
			k++;
			i++;
		}
		tab[j][20] = '\0';
		k = 0;
		j++;
		i++;
	}
	return (tab);
}

static float		ft_sqrt(float nb)
{
	float	x;

	x = 0;
	while (x * x < nb)
		x++;
	return (x);
}

static int			get_map_size(void)
{
	int		square_size;
	float	float_nb;

	float_nb = ft_sqrt((float)(g_nb_tetris) * 4.0);
	square_size = (int)float_nb;
	if (square_size == float_nb)
		return (square_size);
	return (square_size);
}

void		free_tab(char **tab, int tab_size)
{
	int i;

	i = 0;
	while (i < tab_size)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_strdel(tab);
}

void        aff(t_tetri *test, int c_tetris)
{
    int i;
    int x;
    int y;
    i = 0;
    x = 0;
    y = 0;
    while (c_tetris >= 1)
    {
        while (x < 4)
        {
            while (y < 4)
            {
                printf("%c", test->tetri[x][y]);
                y++;
            }
            x++;
            y = 0;
            printf("\n");
        }
        c_tetris--;
        test++;
        x = 0;
        printf("\n\n");
    }
}

void	affiche_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		while (tab[i][j] != '\0')
		{
			printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

int					main(int argc, char **argv)
{
	int			size;
	char		**str;
	t_tetri		*tetriminios;
	char		**map;

	str = NULL;
	tetriminios = NULL;
	size = get_map_size();
	map = NULL;
	if (argc != 2)
	{
		ft_putendl("error");
		return (-1);
	}
	if ((str = init_checker(argv[1])) == NULL)
	{
		ft_putendl("error");
		free_tab(str, g_nb_tetris + 1);
		return (-1);
	}
	tetriminios = create_tetris(tetriminios, str);
	free_tab(str, g_nb_tetris + 1);
	tetriminios = create_coord(tetriminios);
	tetriminios = create_letter(tetriminios);
	solve(tetriminios, size, map);
	return (0);
}
