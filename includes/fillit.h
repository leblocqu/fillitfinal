/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:50:03 by behaudeg          #+#    #+#             */
/*   Updated: 2019/06/25 14:50:06 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

int g_nb_tetris;
int g_size;
# define BUFF_SIZE 4096

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_tetri
{
	char		lettre;
	char		tetri[5][5];
	t_point		coord[4];
}				t_tetri;

char			**create_map(char **map, int size);
int				try_pos(char **map, t_point point, t_tetri t, int size);
char			**put_tetris(char **map, t_point point, t_tetri *t, int nb);
void			affiche_map(char **map, int size);
char			**init_checker(char *argv, char **str);
int				line_checker(char *str);
int				check_char(char *str);
int				check_shape(char *str);
int				checker(char **tab);
int				count_tetris(char *str);
t_tetri			*create_tetris(t_tetri *t, char **str);
t_tetri			*create_coordd(t_tetri *test, int j, int k);
t_tetri			*create_coord(t_tetri *test);
t_tetri			*create_letter(t_tetri *tetri);
void			free_split(char **str_split);
void			solve(t_tetri *t, char **map);
char			**fill_tab(char **tab, char *buf);
int				test_init(char *buf);
void			free_tab(char **tab, int tab_size);
int				get_map_size(void);

#endif
