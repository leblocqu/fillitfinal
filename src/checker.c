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
	if (!(tmp = (char**)malloc(sizeof(char *) * g_nb_tetris + 1)))
		return (NULL);
	if (first_test(buf) == 0)
		return (NULL);
	tmp = fill_tab(tmp, buf);
	if (checker(tmp) == 0)
		return (NULL);
	return (tmp);
}

int				first_test(char *buf)
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

// int		line_checker(char *str)
// {
// 	int i;
// 	int n;

// 	n = 1;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\n')
// 			n++;
// 		if (n % 5 == 0 && str[i] != '\n')
// 			return (0);
// 		i++;
// 	}
// 	return (n % 5 != 0) ? 0 : 1;
// }

// int		check_char(char *str)
// {
// 	char	**ret;
// 	int		lines;
// 	int		col;
// 	int		c;

// 	ret = NULL;
// 	if (!(ret = ft_strsplit(str, '\n')))
// 		return (0);
// 	lines = 0;
// 	col = 0;
// 	c = 0;
// 	while (ret[lines] != NULL)
// 	{
// 		while (ret[lines][col] != '\0')
// 		{
// 			if (ret[lines][col] != '#' && ret[lines][col] != '.')
// 				return (0);
// 			col++;
// 		}
// 		if (col != 4)
// 			return (0);
// 		col = 0;
// 		lines++;
// 	}
// 	return (1);
// }

// int		check_char2(char *s)
// {
// 	int i;
// 	int hash;
// 	int point;
// 	int endline;

// 	i = 0;
// 	hash = 0;
// 	point = 0;
// 	endline = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == '#') 
// 			hash++;
// 		if (s[i] == '.')
// 			point++;
// 		if (s[i] == '\n')
// 			endline++;
// 		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
// 			return (0);
// 		i++;
// 	}
// 	// printf("points = %d\n", point);
// 	// printf("hash = %d\n", hash);
// 	// printf("endline = %d\n", endline);
// 	endline++;
// 	if (hash % 4 != 0 || point % 12 != 0 || endline % 4 != 0)
// 		return (0);
// 	return (1);
// }

// int		check_char3(char *str, int i, int hash, int points)
// {
// 	int n;
// 	// char c;

// 	n = 1;
// 	while (str[++i])
// 	{
// 		while (n % 5 != 0)
// 		{
// 			// printf("val de i = %d\n", i);
// 			if (str[i] == '.')
// 				points++;
// 			if (str[i] == '\n')
// 				n++;
// 			if (str[i] == '#')
// 				hash++;
// 			// if (str[i] != '.' && str[i] != '\n' && str[i] != '#')
// 			// 	c = str[i];
// 			// printf ("c = %c\n", c);
// 			i++;
// 		}
// 		printf("points = %d\n", points);
// 		printf("hash = %d\n", hash);
// 		printf("n= %d\n", n);
// 		if (points != 12 || hash != 4 || n % 5 != 0)
// 			return (0);
// 		points = 0;
// 		hash = 0;
// 		n++;
// 	}
// 	return (1);
// }
