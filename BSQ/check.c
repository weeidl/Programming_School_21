/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeabuck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 04:25:55 by fmeabuck          #+#    #+#             */
/*   Updated: 2021/02/24 04:25:57 by fmeabuck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	**check_map(char **map, int height)
{
	if (!(check_first_2_lines(map)))
    {
        return (NULL);
    }
	if (!(check_nb_lines(map, height)))
    {
        return (NULL);
    }
	if (!(check_line_length_consistency(map)))
    {
        return (NULL);
    }
	if (!(check_charset_consistency(map)))
    {
        return (NULL);
    }
	return (map);
}

int		check_first_2_lines(char **map)
{
	char	*ptr;
	int		i;

	charptr = map[0];
	while (*charptr != 0)
		charptr++;
	if (ft_strlen(map[0]) > 3 && *(ptr - 1) >= ' ' && *(ptr - 2) >= ' ' 
    && *(ptr - 3) >= ' ' && *(ptr - 1) != *(ptr - 2) 
    && *(ptr - 1) != *(ptr - 3) && *(ptr - 2) != *(ptr - 3))
	{
		i = 0;
		while (i < ((ptr - 3) - map[0]))
		{
			if (map[0][i] < '0' || map[0][i] > '9')
            {
				return (0);
            }
			i++;
		}
		if (!map[1] || (map[1][0] != *(ptr - 2)
			&& map[1][0] != *(ptr - 3)))
			return (0);
		return (1);
	}
	else
		return (0);
}

int		check_nb_lines(char **map, int height)
{
	char	*nblines;
	int		nblinesint;
	int		i;

	nblines = malloc(ft_strlen(map[0]) - 3);
	i = 0;
	while (i < ft_strlen(map[0]) - 3)
	{
		nblines[i] = map[0][i];
		i++;
	}
	nblines[i] = 0;
	nblinesint = ft_atoi(nblines);
	free(nblines);
	if (nblinesint == height - 1)
		return (1);
	return (0);
}



int		check_charset_consistency(char **map)
{
	char	*charptr;
	int		j;
	int		i;
	char	empty;
	char	obstacle;

	ptr = map[0];
	while (*ptr != 0)
		ptr++;
	empty = *(ptr - 3);
	obstacle = *(ptr - 2);
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != 0)
		{
			if (map[i][j] != empty && map[i][j] != obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}