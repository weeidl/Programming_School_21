/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewayn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 05:01:42 by ewayn             #+#    #+#             */
/*   Updated: 2021/02/24 05:01:45 by ewayn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_gridinfo {
	int		height;
	int		width;
	char	empty;
	char	obstacle;
	char	sqrchr;
	char	**map;
	int		x_bsq;
	int		y_bsq;
}				t_gridinfo;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
void			error(char *err);
int				ft_atoi(char *str);

char			**check_map(char **map, int height);

char			**get_lines_from_grid(char *path_to_dict);
int				get_number_of_lines(char **lines);
char			*ft_file_missing(void);

void			do_square(t_gridinfo mygrid);

char			**ft_split(char *str, char *charset);

#endif
