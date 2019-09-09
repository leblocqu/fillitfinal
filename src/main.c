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

char				**fill_tab(char **tab, char *buf)
{
	int			i;
	int			j;
	int			k;

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

int					get_map_size(void)
{
	int			square_size;
	float		float_nb;

	float_nb = ft_sqrt((float)(g_nb_tetris) * 4.0);
	square_size = (int)float_nb;
	if (square_size == float_nb)
		return (square_size);
	return (square_size);
}

void				free_tab(char **tab, int tab_size)
{
	int			i;

	i = 0;
	while (i < tab_size)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_strdel(tab);
}

int					main(int argc, char **argv)
{
	char		**str;
	t_tetri		*tetriminios;

	str = NULL;
	tetriminios = NULL;
	if (argc != 2)
	{
		ft_putendl("error");
		return (-1);
	}
	if ((str = init_checker(argv[1])) == NULL)
	{
		ft_putendl("error");
		free_tab(str, g_nb_tetris);
		return (-1);
	}
	tetriminios = create_tetris(tetriminios, str);
	free_tab(str, g_nb_tetris);
	tetriminios = create_coord(tetriminios);
	tetriminios = create_letter(tetriminios);
	solve(tetriminios, NULL);
	return (0);
}
