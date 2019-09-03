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

char	**fill_tab(char **tab, char *buf)
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
	tab[j] = NULL;
	return (tab);
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

int		main(int argc, char **argv)
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
		return (-1);
	}
	else
		printf("that's good !\n");
	tetriminios = create_tetris(tetriminios, str);
	tetriminios = create_coord(tetriminios);
	tetriminios = create_letter(tetriminios);
	solve(tetriminios, 2, NULL);
	return (0);
}
