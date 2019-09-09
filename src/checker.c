/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:02:08 by behaudeg          #+#    #+#             */
/*   Updated: 2019/07/12 13:02:09 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_shape(char *str)
{
	int i;
	int link;

	link = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			if (((i + 1) < 19) && str[i + 1] == '#')
				link++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				link++;
			if (((i + 5) < 19) && str[i + 5] == '#')
				link++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				link++;
		}
		i++;
	}
	if (link != 6 && link != 8)
		return (0);
	return (1);
}

int		check_line(char *s)
{
	int x;
	int y;
	int add_5;

	x = 0;
	y = 0;
	add_5 = 4;
	while (s[x] != '\0')
	{
		if (s[x] == '.' || s[x] == '#')
			y++;
		if (y > 4)
			return (0);
		if (s[x] == '\n' && x == add_5)
		{
			y = 0;
			add_5 += 5;
		}
		x++;
	}
	return (1);
}

int		check_char(char *s)
{
	int i;
	int hash;
	int point;
	int endline;

	i = 0;
	hash = 0;
	point = 0;
	endline = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			hash++;
		if (s[i] == '.')
			point++;
		if (s[i] == '\n')
			endline++;
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		i++;
	}
	if (hash != 4 || point != 12 || endline != 4)
		return (0);
	return (1);
}

int		checker(char **tab)
{
	int i;

	i = 0;
	if (tab[0] == NULL)
		return (0);
	while (i < g_nb_tetris)
	{
		if (check_char(tab[i]) != 1)
			return (0);
		if (check_line(tab[i]) != 1)
			return (0);
		if (check_shape(tab[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
