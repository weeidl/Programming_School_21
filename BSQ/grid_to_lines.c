/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_to_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeabuck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 04:30:19 by fmeabuck          #+#    #+#             */
/*   Updated: 2021/02/24 04:30:21 by fmeabuck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

char			*ft_file_missing(void)
{
	char	buf;
	int		file;

	if ((file = open("tempgrid", O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
		return (NULL);
	while (read(STDIN_FILENO, &buf, 1))
	{
		write(file, &buf, 1);
	}
	close(file);
	return ("tempgrid");
}

char			*filetostr(char *path)
{
	int				grig;
	unsigned int	nbchars;
	char			currchar;
	char			*filestr;
	int				i;

	if ((grid = open(path, O_RDONLY)) < 0)
		return (NULL);
	nbchars = 0;
	while (read(grid, &currchar, 1))
		nbchars++;
	if (!(filestr = malloc(sizeof(char) * (nbchars + 1))))
		return (NULL);
	close(grid);
	grid = open(path, O_RDONLY);
	i = 0;
	while (read(grid, filestr + i, 1))
		i++;
	close(grid);
	filestr[nbchars] = '\0';
	return (filestr);
}

char			**get_lines_from_grid(char *path_to_dict)
{
	char **lines;
	char *filestr;

	if (!(filestr = filetostr(path_to_dict)))
		return (NULL);
	lines = ft_split(filestr, "\n");
	free(filestr);
	return (lines);
}

int				get_number_of_lines(char **lines)
{
	int i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}
